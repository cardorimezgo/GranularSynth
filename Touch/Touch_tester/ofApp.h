#pragma once

#include "ofMain.h"
#include "ofxRPiTouch.h"
#include "ofxOsc.h"

//send host (ip address)
#define HOST "localhost"

//send port
#define PORT 57120

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
		
		ofxRPiTouch touchHandler;
		ofxOscSender sender;

		vector<ofPoint> fingersPos; // x, y coords.
		vector<int> slot_; // slot assigned to touch event
		vector<int> trackingID_; // Identification of touch event
		
		
};
