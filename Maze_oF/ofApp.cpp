#include "ofApp.h"
#include "Binary_Tree.h"

//-Default startup:  BinaryTree------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0,0,0);
    std::vector<MazeGenerator*> generators;
    generators.push_back(new BinaryTreeGenerator(draw_maze));
    generators[0]->Generate();

    dj.Reset();
    dj.Solve();

}

//-Model--Controller-----------------------------------------------------------
void ofApp::update(){
}

//-View-------------------------------------------------------------
void ofApp::draw(){
    c_render.Display();
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
