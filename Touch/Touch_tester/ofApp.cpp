#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	touch.init("/dev/input/event2");
	ofLog() << touch.getName();

	/// Square Multitouch_Test///////////////////////////////////////
	//create a grid of squares
	int gridSize = 4; //4x4 grid size
	float squareSizeX = ofGetWidth() / gridSize;
	float squareSizeY = ofGetHeight() / gridSize;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			Square square;
			square.rect = ofRectangle(j * squareSizeX, i * squareSizeY, squareSizeX, squareSizeY);
			square.color = ofColor(100, 100, 100); //default color
			squares.push_back(square);
		}
	}
	//////////////////////////////////////////////////////////////
}

//--------------------------------------------------------------
void ofApp::update(){

	/// Square Multitouch_Test///////////////////////////////////////
	//reset touch status
	for (auto& square : squares) {
		square.isTouched = false;
	}

	//check which sqaures are being touched
	ofPoint touchPoint(touch.getAbsPos().x, touch.getAbsPos().y);
	for (auto& square : squares) {
		if (square.rect.inside(touchPoint)) {
			square.isTouched = true;
			square.color = ofColor(0, 255, 0);//change color when touched
		}
	}
	///////////////////////////////////////////////////////////////////
}

//--------------------------------------------------------------
void ofApp::draw(){

	////////////////Drawing_Line Test////////////////////////////////
	/*
	if (!linePoints.empty()) {
		ofSetColor(0, 255, 0);
		ofSetLineWidth(2);
		ofNoFill();
		ofBeginShape();
		for (auto& point : linePoints) {
			ofVertex(point.x, point.y);
		}
		ofEndShape(false);
	}
	*/
	/////////////////////////////////////////////////////////////////////

	/// Square Multitouch_Test///////////////////////////////////////
	//draw squares
	for (auto& square : squares) {
		ofSetColor(square.color);
		ofDrawRectangle(square.rect);
	}
	////////////////////////////////////////////////////////////////

		// INPUT iformation ///////////////////////////////////////////////
	stringstream statusStream;
	ofSetColor(255, 255, 255);

	statusStream << "X: " << touch.getCoordTouch().x << endl
		<< "Y: " << touch.getCoordTouch().y << endl
		<< "BTN: " << touch.getButton() << endl
		<< "mtSlot: " << touch.getMTSlot() + 1 << endl
		<< "absPosX: " << touch.getAbsPos().x << endl
		<< "absPosY: " << touch.getAbsPos().y << endl
		<< "AbsTrackingID: " << touch.getAbsTrackingID() << endl
		<< endl;
	ofDrawBitmapString(statusStream.str(), 20, 20);
	///////////////////////////////////////////////////////////////////

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	//linePoints.push_back(ofPoint(x, y));// Draw_Line Test
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	//linePoints.clear(); // Draw_Line Test
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void ofApp::exit() {
	touch.exit();
}