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
                //adding +1 to unvisited neighbor
                SolveHelper(neighbor->row, neighbor->col, distance + 1);
        }
    }

    void Print(){
        for(int r = grid_.GetNumRows() - 1; r >= 0; r--){
            for(int c = 0; c < grid_.GetNumCols(); c++){
                std::cout << std::setw(2) <<flood_fill[r][c] << " ";
            }
            std::cout << std::endl;
        }
    }

public:
    DijkstraSolver (Grid& grid):
    grid_(grid), flood_fill(grid_.GetNumRows(),
    std::vector<int>(grid_.GetNumCols(), -1))
    {}

    void Reset(){
        for(int r = 0; r < grid_.GetNumRows(); r++){
            for(int c = 0; c < grid_.GetNumCols(); c++){
                flood_fill[r][c] = -1;
            }
        }
    }

    //Finds a Path from the NW corner to the SE corner
    void Solve(){
        Cell* const nw_corner = grid_.GetCell(grid_.GetNumRows()-1, 0);
        Cell* const se_corner = grid_.GetCell(0, grid_.GetNumCols()-1);
        SolveHelper(nw_corner->row, nw_corner->col, 0);

        Print();
        //print upper left corner "color intensity"
        std::cout << std::setw(2) <<flood_fill[grid_.GetNumRows()-1][0] << " ";
        //
        ofRectangle myRect(0, 0, ofGetWidth() / 2, ofGetHeight() / 2);
        ofDrawRectangle(myRect);
        //grid_.Display();
        //TAKE ADVANTAGE OF THE DISPLAY FUNCTION IN THE GRID CLASS
        // USE FLOOD_FILL METHOD FROM THE DIJKSTRA CLASS
    }


};

#endif // DIJKSTRA_H
