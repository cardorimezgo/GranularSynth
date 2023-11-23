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
		cout << "r:" << r << " c:" << c <<" dist: " << distance << endl;////////////////
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
	}

	const std::vector<std::pair<int, std::pair<int, int>>>& Get_Flat_DS() override {
		return grid_flat;
	}

	//Get longest simple path
	void L_Path() {
		//need : // store or send flood_fill_sort for drawing maze structure, could we just run it twice and render that version?
		//		 last cell from the DFS firt run cell[x][x]
		//		 clean flood_fill
		//		 clean flood_fill_sort
		//		 run Solve with cell[x][x]
		//
	}

	/*void Reset(){
			for(int r = 0; r < grid_.GetNumRows(); r++){
				for(int c = 0; c < grid_.GetNumCols(); c++){
					flood_fill[r][c] = -1;
				}
			}
		}*/

};

#endif // DEPTH_FIRST_SEARCH_H
