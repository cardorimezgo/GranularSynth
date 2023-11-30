#pragma once

#include "Maze_Sz.h"
#include "Maze_Algos.h"
#include "Grid.h"
#include "Maze_Algos.h"
#include "Maze_Solver.h"
#include "Binary_Tree.h"
#include "Sidewinder.h"
#include "Prim's.h"
#include "Depth_First_Search.h"
#include "Dijkstra.h"
#include "Cell_Renderer.h"

#include <memory>

class Maze_Run {
	Maze_Sz& sz;
	Grid maze;
	Maze_Algos& maze_algo;

	Depth_First_Search dfs;
	Dijkstra dj;

	BinaryTreeGenerator bt;
	Sidewinder sw;
	Prim prim;	

	std::unique_ptr<MazeSolver> m_solver; //use of smart pointer to manage Maze_Solver
	std::unique_ptr<Cell_Renderer> c_render; // smart pointer for Cell_Renderer

public:
	Maze_Run(Maze_Sz& sz_ , Maze_Algos& maze_algo_) :
		sz(sz_),
		maze_algo(maze_algo_),
		maze(sz_),
		dfs(maze),
		dj(maze),
		bt(maze),
		sw(maze),
		prim(maze),
		m_solver(nullptr),
		c_render(nullptr)		
	{}

	bool Select_Maze(int key);

	void Setup_Maze(Maze_Algos type);

	void Render(int frame);

	void Print_List();
};