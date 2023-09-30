#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Weighted_Grid.h"
#include <vector>
#include <map>


class DijkstraSolver{
    Weighted_Grid& w_grid_;

    //Creation of struct for specific pair Cell and int that will be used in priority queue
    using cell_Dist = std::pair<Cell* , int>;
    struct Compare{
        bool operator()(const cell_Dist& a, const cell_Dist& b)const{
            return a.second > b.second;
        }
    };
    std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare>minHeap;
    
    //DS for storing cells that have already been processed 
    std::vector<std::vector<int>> finalized;

    // DS for updating distance value between cells and origin cell
    std::vector<std::vector<int>> dist; 

    //Weights are already assigned by Weighted_Grid
    void Dijkstra_Solver(int r , int c, int distance){
        if(w_grid_.IsInvalid(r , c))
            return;

        Cell* origin = w_grid_.Get_Cell(r , c);
        minHeap.push({origin , distance});
        dist[r][c] = distance;
        Cell* current_cell = origin;

        while(Isnt_Final(current_cell->row , current_cell->col)){
            auto neighbors = current_cell->GetNeighbors();
            for(auto neighbor : neighbors){
                if(Isnt_Final(neighbor->row , neighbor->col)){
                    //adding neighbor(s) to priority queue
                    int weight = w_grid_.get_Weight(current_cell , neighbor);
                    std::pair<Cell* , int> newElement = std::make_pair(neighbor , weight);
                    minHeap.push(newElement);
                    //adding and updating distance values
                    dist[neighbor->row][neighbor->col] = weight;
                    ////NEED TO ADD A WAY TO UPDATE DISTANCE VALUES!!!!!
                }else{
                    continue;
                }
            }
        }
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
    DijkstraSolver (Weighted_Grid& w_grid):
    w_grid_(w_grid),
    dist(w_grid_.GetNumRows() , std::vector<int>(w_grid_.GetNumCols(), INT_MAX)),
    finalized(w_grid_.GetNumRows() , std::vector<int>(w_grid_.GetNumCols(), -1))
    {}

    void Init_Dist(){
        for(int r = 0; r < w_grid_.GetNumRows(); r++){
            for(int c = 0; c < w_grid_.GetNumCols(); c++){
                dist[r][c] = INT_MAX;
            }
        }
    }

    void Init_Final(){
        for(int r = 0; r < w_grid_.GetNumRows(); r++){
            for(int c = 0; c < w_grid_.GetNumCols(); c++){
                finalized[r][c] = -1;
            }
        }
    }

    bool Isnt_Final(int r, int c){
        if(w_grid_.IsInvalid(r , c)){
            return;
        }
        // check if the cell has been finalized
        return finalized[r][c] != -1;
        }

    void Reset_DS(){
        //Initialize all values to -1
        Init_Final();
        // Initialize all distance values to INT_MAX
        Init_Dist();
        //Clearing Priority Queue
        std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare> empty;
        std::swap(minHeap , empty);
    }

    //(start cell - end cell)Finds a Path from the NW corner to the SE corner
    void Solve(){
        Cell* const nw_corner = grid_.GetCell(grid_.GetNumRows()-1, 0);
        Cell* const se_corner = grid_.GetCell(0, grid_.GetNumCols()-1);
        //SolveHelper(nw_corner->row, nw_corner->col, 0);

        //Debbuging num cells
        //Print();
    }


};

#endif // DIJKSTRA_H
