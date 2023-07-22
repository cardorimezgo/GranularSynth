#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Grid.h"
#include <vector>

class DijkstraSolver{
    Grid& grid_;
    // -1 for unvisited, -2 for blocked, else distance from source
    std::vector<std::vector<int>> flood_fill;
    void SolveHelper(int r, int c, int distance){
        //return if invalid cell or already visited
        if(grid_.IsInvalid(r , c) || flood_fill[r][c] != -1)
            return;
        flood_fill[r][c] = distance;

        auto* const current_cell = grid_.GetCell(r , c);
        auto neighbors = current_cell->GetNeighbors();
        for (auto neighbor : neighbors){
            if(current_cell->Linked(neighbor))
                SolveHelper(neighbor->row, neighbor->col, distance + 1);
        }
    }



};

for(int c = 0; c < )


#endif // DIJKSTRA_H
