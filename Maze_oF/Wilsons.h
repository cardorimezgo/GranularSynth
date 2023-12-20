#pragma once
#include<iostream>
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

	std::uniform_int_distribution<int>rnd_row(0, maze_.GetNumRows()-1);
	std::uniform_int_distribution<int>rnd_col(0, maze_.GetNumCols()-1);
				
	while (num_fin != maze_.Total_Cells()) { 
		int rnd_r = rnd_row(rng_);
		int rnd_c = rnd_col(rng_);
		auto* current_cell = maze_.GetCell(rnd_r, rnd_c); // this cell should be different to the first finalized cell

		if (current_cell && !finalized[current_cell->row][current_cell->col]) { //start from a random unfinished cell
			Make_Path(current_cell);
			//Linking cells
			for (int i = 0; i < path.size() - 1; i++) {
				Cell* c1 = maze_.GetCell(Decode_Cell(path[i]).first, Decode_Cell(path[i]).second);
				Cell* c2 = maze_.GetCell(Decode_Cell(path[i + 1]).first, Decode_Cell(path[i + 1]).second);
				c1->LinkCell(c2);
				// Finalizing all the cells in the path except the last one which was already finalized
				finalized[Decode_Cell(path[i]).first][Decode_Cell(path[i]).second] = true;
			}
			int dec_row = Decode_Cell(path[path.size() - 1]).first;
			int dec_col = Decode_Cell(path[path.size() - 1]).second;
			finalized[dec_row][dec_col] = true;
			num_fin += path.size();
		}
		else {
			continue;
		}
	}
}

void Make_Path(Cell* current_c) {
	std::uniform_int_distribution<int>nbr(0, 3);
	un_map.clear();
	path.clear();
	path.push_back(Encode_Cell(current_c->row , current_c->col)); //Adding first cell to the path
	un_map[Encode_Cell(current_c->row , current_c->col)] = 0; //Adding first cell to unordered_map

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
			}else{  //neighbor isn't in path
				un_map[encoded_cell] = path.size();
				path.push_back(encoded_cell); //adding cell to the path
				current_c = neighbor;
			}
		}else{
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
