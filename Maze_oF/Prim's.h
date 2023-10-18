#pragma once

#include "Weighted_Grid.h"
#include <random>
#include <vector>
#include <map>


class Prim{
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

    void Prim_Solver(){
    ///Random seed
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> rows_rnd(0 , w_grid_.GetNumRows() - 1); //rows
    std::uniform_int_distribution<> cols_rnd(0 , w_grid_.GetNumCols() - 1); //cols
    int random_row = rows_rnd(gen);
    int random_col = cols_rnd(gen);
        
        if(w_grid_.IsInvalid(random_row , random_col))
            return;

        auto* const origin = w_grid_.Get_Cell(random_row , random_col);
        auto current_cell = origin;
        int distance = 0;//0 distance to origin cell
        minHeap.push({origin , distance}); //adding origin cell to pq
        dist[random_row][random_col] = distance; 
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
                   !current_cell->Linked(neighbor)){
                    int weight = w_grid_.get_Weight(current_cell , neighbor);
                    
                    if(weight == INT_MAX) 
                        continue; // There is no edge
                        
                    // Adding and updating distance values                    
                    if(weight < dist[neighbor->row][neighbor->col]){
                        dist[neighbor->row][neighbor->col] = weight;
                        current_cell->LinkCell(neighbor);   // Creating Link between Cells
                        minHeap.push({neighbor , weight}); // Inserting neighbor into minHeap

                        //std::cout<<current_cell->row<<" "<<current_cell->col<<" -> "<<neighbor->row<<" "<<
                        //neighbor->col<<std::endl;
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
    
    ////////////////////////////////////////////////////////////////////////////////

public:

    Prim (Weighted_Grid& w_grid):
    w_grid_(w_grid),
    dist(w_grid_.GetNumRows() , std::vector<int>(w_grid_.GetNumCols(), INT_MAX)),
    finalized(w_grid_.GetNumRows() , std::vector<bool>(w_grid_.GetNumCols(), false))
    {
        w_grid_.set_Rnd_Edges();
    }    

    void Reset_DSs(){
        // Initialize all finalized values to false
        Init_Final();
        // Initialize all distance values to INT_MAX
        Init_Dist();
        //Clearing Priority Queue
        minHeap = std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare>();
        // Setting Random weight values to grid 
        w_grid_.set_Rnd_Edges();
    }

    void Run(){
        Prim_Solver();
    }

};

