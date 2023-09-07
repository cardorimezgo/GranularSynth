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
}
//RESET FLOOD_FLAT TO -1 EACH TIME WE RUN AGAIN DFS , SAME FOR OTHER DS 
void ofApp::update(){
    static unsigned long lastUpdateTime = 0;
    unsigned long currentTime = ofGetElapsedTimeMillis();
    static int stepSize = 10; // Control speed here: higher value for faster rendering, lower for slower.

    if(currentTime - lastUpdateTime > MILLISECS_PER_FRAME) {
        static int currentIndex = 0;
        
        for (int i = 0; i < stepSize; ++i) {
            if (currentIndex < total_cells) {
                Draw_Buffer.begin();
                c_render.Draw(currentIndex);
                Draw_Buffer.end();
                currentIndex++;
            }
        }
        
        lastUpdateTime = currentTime;
    }
}

//-View-------------------------------------------------------------
void ofApp::draw(){ 
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
