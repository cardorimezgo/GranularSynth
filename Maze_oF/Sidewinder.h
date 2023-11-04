#pragma once
// start south west corner
// use of random function from Maze_Generator class
// every cell must be visited once 
// 
// each eastern cell that is carved should be stored in a group
// from the group of carved cells we randomly chose one and link north
// once we carved north on one of the grouped cells, we move east to the next cell (without carving east)
// cotinue the same process  
// when arriving to the east boundary of the grid, close the group of cells visited (even if its one) and link north
// go up the next row and repeat the same process
// When arriving to the top row, the option of linking north is deactivated, we can only link east (which will give us an open row corridor)

// random function alternate between two functions: 
// 1) carve east: link eastern neighbor
// 2) chose one of the group of cells to carve north
#include "Maze_Generator.h"

class Sidewinder : public MazeGenerator {

public:

	Sidewinder(Grid& maze): MazeGenerator(maze , "SideWinder")
	{}

	//set initial row and col to [GRID_DIM_Y - 1] and [0] respectively 
	void Generate(int in_row, int in_col) override {
		int num_cells = 0;
		vector<int> group;
		Cell* c;

		while (num_cells != maze_.Total_Cells()) {

			for (int r = in_row; r >= 0; r--) {
				for (int c = in_col; c < maze_.GetNumCols(); c++) {
					std::uniform_int_distribution<int> distribution(0 , 1);
					bool IO = distribution(rng_) != 0; // converting to boolean variable
					if(IO){
						c[r][c].Link(r, c + 1, Direction::East);
						group.push_back(c);

					}
					else{
						std::uniform_int_distribution<int> (0, 1); /// set vals 
					}

					num_cells++;
				}
			}
		}
	}
};