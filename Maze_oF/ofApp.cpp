#include "ofApp.h"

//- Default startup:  RANDOM MAZE!!!----------------------------------------------------------
//- RESET EVERYTHING: GRID, MAZE ALGOS. , WEIGHTS ETC. WHEN CHANGING MAZES 
void ofApp::setup() {
    total_cells = GRID_DIM_X * GRID_DIM_Y;
    ofBackground(0, 0, 0);

    //Unweighted graph mazes: BinaryTree, Aldous Broder, Hunt and kill etc.
    //bt.Generate(0,0);
    //sw.Generate(GRID_DIM_Y - 1,0);
    //dfs.Solve(GRID_DIM_Y -1,0);
    //dfs.printGridFlat();
    
    ///////////////////////////////////////////////////////////////////////
    //Generate weighted graph
    weight_maze.init_Weights();
    weight_maze.set_Rnd_Edges();
    // Weighted graph mazes: Prim's, Kruskal's
    int rnd_row, rnd_col;
    prim.Gen_Rnd_Cell(rnd_row , rnd_col);
    prim.Generate(rnd_row, rnd_col);
    dj.Solve(rnd_row, rnd_col);
    //dj.printGridFlat();
    ///////////////////////////////////////////////////////////////////////
    
    // allocating memory for image buffer
    Draw_Buffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    //guarantee that the FBO starts with a clean slate
    //Draw_Buffer.begin();
    //c_render.Draw_Walls();
    //ofClear(255 , 255 , 255 , 0);
    //Draw_Buffer.end();



}

//RESET FLOOD_FLAT TO -1 EACH TIME WE RUN AGAIN DFS , SAME FOR OTHER DS 
void ofApp::update() {
    
    static unsigned long lastUpdateTime = 0;
    unsigned long currentTime = ofGetElapsedTimeMillis();
    static int stepSize = 22; // Control speed: higher value for faster rendering

    if (currentTime - lastUpdateTime > MILLISECS_PER_FRAME) {
        static int currentIndex = 0;

        for (int i = 0; i < stepSize; ++i) {
            if (currentIndex < total_cells) {
                Draw_Buffer.begin();
                //render.Draw(currentIndex, maze, dfs.Get_Flat_DS());
                render.Draw(currentIndex, weight_maze, dj.Get_Flat_DS());
                Draw_Buffer.end();
                currentIndex++;
            }
        }
        lastUpdateTime = currentTime;
    }
}

//-View-------------------------------------------------------------
void ofApp::draw() {
    Draw_Buffer.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
    case 'b':
        maze_algo = Maze_Algos::Binary_Tree;
        std::cout<<"binary_tree"<<std::endl;
        break;
    case 's':
        maze_algo = Maze_Algos::Sidewinder;
        std::cout << "sidewinder" << std::endl;
        break;
    case 'a':
        maze_algo = Maze_Algos::Aldous_Broder;
        std::cout << "aldous_broder" << std::endl;
        break;
    case 'w':
        maze_algo = Maze_Algos::Wilsons;
        std::cout << "wilsons" << std::endl;
        break;
    case 'h':
        maze_algo = Maze_Algos::Hunt_and_Kill;
        break;
    case 'r':
        maze_algo = Maze_Algos::Recursive_Backtracker;
        break;
    case 'g':
        maze_algo = Maze_Algos::Growing_Tree;
        break;
    case 'e':
        maze_algo = Maze_Algos::Ellers;
        break;
    case 'p':
        maze_algo = Maze_Algos::Prims;
        break;
    case 'k':
        maze_algo = Maze_Algos::Kruskals;
        break;
    }

    //Setup_Maze(maze_algo);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

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