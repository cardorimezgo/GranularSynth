#include "ofApp.h"
#include "ofGraphics.h"

//--------------------------------------------------------------
void ofApp::setup(){
	touchHandler.init("/dev/input/event0");

	//open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){ //// USE TRACKINGID TO CHECK IF THERE IS TOUCH INPUT TO AVOID CALCULATIONS WITH NO INPUT 
	ofxOscMessage m;
	
	fingersPos.clear();
	trackingID_.clear();
	slot_.clear();

	touchHandler.withReadBuffer([&](const auto& readBuffer) { //capture by REFERENCE 
			
		for (const auto& pair : readBuffer) {
			auto key = pair.first;
			auto touchPoint = pair.second;
			if (fingersPos.size() < 3) { // Checking for number of touch events be 3 or less
				
				fingersPos.push_back(ofPoint(touchPoint.x, touchPoint.y)); // storing x,y position 
				m.setAddress("/fingers/position");
				m.addIntArg(touchPoint.x);
				m.addIntArg(touchPoint.y);
				sender.sendMessage(m,false);

				trackingID_.push_back(touchPoint.trackingID); // store ID#
				m.setAddress("/fingers/trackingID");
				m.addIntArg(touchPoint.trackingID);
				sender.sendMessage(m, false);

				slot_.push_back(touchPoint.slot); //store slot#
				m.setAddress("/fingers/slot");
				m.addIntArg(touchPoint.slot);
				sender.sendMessage(m, false);
			}
		}
	});
	touchHandler.swapBuffers();

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);

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