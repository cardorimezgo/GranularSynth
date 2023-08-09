#include "ofApp.h"
#include "Binary_Tree.h"

//-Default startup:  BinaryTree------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0,0,0);

    // Maze algos initialization
    std::vector<MazeGenerator*> generators;
    generators.push_back(new BinaryTreeGenerator(draw_maze));
    generators[0]->Generate();

    dj.Reset();
    dj.Solve();


    Draw_Buffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    Draw_Buffer.begin();
    ofClear(255 , 255 , 255 , 255);
    c_render.Draw_Rects();
    c_render.Draw_Walls();
    Draw_Buffer.end();

    circleYPos = 0;

}

//-Model--Controller-----------------------------------------------------------
void ofApp::update(){
    //start animating the maze
    circleYPos+=2;
    if(circleYPos > 300) circleYPos = 0;

}

//-View-------------------------------------------------------------
void ofApp::draw(){ //IMPLEMENTAR COLOR GRADIENT
                    //check cell color order flood_fill
    ofClear(255, 255, 255, 255);
    c_render.Anima_Maze(circleYPos);
    //Draw_Buffer.draw(0 , 0);
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
