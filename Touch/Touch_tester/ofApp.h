#pragma once

#include "ofMain.h"
#include "ofxRPiTouch.h"

// Delta time
const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofFbo Draw_Buffer;
		ofxRPiTouch touchHandler;
		vector<ofPoint> fingersPos;
		vector<int> slot_;
		vector<int> trackingID_;
		
};
