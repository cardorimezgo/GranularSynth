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

    // allocating memory for image buffer
    Draw_Buffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    //guarantee that the FBO starts with a clean slate
    Draw_Buffer.begin();
    ofClear(255 , 255 , 255 , 0);
    Draw_Buffer.end();
    // start from frame 0
    anima_frame = 0;

}

//-Model--Controller-----------------------------------------------------------
void ofApp::update(){

    while(anima_frame < GRID_DIM_X * GRID_DIM_Y){
        Draw_Buffer.begin();
        //ofClear(255,255,255,0);
        c_render.Draw_Rects(anima_frame);
        Draw_Buffer.end();
        anima_frame++;
    }
}

//-View-------------------------------------------------------------
void ofApp::draw(){ //IMPLEMENTAR COLOR GRADIENT
                    //check cell color order flood_fill
    Draw_Buffer.draw(0 , 0);
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
