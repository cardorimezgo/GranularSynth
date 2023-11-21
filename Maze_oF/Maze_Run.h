#pragma once

#include "Maze_Sz.h"
#include "Maze_Algos.h"
#include "Grid.h"
//#include "Weighted_Grid.h"
#include "Maze_Algos.h"
#include "Maze_Solver.h"
#include "Binary_Tree.h"
#include "Sidewinder.h"
#include "Prim's.h"
#include "Depth_First_Search.h"
#include "Dijkstra.h"
#include "Cell_Renderer.h"

class Maze_Run {
	Maze_Sz& sz;
	Maze_Algos maze_algo;
	Grid maze;
	
	Depth_First_Search dfs;
	Dijkstra dj;

	BinaryTreeGenerator bt;
	Sidewinder sw;
	Prim prim;	
	

	Cell_Renderer c_render;

public:
	Maze_Run(Maze_Sz& sz_):
		sz(sz_),
		maze(sz_.get_Total_Rows(), sz_.get_Total_Cols(), sz_.get_Margin(), sz_.get_cell_Sz()),
		dfs(maze),
		dj(maze),
		bt(maze),
		sw(maze),
		prim(maze),
		c_render(maze, dfs)
	{}

	bool Select_Maze(int key);

	void Setup_Maze(Maze_Algos type);

	void Render(int frame);


};