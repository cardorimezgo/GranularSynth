#include "ofApp.h"
#include "ofGraphics.h"

//--------------------------------------------------------------
void ofApp::setup(){
	touchHandler.init("/dev/input/event0");
}

//--------------------------------------------------------------
void ofApp::update(){

	static unsigned long lastUpdateTime = 0;
	unsigned long currentTime = ofGetElapsedTimeMillis();

	if (currentTime - lastUpdateTime > MILLISECS_PER_FRAME) {
		Draw_Buffer.begin();
		
		// clear previous frame's touch position
		fingersPos.clear();

		touchHandler.withReadBuffer([&](const auto& readBuffer) { //capture by REFERENCE 
			for (const auto& pair : readBuffer) {
				auto key = pair.first;
				auto touchPoint = pair.second;
				if (fingersPos.size() < 3) { // Checking through all the keys of the unordered_map (3 fingers max)
					fingersPos.push_back(ofPoint(touchPoint.x, touchPoint.y)); // Getting values of unordered_map
					trackingID_.push_back(touchPoint.trackingID);
					slot_.push_back(touchPoint.slot);
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
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("Testeando el texteador", 40, 20);

	stringstream statusStream;	
	for (size_t i = 0; i < fingersPos.size(); i++) {
		const auto pos = fingersPos[i];
		int slot = (i < slot_.size()) ? slot_[i] : -1; //Ensure that we don't get out of bounds
		int trackingID = (i < trackingID_.size()) ? trackingID_[i] : -1;
		
		ofDrawCircle(pos , 10); //Circle radius 10
		
		statusStream 
			<< "Touch#: "<< i+1 <<endl
			<< "X: " << pos.x << endl
			<< "Y: " << pos.y << endl
			<< "slot: " << slot << endl
			<< "trackingID: " << trackingID << endl
			<< endl;
	}
		ofDrawBitmapString(statusStream.str(), 20, 20);
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
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
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