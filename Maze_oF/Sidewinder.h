#pragma once
#include "Maze_Generator.h"

class Sidewinder : public MazeGenerator {

public:

	Sidewinder(Grid& maze): MazeGenerator(maze , "SideWinder")
	{}

	void Generate(int i_r, int i_c) override {

			for (int r = maze_.GetNumRows()- 1; r >= 0; r--) {
				int group_run = 0;
				for (int c = 0; c < maze_.GetNumCols(); c++) {
					std::uniform_int_distribution<int> e_or_n(0, 1);
					bool io = e_or_n(rng_) != 0;

					if(io){
						if (!maze_.Link(r, c, Direction::East))
							io = 0;
					}
					else{
						// Select random cell from the group of cells visited
						if (!group.empty()) {
							std::uniform_int_distribution<> group_c(0, group.size() - 1);
							int ran_index = group_c(rng_);
							maze_.Link(r, ran_index, Direction::North);
						}
						else {
							maze_.Link(r, c, Direction::North);
						}
						group.clear();
					}
					num_cells++;
				}
			}
		}
	}
};