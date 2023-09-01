#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include "Grid.h"
#include <vector>
#include <algorithm>

class Depth_First_Search{ //RESET FLOOD_FLAT TO -1 EACH TIME WE RUN AGAIN DFS , SAME FOR OTHER DS 
	Grid& grid_;

	// -1 for unvisited, -2 for blocked, else distance from source.
	std::vector<std::vector<int>> flood_fill;
	//vector for flattening vector of vectors
	std::vector<std::pair<int, std::pair<int , int>>> flood_flat;

	//Recursive implementation of Depth Search algorithm 
	void DFS_helper(int r, int c, int distance){
		if(grid_.IsInvalid(r , c) || flood_fill[r][c] != -1)
			return;

		flood_fill[r][c] = distance;

	auto* const current_cell = grid_.GetCell(r , c);
	auto neighbors = current_cell->GetNeighbors();
	for(auto neighbor : neighbors){
		if(current_cell->Linked(neighbor))
			DFS_helper(neighbor->row , neighbor->col, distance+1);
	}
}

void flood_fill_sort(){
	//Flattening vector of vectors
	for(int i = 0; i < flood_fill[0].size(); i++){
		for(int j = 0; j < flood_fill.size(); j++){
			flood_flat.push_back({flood_fill[i][j] , {i , j}});
		}
	} 
	//Sorting distance/color in ascending order
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

void Print_flat(){
	for(int i = 0; i < flood_flat.size(); i++){
		std::cout <<  "{" << flood_flat[i].first << ", (" << flood_flat[i].second.first << "," << flood_flat[i].second.second <<")}" ;
	}
	std::cout << std::endl;
}


public:
	Depth_First_Search(Grid& grid):
		grid_(grid), 
		// Initialize to -1 every cell
		flood_fill(grid_.GetNumRows() , std::vector<int>(grid_.GetNumCols(), -1))
		{}

		void Reset(){
			for(int r = 0; r < grid_.GetNumRows(); r++){
				for(int c = 0; c < grid_.GetNumCols(); c++){
					flood_fill[r][c] = -1;
				}
			}
		}

		void DFS_Run(){
			Cell* const nw_corner = grid_.GetCell(grid_.GetNumRows() - 1, 0);
			Cell* const se_corner = grid_.GetCell(0, grid_.GetNumCols() - 1);
			DFS_helper(nw_corner->row , nw_corner->col, 0);
			flood_fill_sort();
			Print_flat();
		}

		const std::vector<std::vector<int>> Get_DFS(){
			return flood_fill;
		}

		const std::vector<std::pair<int, std::pair<int , int>>>& Get_DFS_flat(){
			return flood_flat;
		}		


};
#endif // DEPTH_FIRST_SEARCH_H
