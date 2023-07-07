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

	Cell(int row_in, int col_in) : row(row_in), col(col_in)
	{}

	// Querying whether the current cell is linked to another given cell
	bool Linked(Cell cell);

	// Return false if neighbor does not exist
	bool LinkCell(Direction dir);

	// Return false if neighbor does not exist
	bool UnlinkCell(Direction dir);

	// Return false if neighbor does not exist
	bool LinkCell(Cell* cell);

	// Return false if neighbor does not exist
	bool UnlinkCell(Cell* cell);

	// Fails if neighbor exists in direction dir
	bool AddNeighbor(Direction dir, Cell* cell);

	//Fails if no neighbor in direction dir
	bool DeleteNeighbor(Direction dir);

	// We need both associative and iterative access to neighbors
	Cell* GetNieghbor(Direction dir);

	std::vector<Cell*>GetNieghbor();

	void PrintCell(bool print_neighbor = true);
};


inline bool operator==(const Cell& lhs, const Cell& rhs) {
	return (lhs.row == rhs.row) && (lhs.col == rhs.col);
}

inline int HashCell(Cell* cell, int num_cols) {
	return cell->row * num_cols + cell->col;
}




