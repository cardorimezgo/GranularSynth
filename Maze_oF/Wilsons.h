#pragma once

#include "Maze_Generator.h"

class Wilsons: public MazeGenerator {

	vector<Cell*> path;

public:

	Wilsons(Grid& maze): MazeGenerator(maze)
	{}
		
	void Generate(int row, int col) override {
		// Generation of random values for neighbor
		std::uniform_int_distribution<int> nbr(0, 3);

		auto* current_cell = maze_.Get_Cell(row, col);
		int num_fin = 1;
	}
};