#pragma once

#include "Grid.h"
#include "Weighted_Grid.h"
#include "Maze_Algos.h"
#include "Maze_Solver.h"
#include "Binary_Tree.h"
#include "Sidewinder.h"
#include "Prim's.h"
#include "Depth_First_Search.h"

class Maze_Run {
	Grid maze;
	Weighted_Grid  w_maze = Weighted_Grid(w_maze.GetNumRows(), w_maze.GetNumCols(), w_maze.GetMargin(), w_maze.GetCell_Sz());
	//BinaryTreeGenerator bt = BinaryTreeGenerator(maze);
	BinaryTreeGenerator bt;
	Sidewinder sw = Sidewinder(maze);
	Prim prim = Prim(w_maze);
	

public:
	Maze_Run()	{   
		maze(GRID_DIM_Y, maze.GetNumCols(), maze.GetMargin(), maze.GetCell_Sz())
		bt = BinaryTreeGenerator(maze);
	}
	void Setup_Maze(Maze_Algos type);

};