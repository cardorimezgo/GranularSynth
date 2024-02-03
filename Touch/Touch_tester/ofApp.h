#pragma once

#include "ofMain.h"
#include "ofxRPiTouch.h"

class ofApp : public ofBaseApp{

	/// Square Multitouch_Test///////// 
	struct Square {
		ofRectangle rect;
		ofColor color;
		bool isTouched = false;
	};

	vector<Square> squares;
	/////////////////////////////////

	std::unordered_map<int, ofxRPiTouch::TouchPoint_xy> TouchPointsB;
	std::unordered_map<int, ofxRPiTouch::TouchPoint_xy>* writeBuffer = &ofxRPiTouch::TouchPointsA;
	std::unordered_map<int, ofxRPiTouch::TouchPoint_xy>* readBuffer = &TouchPointsB;

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
		
		ofxRPiTouch touch;
		vector<int>fingersFound;
		//vector<ofPoint> linePoints; //drawing Line_Test
		ofPoint fingerPosition; // lag test

};
