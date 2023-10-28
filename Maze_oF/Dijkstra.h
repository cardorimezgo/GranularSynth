#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Maze_Solver.h"
#include "Weighted_Grid.h"
#include <vector>
#include <map>

/*
class DijkstraSolver{
    Weighted_Grid& w_grid_;

    // Creation of struct for specific pair Cell and int that will be used in priority queue
    using cell_Dist = std::pair<Cell* , int>;
    struct Compare{
        bool operator()(const cell_Dist& a, const cell_Dist& b)const{
            return a.second > b.second;
        }
    };
    std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare>minHeap;
    
    // DS for storing cells that have already been processed
    std::vector<std::vector<bool>> finalized;

    // DS for updating distance value between cells and origin cell
    std::vector<std::vector<int>> dist;
    //vector for flattening vector of vectors 
    std::vector<std::pair<int, std::pair<int , int>>> dist_flat; 

    void Dijkstra_Solver(int r , int c){
        if(w_grid_.IsInvalid(r , c))
            return;

        auto* const origin = w_grid_.Get_Cell(r , c);
        auto current_cell = origin;
        int distance = 0;//0 distance to origin cell
        minHeap.push({origin , distance}); //adding origin cell to pq
        dist[r][c] = distance; 
        int num_Fin = 0;
        
        while(!minHeap.empty() && num_Fin != w_grid_.Total_Cells()){ 
            cell_Dist pq_top = minHeap.top();
            current_cell = pq_top.first;
            minHeap.pop(); //removing root from minHeap

            if(finalized[current_cell->row][current_cell->col])
                continue;

            //Adding cell to finalized list
            finalized[current_cell->row][current_cell->col] = true;
            num_Fin++;
            
            auto neighbors = current_cell->GetNeighbors();
            for(auto neighbor : neighbors){
                if(neighbor && !finalized[neighbor->row][neighbor->col] &&
                   current_cell->Linked(neighbor)){
                    int weight = w_grid_.get_Weight(current_cell , neighbor);
                    
                    if(weight == INT_MAX) 
                        continue; // There is no edge
                        
                    // Adding and updating distance values
                    int new_dist = dist[current_cell->row][current_cell->col] + weight;
                    if(new_dist < dist[neighbor->row][neighbor->col]){
                        dist[neighbor->row][neighbor->col] = new_dist;
                        minHeap.push({neighbor , new_dist}); // Inserting neighbor into minHeap
                        
                        //std::cout<<"current_row:"<<current_cell->row<<" current_col:"<<current_cell->col<<" weight:"<<weight
                        //<<" neighbor_row:"<<neighbor->row<<" neighbor_col:"<<neighbor->col<<" new_dist:"<<new_dist<<std::endl;
                    }
                }
            }
        }
    } 
    
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
                finalized[r][c] = false;
            }
        }
    }

    //Flattening vector of vectors
	//Sorting distance/color in ascending order
	void Dist_Sort(){
		for(int r = 0; r < dist.size(); r++){
			// number of columns in row "r"
			for(int c = 0; c < dist[r].size(); c++){
				dist_flat.push_back({dist[r][c] , {r , c}});
			}
		} 
		std::sort(dist_flat.begin(), dist_flat.end(), [](const auto& a , const auto& b){
			return a.first < b.first;
		});
	}

    void printDistFlat() {
    std::cout << "Printing dist_flat:" << std::endl;
    
    for (const auto& element : dist_flat) {
        int dist_value = element.first;
        int row = element.second.first;
        int col = element.second.second;

        std::cout << "(" << dist_value << ", (" << row << ", " << col << "))" << std::endl;
    }
}
    
    ////////////////////////////////////////////////////////////////////////////////

public:

    DijkstraSolver (Weighted_Grid& w_grid):
    w_grid_(w_grid),
    dist(w_grid_.GetNumRows() , std::vector<int>(w_grid_.GetNumCols(), INT_MAX)),
    finalized(w_grid_.GetNumRows() , std::vector<bool>(w_grid_.GetNumCols(), false))
    {
        w_grid_.init_Weights();
    }    

    void Reset_DSs(){
        // Initialize all finalized values to false
        Init_Final();
        // Initialize all distance values to INT_MAX
        Init_Dist();
        //Clearing Priority Queue
        std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare> empty;
        std::swap(minHeap , empty);
        // Setting weight values to grid 
        w_grid_.init_Weights();
    }

    //(start cell - end cell)Finds a Path from the NW corner to the SE corner
    void Run(){
        Cell* const sw_corner = w_grid_.GetCell(w_grid_.GetNumRows()-1, 0);
        Dijkstra_Solver(sw_corner->row, sw_corner->col);
        Dist_Sort();

        //Debbuging num cells
        //printDistFlat();
    }

    const std::vector<std::pair<int, std::pair<int , int>>>& Get_Flat_DS(){
			return dist_flat;
		}		

};
*/

class Dijkstra : public MazeSolver {
    
    Weighted_Grid& w_grid_;

    // Creation of struct for specific pair Cell and int that will be used in priority queue
    using cell_Dist = std::pair<Cell*, int>;
    struct Compare {
        bool operator()(const cell_Dist& a, const cell_Dist& b)const {
            return a.second > b.second;
        }
    };
    std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare>minHeap;

    // DS for storing cells that have already been processed
    std::vector<std::vector<bool>> finalized;

    void Dijkstra_Solver(int r, int c) {
        if (w_grid_.IsInvalid(r, c))
            return;

        auto* const origin = w_grid_.Get_Cell(r, c);
        auto current_cell = origin;
        int distance = 0;//0 distance to origin cell
        minHeap.push({ origin , distance }); //adding origin cell to pq
        flood_fill[r][c] = distance;
        int num_Fin = 0;

        while (!minHeap.empty() && num_Fin != w_grid_.Total_Cells()) {
            cell_Dist pq_top = minHeap.top();
            current_cell = pq_top.first;
            minHeap.pop(); //removing root from minHeap

            if (finalized[current_cell->row][current_cell->col])
                continue;

            //Adding cell to finalized list
            finalized[current_cell->row][current_cell->col] = true;
            num_Fin++;

            auto neighbors = current_cell->GetNeighbors();
            for (auto neighbor : neighbors) {
                if (neighbor && !finalized[neighbor->row][neighbor->col] &&
                    current_cell->Linked(neighbor)) {
                    int weight = w_grid_.get_Weight(current_cell, neighbor);

                    if (weight == INT_MAX)
                        continue; // There is no edge

                    // Adding and updating distance values
                    int new_dist = flood_fill[current_cell->row][current_cell->col] + weight;
                    if (new_dist < flood_fill[neighbor->row][neighbor->col]) {
                        flood_fill[neighbor->row][neighbor->col] = new_dist;
                        minHeap.push({ neighbor , new_dist }); // Inserting neighbor into minHeap
                    }
                }
            }
        }
    }

public:
    Dijkstra(Weighted_Grid& w_grid) :
    MazeSolver(w_grid_, "Dijkstra"),
    w_grid_(w_grid),
    finalized(w_grid_.GetNumRows(), std::vector<bool>(w_grid_.GetNumCols(), false))
    {
        flood_fill.resize(w_grid_.GetNumRows(), std::vector<int>(w_grid_.GetNumCols(), INT_MAX));
    }    

    void Solve(int row , int col) override {
        // Starting Cell & start value distance
        Dijkstra_Solver(row, col);
        //Sorting cells for the maze to be rendered 
        flood_fill_sort();
    }

};
#endif // DIJKSTRA_H
