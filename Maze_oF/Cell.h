#pragma once
#include <unordered_map>
#include <vector>
#include "Dir.h"

struct Cell {

	int row, col;

	//linked cells
	std::vector<Cell*>links;
	
	// Neighbors 
	std::unordered_map<Direction, Cell*, EnumClassHash> neighbors;

	Cell()
};
