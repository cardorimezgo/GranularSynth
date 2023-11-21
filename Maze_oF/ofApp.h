#pragma once

#include "ofMain.h"
#include "Grid.h"
//#include "Weighted_Grid.h"
//#include "Depth_First_Search.h"
//#include "Dijkstra.h"
//#include "Cell_Renderer.h"
//#include "Prim's.h"
//#include "Binary_Tree.h"
//#include "Sidewinder.h"
//#include "Maze_Solver.h"
#include "Maze_Algos.h"
#include "Maze_Run.h"
#include "Maze_Sz.h"

//Grid variables   /// the number of cols and rows arent constant, will change according to user's needs
//constexpr auto GRID_DIM_X = 100; ///cols//100///50///25///10
//constexpr auto GRID_DIM_Y = 60; //rows////60///30///15////6
//constexpr auto MARG = 0;
//constexpr auto CELL_SZ = 8; //////////////8///16///32///80         

// Delta time
const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;

enum AppState {
	WAITING_FOR_INPUT,
	MAZE_GENERATION,
	MAZE_GENERATED
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

	//int total_cells = 0;

	///KEYBOARD INTERACTION
	bool set_size = false;
	bool set_maze = false;
	/////////////////////

	ofFbo Draw_Buffer;
	/*
	Maze_Sz sz;
	
	Weighted_Grid w_maze = Weighted_Grid(sz.get_Total_Rows(), sz.get_Total_Cols(), sz.get_Margin(), sz.get_cell_Sz());
	Depth_First_Search dfs = Depth_First_Search(maze);
	
	
	
	Cell_Renderer c_render = Cell_Renderer(maze, dfs);
	*/
	//Dijkstra dj = Dijkstra(weight_maze);
	//BinaryTreeGenerator bt = BinaryTreeGenerator(maze);
	//Sidewinder sw = Sidewinder(maze);
	//Prim prim = Prim(weight_maze);
	Maze_Sz sz;
	Maze_Run run = Maze_Run (sz);
	Maze_Algos maze_algo;
	Grid maze = Grid(sz.get_Total_Rows(), sz.get_Total_Cols(), sz.get_Margin(), sz.get_cell_Sz());

private:
	AppState currentState;
};