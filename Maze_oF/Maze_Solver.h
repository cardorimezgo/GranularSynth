#pragma once 

#include "Grid.h"
#include <random>

class MazeSolver{
public:
    Grid& maze_;
    std::vector<std::vector<int>> flood_fill; // -1 for unvisited, -2 for blocked, else distance from source.
	std::vector<std::pair<int, std::pair<int , int>>> grid_flat; //vector for flattening vector of vectors
    std::string name_;

    MazeSolver(Grid& maze, std::string name):
    maze_(maze), name_(name)
    {}

    //Required implementation by each maze solving algorithm
    virtual void Solve() = 0;

    //Get name of maze solving algorithm
    const std::string& GetName(){
        return name_;
    }

    //Flattening vector of vectors
	//Sorting distance/color in ascending order
	void flood_fill_sort(){
		for(int r = 0; r < flood_fill.size(); r++){
			// number of columns in row "r"
			for(int c = 0; c < flood_fill[r].size(); c++){
				grid_flat.push_back({flood_fill[r][c] , {r , c}});
			}
		} 
		std::sort(grid_flat.begin(), grid_flat.end(), [](const auto& a , const auto& b){
		    return a.first < b.first;
		});
	}

    //Return flattened and ordered list of cells
    const std::vector<std::pair<int, std::pair<int , int>>>& Get_Flat_DS(){
		return grid_flat;
	}		

    void printGridFlat() {
    std::cout << "Printing dist_flat:" << std::endl;
    
        for (const auto& element : grid_flat) {
            int dist_value = element.first;
            int row = element.second.first;
            int col = element.second.second;

            std::cout << "(" << dist_value << ", (" << row << ", " << col << "))" << std::endl;
        }
    }
};
