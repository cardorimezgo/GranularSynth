#pragma once

#include <unordered_map>
#include <vector>
#include "Dir.h"

struct Cell {

    int row;
    int col;

    //linked cells
    std::vector<Cell*>links;

    // Neighbors
    std::unordered_map<Direction, Cell*, EnumClassHash> neighbors;

    std::vector<Cell*>GetNeighbors();

    Cell(int row_in, int col_in) : row(row_in), col(col_in)
    {}

    // Querying whether the current cell is linked to another given cell
    bool Linked(Cell* cell);

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
    Cell* GetNeighbor(Direction dir);

    void PrintCell(bool print_neighbor = true);

};

inline bool operator==(const Cell& lhs, const Cell& rhs) {
    return (lhs.row == rhs.row) && (lhs.col == rhs.col);
}

inline int HashCell(Cell* cell, int num_cols) {
    return cell->row*num_cols + cell->col;
}

// For user defined type using unordered_map
struct hash_Cell_Ptr{
    std::size_t operator() (const std::pair<Cell*, Cell*>& p) const {
        std::size_t h1 = std::hash<int>{}(p.first->row) ^ std::hash<int>{}(p.first->col);
        std::size_t h2 = std::hash<int>{}(p.second->row) ^ std::hash<int>{}(p.second->col);
        return h1 ^ (h2 << 1);  // or another combining function
    }
};

