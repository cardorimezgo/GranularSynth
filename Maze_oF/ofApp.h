#pragma once

#include "ofMain.h"
#include "Grid.h"
#include "Maze_Algos.h"
#include "Maze_Run.h"
#include "Maze_Sz.h"        
#include "Binary_Tree.h"//////////////////
#include "Depth_First_Search.h"/////////////
#include "Cell_Renderer.h"//////////

// Delta time
const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;

enum AppState {
	WAITING_FOR_INPUT,
	MAZE_GENERATION,
	MAZE_GENERATED,
	RENDERING_COMPLETE
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	///KEYBOARD INPUT
	bool set_size = false;
	bool set_maze = false;
	/////////////////////

	ofFbo Draw_Buffer;

	Maze_Algos maze_algo;
	Maze_Sz sz;	
	Grid maze = Grid(sz);
	Maze_Run run = Maze_Run(sz , maze);
	//BinaryTreeGenerator bt = BinaryTreeGenerator(maze);/////////
	//Depth_First_Search dfs = Depth_First_Search(maze);/////////
	//Cell_Renderer c_ren = Cell_Renderer(maze);///////////////

private:
	AppState currentState;
};