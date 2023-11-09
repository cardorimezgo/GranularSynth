#pragma once
#include "Maze_Generator.h"

class Sidewinder : public MazeGenerator {

public:

	Sidewinder(Grid& maze): MazeGenerator(maze , "SideWinder")
	{}

	void Generate(int i_r, int i_c) override {
		std::uniform_int_distribution<int> e_or_n(1, 2);

		for (int r = maze_.GetNumRows() - 1; r > 0; r--) {
		int group_run = 0;
			for (int c = 0; c < maze_.GetNumCols(); c++) {		
				int rand_int = e_or_n(rng_);
				
				if (rand_int == 2) { //If not at east border Open east wall
					if (!maze_.Link(r, c, Direction::East)){ // if we are at the last col, carve north
						rand_int = 1;
					}
				}

				if (rand_int == 1) { //If at the last column Open North wall for one of the cells in the group
					std::uniform_int_distribution<> group_c(group_run, c);
					int ran_index = group_c(rng_);
					maze_.Link(r, ran_index, Direction::North);
					group_run = c + 1;
				}
			}
		}
		for (int c = 0; c < maze_.GetNumCols() - 1; c++) {
			maze_.Link(0, c, Direction::East);
		}
	}

};