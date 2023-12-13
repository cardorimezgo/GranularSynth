#pragma once

#include"Maze_Generator.h"

class Aldous_Broder: public MazeGenerator{

public:
	Aldous_Broder(Grid& maze): MazeGenerator(maze)
	{}

	void Generate(int row, int col) override {
		// Generation of random values for neighbor
		std::uniform_int_distribution<int> nbr(0, 3);

		auto* current_cell = maze_.Get_Cell(row, col);
		int num_fin = 1;

		while (num_fin < maze_.Total_Cells()) {
			int rnd_nbr = nbr(rng_);
			IntToDirection(rnd_nbr);
			Direction dir = IntToDirection(rnd_nbr);
			auto neighbor = current_cell->GetNeighbor(dir);

			if (neighbor && !neighbor->Is_linked()) {
				current_cell->LinkCell(neighbor);
				current_cell = neighbor;
				num_fin++;
			}
			else if (neighbor && neighbor->Is_linked()) {
				current_cell = neighbor;
			}
			else {
				continue;
			}
		}
	}
};