#include "ofApp.h"
#include "ofGraphics.h"

//--------------------------------------------------------------
void ofApp::setup(){
	touchHandler.init("/dev/input/event2");
	ofLog() << touchHandler.getName();

	/*
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
	*/

}

//--------------------------------------------------------------
void ofApp::update(){
	///// Lag_Test
	//update finger position
	//fingerPosition.set(touchHandler.getAbsPos().x, touchHandler.getAbsPos().y);
	///////////////////////////////////////////////////////////

	/*
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
	*/

	static unsigned long lastUpdateTime = 0;
	unsigned long currentTime = ofGetElapsedTimeMillis();

	if (currentTime - lastUpdateTime > MILLISECS_PER_FRAME) {
		Draw_Buffer.begin();
		
		// clear previous frame's touch position
		fingersPos.clear();

		touchHandler.withReadBuffer([&](const auto& readBuffer) { //capture by REFERENCE 
			for (const auto& pair : readbuffer) {
				auto key = pair.first;
				auto touchPoint = pair.second;
				if (fingersPos.size() < 3) { // Checking through all the keys of the unordered_map (3 fingers max)
					fingersPos.push_back(ofPoint(touchPoint.x, touchPoint.y)); // Getting values of unordered_map
				}
			}
		});
		Draw_Buffer.end();
		//Swap the buffers, preparing for the next frame
		touchHandler.swapBuffers();
		lastUpdateTime = currentTime;
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){

	
		ofSetColor(255, 0, 0);
		for (const auto& pos : fingersPos) {
			ofDrawCircle(pos , 10); //Circle radius 10
		}
		

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
	/*
	/// Square Multitouch_Test///////////////////////////////////////
	//draw squares
	for (auto& square : squares) {
		ofSetColor(square.color);
		ofDrawRectangle(square.rect);
	}
	////////////////////////////////////////////////////////////////
	*/

	///// Lag_Test
	//Draw a circle at the finger position
	/*
	ofSetColor(255, 0, 0);
	ofDrawCircle(fingerPosition, 10); //Circle radius 10
	/*
	/////////////////////////////////////
	 
		// INPUT iformation ///////////////////////////////////////////////
	/*
	stringstream statusStream;
	ofSetColor(255, 255, 255);

	statusStream << "X: " << touchHandler.getCoordTouch().x << endl
		<< "Y: " << touchHandler.getCoordTouch().y << endl
		<< "BTN: " << touchHandler.getButton() << endl
		<< "mtSlot: " << touchHandler.getMTSlot() + 1 << endl
		<< "absPosX: " << touchHandler.getAbsPos().x << endl
		<< "absPosY: " << touchHandler.getAbsPos().y << endl
		<< "AbsTrackingID: " << touchHandler.getAbsTrackingID() << endl
		<< endl;
	ofDrawBitmapString(statusStream.str(), 20, 20);
	*/
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
	touchHandler.exit();
}