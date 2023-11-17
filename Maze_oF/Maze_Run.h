#pragma once

#include "Maze_Sz.h"
#include "Maze_Algos.h"
#include "Grid.h"
#include "Weighted_Grid.h"
#include "Maze_Algos.h"
#include "Maze_Solver.h"
#include "Binary_Tree.h"
#include "Sidewinder.h"
#include "Prim's.h"
#include "Depth_First_Search.h"
#include "Dijkstra.h"

class Maze_Run {
	Maze_Sz sz;
	Maze_Algos maze_algo;
	Grid maze;
	Weighted_Grid  w_maze;
	BinaryTreeGenerator bt;
	Sidewinder sw;
	Prim prim;
	

public:
	Maze_Run():
		maze(sz.get_Total_Rows(), sz.get_Total_Cols(), sz.get_Margin(), sz.get_cell_Sz()),
		w_maze(sz.get_Total_Rows(), sz.get_Total_Cols(), sz.get_Margin(), sz.get_cell_Sz()),
		bt(maze),
		sw(maze),
		prim(w_maze)
	{}

	void Select_Maze(int key);

	void Setup_Maze(Maze_Algos type);

};