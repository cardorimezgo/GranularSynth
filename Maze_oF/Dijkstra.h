#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Weighted_Grid.h"
#include <vector>
#include <map>


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
    
    // DS for storing cells that have already been processed (1)
    std::vector<std::vector<int>> finalized;

    // DS for updating distance value between cells and origin cell
    std::vector<std::vector<int>> dist;
    //vector for flattening vector of vectors 
    std::vector<std::pair<int, std::pair<int , int>>> dist_flat; 

    void Dijkstra_Solver(int r , int c, int distance){
        if(w_grid_.IsInvalid(r , c) || finalized[r][c] == 1)
            return;
        
        Cell* const origin = w_grid_.Get_Cell(r , c);
        minHeap.push({origin , distance}); //adding origin cell to pq
        dist[r][c] = distance; //setting 0 distance to origin cell
        finalized[r][c] = 1;  // origin cell finalized
        Cell* current_cell = origin;
        int num_Fin = 0;

        while(num_Fin != w_grid_.Total_Cells()){
            auto neighbors = current_cell->GetNeighbors();
            for(auto neighbor : neighbors){
                std::cout<<"current_cell_row"<<current_cell->row//////////////////////
                <<", current_cell_col"<<current_cell->col
                <<", neighbor_row"<<neighbor->row<<///////////////////////
                ", neighbor_col"<<neighbor->col<<std::endl;///////////////////////
                if(Isnt_Final(neighbor->row , neighbor->col)){
                    std::cout<<"num_Fin:"<<num_Fin<<std::endl;///////////////////////
                    // Adding neighbor(s) to priority queue
                    int weight = w_grid_.get_Weight(current_cell , neighbor);
                     std::cout<<"weight:"<<weight<<std::endl;//////////////////////////////////////////
                    std::pair<Cell* , int> newElement = std::make_pair(neighbor , weight);
                    minHeap.push(newElement);
                    // Adding and updating distance values
                    int current_dist = dist[neighbor->row][neighbor->col];
                    std::cout<<"current_dist: "<<current_dist<<std::endl;//////////////////////////////////
                    if(current_dist > weight + dist[current_cell->row][current_cell->col]){
                        dist[neighbor->row][neighbor->col] = weight + dist[current_cell->row][current_cell->col];
                    std::cout<<"current_dist: "<<dist[current_cell->row][current_cell->col]<<std::endl;//////
                    std::cout<<" neighbor_dist: "<<dist[neighbor->row][neighbor->col]<<std::endl;///////////
                    std::cout<<" pq_size: "<<minHeap.size()<<std::endl;}///////////
                    ////////////// DEBUGGING //////////////////////////////
                    auto tempQueue = minHeap;  // Make a copy
                    while (!tempQueue.empty()) {
                        auto top = tempQueue.top();
                        std::cout << "(" << top.first->row << "," << top.first->col << ") : " << top.second << std::endl;
                        tempQueue.pop();
                    }
                    ////////////////////////////////////////////
                }else{
                    continue;
                }
            }
            if(!minHeap.empty()){
                cell_Dist pq_top = minHeap.top();
                Cell* root = pq_top.first;
                std::cout<<"root:"<<root<<std::endl;///////////////////////////////////
                finalized[root->row][root->col] = 1;
                num_Fin++;
                current_cell = root;
                minHeap.pop();
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
                finalized[r][c] = 0;
            }
        }
    }

    bool Isnt_Final(int r, int c){
        //if(w_grid_.IsInvalid(r , c)){
        //    return false;
        //}
        // check if the cell has been finalized
        return finalized[r][c] != 1;
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

    //todo: getter for running DIjkstra algo
    // getter for the calculated distance values 
    // give option to user to start anywhere he wants
    DijkstraSolver (Weighted_Grid& w_grid):
    w_grid_(w_grid),
    dist(w_grid_.GetNumRows() , std::vector<int>(w_grid_.GetNumCols(), INT_MAX)),
    finalized(w_grid_.GetNumRows() , std::vector<int>(w_grid_.GetNumCols(), 0))
    {}    

    void Reset_DSs(){
        // Initialize all finalized values to 0
        Init_Final();
        // Initialize all distance values to INT_MAX
        Init_Dist();
        //Clearing Priority Queue
        std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare> empty;
        std::swap(minHeap , empty);
    }

    //(start cell - end cell)Finds a Path from the NW corner to the SE corner
    void Run(){
        Cell* const sw_corner = w_grid_.GetCell(w_grid_.GetNumRows()-1, 0);
        Dijkstra_Solver(sw_corner->row, sw_corner->col, 0);
        //Dist_Sort();

        //Debbuging num cells
        //printDistFlat();
    }

    const std::vector<std::pair<int, std::pair<int , int>>>& Get_Dist_Flat(){
			return dist_flat;
		}		

};

#endif // DIJKSTRA_H
