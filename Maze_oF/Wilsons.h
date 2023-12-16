#pragma once

#include "Maze_Generator.h"

class Wilsons: public MazeGenerator {
	
	vector<vector<int>> path;

public:

Wilsons(Grid& maze): MazeGenerator(maze)
{}
		
void Generate(int row, int col) override {
		
	// Finalized first random cell
	finalized[row][col] = true;
	int num_fin = 1;

	std::uniform_int_distribution<int>rnd_row(0, maze_.GetNumRows());
	std::uniform_int_distribution<int>rnd_col(0, maze_.GetNumCols());
				
	while (num_fin != maze_.Total_Cells()) {
		int rnd_r = rnd_row(rng_);
		int rnd_c = rnd_col(rng_);
		auto* current_cell = maze_.GetCell(rnd_r, rnd_c);

		Make_Path(current_cell);
	}
}

void Make_Path(Cell* start) {
	int num_steps = 0;
	std::uniform_int_distribution<int>nbr(0, 3);
	path[start->row][start->col] = num_steps++;
	
	while (!finalized[start->row][start->col]) {
		int rnd_nbr = nbr(rng_);
		Direction dir = IntToDirection(rnd_nbr);

		auto neighbor = start->GetNeighbor(dir);

		if (neighbor) {
			
			if (path[neighbor->row][neighbor->col]) {

				//eliminate the last cells up until the one that is being intersected
				//ENCODING AND DECODING CELLS.
			}
			else {
				path[neighbor->row][neighbor->col] = num_steps++;
				start = neighbor;
				//link all the cells in the path
				// you found a finalized cell, close path and add it to finalized cells
			}
		}
		else {
			continue;
		}
	}
}

};