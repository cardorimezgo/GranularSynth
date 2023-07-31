#pragma once

#include "ofMain.h"
#include "Grid.h"
#include "Maze_Generator.h"
#include "Dijkstra.h"

constexpr auto GRID_DIM_X = 50;
constexpr auto GRID_DIM_Y = 30;
constexpr auto MARG = 0;
constexpr auto CELL_SZ = 16;

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

        Grid draw_maze = Grid(GRID_DIM_X, GRID_DIM_Y, MARG, CELL_SZ);

};
