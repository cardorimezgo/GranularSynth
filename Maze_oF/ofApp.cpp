#include "ofApp.h"
#include "Binary_Tree.h"
#include "Prim's.h"


//- Default startup:  RANDOM MAZE!!!----------------------------------------------------------
//- RESET EVERYTHING: GRID, MAZE ALGOS. , WEIGHTS ETC. WHEN CHANGING MAZES 
void ofApp::setup(){
    total_cells = GRID_DIM_X * GRID_DIM_Y;
    ofBackground(0,0,0);

    // Maze algos initialization
    //std::vector<MazeGenerator*> generators;
    //generators.push_back(new BinaryTreeGenerator(maze));
    //generators[0]->Generate();
    
    bt.Generate();
    dfs.Solve();
    
    //bt.Run();
    //DFS.Run();
    //DFS.Reset();

    //dj.Run();

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
    static int stepSize = 22; // Control speed: higher value for faster rendering

    if(currentTime - lastUpdateTime > MILLISECS_PER_FRAME) {
        static int currentIndex = 0;
        
        for (int i = 0; i < stepSize; ++i) {
            if (currentIndex < total_cells) {
                Draw_Buffer.begin();
                render.Draw(currentIndex , maze, dfs.Get_Flat_DS());
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

/* CHOOSE MAZE ALGO////////////////////////////////////////
enum class MazeType {
    BINARY_TREE,
    KRUSKAL,
    PRIMS,
    ALDOUS_BRODER,
    // ... other maze types ...
};

MazeType selectedMaze;

void ofApp::keyPressed(int key) {
    switch (key) {
        case 'b': // Assuming 'b' for binary tree
            selectedMaze = MazeType::BINARY_TREE;
            break;
        case 'k': // Assuming 'k' for Kruskal
            selectedMaze = MazeType::KRUSKAL;
            break;
        // ... other cases for other algorithms ...
    }

    setupMaze(selectedMaze);
}

void ofApp::setupMaze(MazeType type) {
    generators.clear(); // Assuming generators is a class member vector

    switch (type) {
        case MazeType::BINARY_TREE:
            generators.push_back(new BinaryTreeGenerator(maze));
            // ... setup other parts specific to Binary Tree ...
            break;

        case MazeType::KRUSKAL:
            // ... setup for Kruskal ...
            break;

        // ... other cases ...

        default:
            ofLogError() << "Unsupported maze type!";
            return;
    }

    // Common setup code if any, for all algorithms
    // e.g.:
    generators[0]->Generate();
}

if (type == MazeType::PRIMS || type == MazeType::KRUSKAL) {
    // Create Weighted_Grid instance
} else {
    // Create Grid instance
}

*/