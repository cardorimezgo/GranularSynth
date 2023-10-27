#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include "Maze_Solver.h"
#include <iostream>
#include <vector>
#include <algorithm>

/*class Depth_First_Search{ 
	Grid& grid_;	
	std::vector<std::vector<int>> flood_fill; // -1 for unvisited, -2 for blocked, else distance from source.
	std::vector<std::pair<int, std::pair<int , int>>> flood_flat; //vector for flattening vector of vectors

	//Recursive implementation of Depth Search algorithm 
	void DFS_Solver(int r, int c, int distance){
		if(grid_.IsInvalid(r , c) || flood_fill[r][c] != -1)
			return;

		flood_fill[r][c] = distance;

		auto* const current_cell = grid_.GetCell(r , c);
		auto neighbors = current_cell->GetNeighbors();
		for(auto neighbor : neighbors){
			if(current_cell->Linked(neighbor))
				DFS_Solver(neighbor->row , neighbor->col, distance+1);
		}
	}

	//Flattening vector of vectors
	//Sorting distance/color in ascending order
	void flood_fill_sort(){
		for(int r = 0; r < flood_fill.size(); r++){
			// number of columns in row "r"
			for(int c = 0; c < flood_fill[r].size(); c++){
				flood_flat.push_back({flood_fill[r][c] , {r , c}});
			}
		} 
		std::sort(flood_flat.begin(), flood_flat.end(), [](const auto& a , const auto& b){
			return a.first < b.first;
		});
	}

	void Print(){
		for(int r = 0; r < grid_.GetNumRows(); r++){
			for(int c = 0; c < grid_.GetNumCols(); c++){
				std::cout << std::setw(2) <<flood_fill[r][c] << " ";
			}
			std::cout << std::endl;
		}
	}

public:
	Depth_First_Search(Grid& grid):
		grid_(grid), 
		// Initializing to -1 every cell
		flood_fill(grid_.GetNumRows() , std::vector<int>(grid_.GetNumCols(), -1))
		{}

		void Reset(){
			for(int r = 0; r < grid_.GetNumRows(); r++){
				for(int c = 0; c < grid_.GetNumCols(); c++){
					flood_fill[r][c] = -1;
				}
			}
		}

		void Run(){
			Cell* const sw_corner = grid_.GetCell(grid_.GetNumRows() - 1, 0);
			DFS_Solver(sw_corner->row, sw_corner->col, 0); // Starting Cell & start value distance
			flood_fill_sort();			
		}

		const std::vector<std::pair<int, std::pair<int , int>>>& Get_Flat_DS(){
			return flood_flat;
		}		
};*/


class Depth_First_Search: public MazeSolver{

public:
    Depth_First_Search(Grid& maze_): 
	MazeSolver(maze_, "Depth_First_Search")
    {
		// Initializing to -1 every cell
		flood_fill.resize(maze_.GetNumRows() , vector<int>(maze_.GetNumCols(), -1));
	}

    void DFS_Solver(int r, int c, int distance){
        if(maze_.IsInvalid(r , c) || flood_fill[r][c] != -1)
			return;

		flood_fill[r][c] = distance;

		auto* const current_cell = maze_.GetCell(r , c);
		auto neighbors = current_cell->GetNeighbors();
		for(auto neighbor : neighbors){
			if(current_cell->Linked(neighbor))
				DFS_Solver(neighbor->row , neighbor->col, distance+1);
		}
    }
	
	void Solve() override{
		Cell* const sw_corner = maze_.GetCell(maze_.GetNumRows() - 1, 0);
		// Starting Cell & start value distance
		DFS_Solver(sw_corner->row, sw_corner->col, 0); 
		//Sorting cells for the maze to be rendered 
		flood_fill_sort();	
	}

};

#endif // DEPTH_FIRST_SEARCH_H
