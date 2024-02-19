#pragma once

#include "ofMain.h"
#include <linux/input.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>

// SYN
#define EVENT_TYPE_0    EV_SYN

// KEY
#define EVENT_TYPE_1    EV_KEY
#define EVENT_CODE_330  BTN_TOUCH
// Min  0
// Max  1

// TOUCH
#define EVENT_TYPE      EV_ABS  // absolute axis events 
#define EVENT_CODE_0    ABS_X
// Min  0
// Max  800
#define EVENT_CODE_1    ABS_Y
// Min  0
// Max  480
#define EVENT_CODE_47   ABS_MT_SLOT //assigning each touch point to a different "slot"
// Min  0
// Max  9
#define EVENT_CODE_53   ABS_MT_POSITION_X //Center X ellipse position
// Min  0
// Max  800
#define EVENT_CODE_54   ABS_MT_POSITION_Y //Center Y ellipse position
// Min  0
// Max  480
#define EVENT_CODE_57   ABS_MT_TRACKING_ID // Unique ID of initiated contact
// Min  0
// Max  65535

//#define PORTRAIT_MODE
//#define LANDSCAPE_MODE

class ofxRPiTouch : public ofThread {
public:

    struct TouchPoint_xy {
        int x;
        int y;
        int trackingID;
        int slot;
        int posX;
        int posY;
    };

private:

    std::unordered_map<int, TouchPoint_xy> TouchPointsA;
    std::unordered_map<int, TouchPoint_xy> TouchPointsB;
    std::unordered_map<int, TouchPoint_xy>* writeBuffer = &TouchPointsA;
    std::unordered_map<int, TouchPoint_xy>* readBuffer = &TouchPointsB;
    mutable std::mutex bufferMutex;

public:

    struct input_event ev;
    int fd, size;
    char name[256];
    char* device;

    int x, y;
    int button;
    int mtSlot;
    int absMTPosX, absMTPosY;
    int absMTTrackingID;

    int currentSlot;
    //int trackingID;
    //int screenW = 480;
    //int screenH = 800;

//-----------------------------------------------------------------------
    int init(string d) {
        size = sizeof(struct input_event);
        name[0] = 'U';
        name[1] = 'n';
        name[2] = 'k';
        name[3] = 'n';
        name[4] = 'o';
        name[5] = 'w';
        name[6] = 'n';
        device = &d[0];

        if ((fd = open(device, O_RDONLY)) < 0) {
            return 1;
        }
        startThread();

        return 0;
    }
    //-----------------------------------------------------------------------
    string getName() {
        ioctl(fd, EVIOCGNAME(sizeof(name)), name);
        string str(name);
        return str;
    }
    //-----------------------------------------------------------------------
    void exit() {
        stopThread();
    }
    //-----------------------------------------------------------------------
    void threadedFunction() {
        while (isThreadRunning()) {
            const size_t ev_size = sizeof(struct input_event);
            ssize_t size = read(fd, &ev, ev_size);
            if (size < (ssize_t)ev_size) {
                ofLog() << "Error size!\n";
                continue;
            }

            //KEY
            if (ev.type == EV_KEY && ev.code == BTN_TOUCH) {
                button = ev.value; //update button state
                //btn = button;
            }

            //TOUCH
            if (ev.type == EV_ABS) {

                switch (ev.code) {

                case ABS_MT_SLOT:
                {
                    currentSlot = ev.value;
                    TouchPointsA[currentSlot].slot = ev.value;                    
                }break;
                case ABS_MT_TRACKING_ID:
                {
                    TouchPointsA[currentSlot] = TouchPoint_xy();
                    TouchPointsA[currentSlot].trackingID = ev.value;
                }break;
                case ABS_MT_POSITION_X:
                {
                    if (TouchPointsA.find(currentSlot) != TouchPointsA.end()) {
                        TouchPointsA[currentSlot].x = ofMap(ev.value, 0, 1024, 0, 800);
                    }
                }break;
                case ABS_MT_POSITION_Y:
                {
                    if (TouchPointsA.find(currentSlot) != TouchPointsA.end()) {
                        TouchPointsA[currentSlot].y = ofMap(ev.value, 0, 600, 0, 480);
                    }
                }break;

                }
            }
        }
    }

    void swapBuffers() { // updating the value of touch input on shared buffer (readBuffer)
        std::lock_guard<std::mutex> lock(bufferMutex);
        std::swap(writeBuffer, readBuffer);
    }

    template<typename Callback> // Template for calling in main thread
    void withReadBuffer(Callback callback)const {
        std::lock_guard<std::mutex> lock(bufferMutex);
        callback(*readBuffer);
    }
};