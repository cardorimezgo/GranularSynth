#include "ofApp.h"
#include "Binary_Tree.h"

//-Default startup:  RANDOM MAZE!!!----------------------------------------------------------
void ofApp::setup(){
    total_cells = GRID_DIM_X * GRID_DIM_Y;
    ofBackground(0,0,0);

    // Maze algos initialization
    std::vector<MazeGenerator*> generators;
    generators.push_back(new BinaryTreeGenerator(draw_maze));
    generators[0]->Generate();

    DFS.DFS_Run();
    DFS.Reset();

    // allocating memory for image buffer
    Draw_Buffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    //guarantee that the FBO starts with a clean slate
    //Draw_Buffer.begin();
    //c_render.Draw_Walls();
    //ofClear(255 , 255 , 255 , 0);
    //Draw_Buffer.end();

    // start from frame 0
    anima_frame = 0;
    //timePreviousFrame = 0;    
}

//-Model--Controller-----------------------------------------------------------
void ofApp::update(){

    //Check if we are too fast , and if so, waste some milliseconds 
    //until we reach the MILLISECS_PER_FRAME
    static int timePreviousFrame;
    int timeToWait = MILLISECS_PER_FRAME - (ofGetLastFrameTime() - timePreviousFrame);
    if(timeToWait > 0){
        ofSleepMillis(timeToWait);
    }

    float deltaTime= (ofGetLastFrameTime() - timePreviousFrame) / 1000.0f;
    //if (deltaTime > 0.016){
    //    deltaTime = 0.016;
    //}

    timePreviousFrame = ofGetLastFrameTime();

    if (anima_frame < total_cells){
            
        Draw_Buffer.begin();
        c_render.Draw(anima_frame);
        Draw_Buffer.end();

        anima_frame+= 1;
        

    }
    //draw_maze.Reset(); Reset Maze every time we change of maze algo.
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
