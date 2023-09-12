#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Grid.h"
//#include "Priority_Queue.h"
#include <vector>
//#include <limits>


class DijkstraSolver{
    Grid& grid_;
    std::vector<std::vector<int>>flood_fill;
    std::vector<std::pair<int, std::pair<int,int>>>flat_tree;

    //the weights are already assigned by maze algo
    void Dijkstra_Solver(int r , int c){

        if(grid_.IsInvalid(r , c))
        return;
    } 

    /*
    void DFS_helper(int r, int c, int distance){
		if(grid_.IsInvalid(r , c) || flood_fill[r][c] != -1)
			return

		flood_fill[r][c] = distance;

		auto* const current_cell = grid_.GetCell(r , c);
		auto neighbors = current_cell->GetNeighbors();
		for(auto neighbor : neighbors){
			if(current_cell->Linked(neighbor))
				DFS_helper(neighbor->row , neighbor->col, distance+1);
		}
	}
    */
    void Print(){
        for(int r = grid_.GetNumRows() - 1; r >= 0; r--){
            for(int c = 0; c < grid_.GetNumCols(); c++){
                std::cout << std::setw(2) <<flood_fill[r][c] << " ";
            }
            std::cout << std::endl;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////*/

public:

    //todo: getter for running DIjkstra algo
    // getter for the calculated distance values 
    // give option to user to start anywhere he wants
    DijkstraSolver (Grid& grid):
    grid_(grid),
    flood_fill(grid_.GetNumRows() , std::vector<int>(grid_.GetNumCols(), -1))
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
