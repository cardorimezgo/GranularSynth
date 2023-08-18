#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Grid.h"
#include <vector>

class DijkstraSolver{

    Grid& grid_;

    // DS for handling (x , y) coordinates and distance of each cell
    struct Cell_Dist{
        int x;
        int y;
        int dist;
    };

    std::vector<Cell_Dist> cell_dist(grid_.GetNumRows() * grid_.GetNumCols());

    void Dijkstra(){
        //start cell
        Cell* const nw_corner = grid_.GetCell(grid_.GetNumRows()-1, 0);
        //end cell
        Cell* const se_corner = grid_.GetCell(0, grid_.GetNumCols()-1);

        //Initialization distances to "infinity"
        int index = 0;
        for(int i = grid_.GetNumRows() - 1; i >= 0; i++){
            for(int j = 0; i < grid_.GetNumCols(); j++){
                cell_dist[index].x = i;
                cell_dist[index].y = j;
                cell_dist[index].dist = std::numeric_limits<int>::max(); //Using the maximum value for the integer type
                index++;
            }
        }

        // Flattening array Column-major
        //////////////////////// col         *     rows           + row
        int nw_corner_index = nw_corner->col * grid_.GetNumRows() + nw_corner->row;
        // Initialization for the first cell
        cell_dist[nw_corner_index].dist = 0;


    }





    // -1 for unvisited, -2 for blocked, else distance from source
    std::vector<std::vector<int>> flood_fill;


    //Recursive function to populate vector
    void SolveHelper(int r, int c, int distance){
        //return if invalid cell or already visited
        if(grid_.IsInvalid(r , c) || flood_fill[r][c] != -1)
            return;

        flood_fill[r][c] = distance;
        //std::cout << std::setw(2) <<" |"<<r<<"|"<<"|"<<c<< "| ";
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

    //(start cell - end cell)Finds a Path from the NW corner to the SE corner
    void Solve(){
        Cell* const nw_corner = grid_.GetCell(grid_.GetNumRows()-1, 0);
        Cell* const se_corner = grid_.GetCell(0, grid_.GetNumCols()-1);
        SolveHelper(nw_corner->row, nw_corner->col, 0);

        //Debbuging num cells
        //Print();
    }


};

#endif // DIJKSTRA_H
