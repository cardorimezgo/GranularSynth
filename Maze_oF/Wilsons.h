#pragma once

#include "Maze_Generator.h"

class Wilsons: public MazeGenerator {
	
	vector<int> path;

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
		///Linking and adding to the maze only when the path has found a finalized cell
	}
}

void Make_Path(Cell* current_c) {
	int num_step = 0;
	std::uniform_int_distribution<int>nbr(0, 3);
	path[num_step] = Encode_Cell(current_c->row , current_c->col); ///DYNAMIC VECTOR GROWTH
	
	while (!finalized[current_c->row][current_c->col]) {
		int rnd_nbr = nbr(rng_);
		Direction dir = IntToDirection(rnd_nbr);

		auto neighbor = current_c->GetNeighbor(dir);

		if (neighbor) {
			
			if (path[num_step]) {

				//eliminate the last cells up until the one that is being intersected
				//ENCODING AND DECODING CELLS.
			}
			else /*no path or finalized*/ {
				path[num_step] = Encode_Cell(neighbor->row , neighbor->col);
				current_c = neighbor;
				
				// you found a finalized cell, close path and add it to finalized cells
			}
		}
		else {
			continue;
		}
	}
}

int Encode_Cell(int row, int col) {
	return row * 1000 + col;
}

pair<int, int> Decode_Cell(	int pos) {
	int row = pos / 1000;
	int col = pos % 1000;
	return{ row , col };
}

};
