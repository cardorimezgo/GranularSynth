#pragma once 

#include "Grid.h"
#include <random>

class MazeSolver{

protected:

    Grid& maze_;
    std::vector<std::vector<int>> flood_fill; 
	std::vector<std::pair<int, std::pair<int , int>>> grid_flat; //vector for flattening vector of vectors
    
    
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

public:

    MazeSolver(Grid& maze) :
        maze_(maze)
    {}

    virtual ~MazeSolver() {} //Virtual destructor

    //Required implementation by each maze solving algorithm
    virtual void Solve(int row , int col) = 0;

    virtual const std::vector<std::pair<int, std::pair<int, int>>>& Get_Flat_DS() = 0;
    /*
    //Return flattened and ordered list of cells
    const std::vector<std::pair<int, std::pair<int , int>>>& Get_Flat_DS(){
		return grid_flat;
	}		
    */
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
