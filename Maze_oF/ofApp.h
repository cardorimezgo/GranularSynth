#pragma once

#include "ofMain.h"
#include "Grid.h"
#include "Weighted_Grid.h"
#include "Depth_First_Search.h"
#include "Dijkstra.h"
#include "Cell_Renderer.h"
#include "Prim's.h"
#include "Binary_Tree.h"

//Grid variables 
constexpr auto GRID_DIM_X = 100; ///cols//100///50///25///10
constexpr auto GRID_DIM_Y = 60; //rows////60///30///15////6
constexpr auto MARG = 0;
constexpr auto CELL_SZ = 8; //////////////8///16///32///80         

// Delta time
const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
		
        int total_cells;

        ofFbo Draw_Buffer;
        Grid maze = Grid(GRID_DIM_Y, GRID_DIM_X, MARG, CELL_SZ);
		Weighted_Grid weight_maze = Weighted_Grid(GRID_DIM_Y, GRID_DIM_X, MARG, CELL_SZ);
		Depth_First_Search dfs = Depth_First_Search(maze);
        DijkstraSolver dj = DijkstraSolver(weight_maze);
		BinaryTreeGenerator bt = BinaryTreeGenerator(maze);
		Prim prim = Prim(weight_maze);
        Cell_Renderer render = Cell_Renderer();
};
