#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Grid.h"
#include "Priority_Queue"
#include <vector>
#include <limits>


class DijkstraSolver{

    Grid& grid_;

    // DS for handling (x , y) coordinates and distance of each cell
    struct Cell_Dist{
        int x;
        int y;
        int dist;
    };

    std::vector<Cell_Dist> cell_dist;

    //start cell
    Cell* const nw_corner = grid_.GetCell(grid_.GetNumRows()-1, 0);
    //end cell
    Cell* const se_corner = grid_.GetCell(0, grid_.GetNumCols()-1);

    void Dijkstra_Init(){  ///CALL THIS FUNCTION AT THE CONSTRUCTOR!?

        //Initialization distances to "infinity"
        int index = 0;
        for(int r = grid_.GetNumRows() - 1; r >= 0; r++){
            for(int c = 0; i < grid_.GetNumCols(); c++){
                cell_dist[index].x = r;
                cell_dist[index].y = c;
                cell_dist[index].dist = std::numeric_limits<int>::max(); //Using the maximum value for the integer type
                index++;
            }
        }

        // Flattening array Column-major
        //////////////////////// col * rows + row
        int nw_corner_index = nw_corner->col * grid_.GetNumRows() + nw_corner->row;
        // Initialization for the first cell
        cell_dist[nw_corner_index].dist = 0;


    }

    void Dijkstra_Solver(){

        if(grid_.IsIvalid())
    }

public:

    DijkstraSolver (Grid& grid):
    grid_(grid),
    cell_dist(grid.GetNumRows() * grid.GetNumCols())
    { }

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
                                 
                                                     
