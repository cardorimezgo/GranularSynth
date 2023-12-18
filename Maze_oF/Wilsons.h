#pragma once

#include "Maze_Generator.h"

class Wilsons: public MazeGenerator {
	
	vector<int> path;
	std::unordered_map<int, int>un_map;

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
	// create flag that marks cell is finalized
	int num_step = 0;
	std::uniform_int_distribution<int>nbr(0, 3);
	path.push_back(Encode_Cell(current_c->row , current_c->col)); //Adding first cell to the path
	
	while (!finalized[current_c->row][current_c->col]) {
		int rnd_nbr = nbr(rng_);
		Direction dir = IntToDirection(rnd_nbr);

		auto neighbor = current_c->GetNeighbor(dir);

		if (neighbor) {
			int encoded_cell = Encode_Cell(neighbor->row, neighbor->col);
			auto it = un_map.find(encoded_cell);
			if (it != un_map.end()) {  //loop reached 
				
				int start_loop = it->second;
				path.erase(path.begin() + start_loop + 1, path.end()); //erase cells that make a loop

				//update un_map
				for (auto iter = un_map.begin(); iter != un_map.end();){
					if (iter->second >= start_loop) {
						iter = un_map.erase(iter);
					}else {
						iter++;
					}
				}
			}
			else {  /*no path or finalized*/
				un_map[encoded_cell] = path.size();
				path.push_back(encoded_cell); //adding cell to the path
				current_c = neighbor;
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
