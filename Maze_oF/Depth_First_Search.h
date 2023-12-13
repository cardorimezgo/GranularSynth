#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include "Maze_Solver.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Depth_First_Search: public MazeSolver{

public:
    Depth_First_Search(Grid& maze_): 
	MazeSolver(maze_)
    {
		// Initializing to -1 every cell
		flood_fill.resize(maze_.GetNumRows() , vector<int>(maze_.GetNumCols(), -1));
	}

    void DFS_Solver(int r, int c, int distance){
        if(maze_.IsInvalid(r , c) || flood_fill[r][c] != -1)
			return;

		flood_fill[r][c] = distance;
		//cout << "r:" << r << " c:" << c <<" dist: " << distance << endl;////////////////debugging
		auto* const current_cell = maze_.GetCell(r , c);
		auto neighbors = current_cell->GetNeighbors();
		for(auto neighbor : neighbors){
			if(current_cell->Linked(neighbor))
				DFS_Solver(neighbor->row , neighbor->col, distance+1);
		}
    }
	
	// solve algorithm starting at cell: row , col
	void Solve(int row , int col) override{
		DFS_Solver(row , col , 0); 
		//Sorting cells for the maze to be rendered 
		flood_fill_sort();
		//printGridFlat();////////////////debugging
	}

	const std::vector<std::pair<int, std::pair<int, int>>>& Get_Flat_DS() override {
		return grid_flat;
	}

	void Clear_Solve_DS() override{
		MazeSolver::Clear_Solve_DS();
	}

};
#endif // DEPTH_FIRST_SEARCH_H
