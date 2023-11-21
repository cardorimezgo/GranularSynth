#pragma once

#include "Maze_Generator.h"
//#include "Weighted_Grid.h"
#include <random>
#include <vector>
#include <map>


class Prim: public MazeGenerator{
    //Weighted_Grid& w_grid_;

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

    void Prim_Solver(int rnd_row , int rnd_col){

        if(maze_.IsInvalid(rnd_row , rnd_col)) 
            return;

        auto* const origin = maze_.Get_Cell(rnd_row , rnd_col);
        auto current_cell = origin;
        int distance = 0;//0 distance to origin cell
        minHeap.push({origin , distance}); //adding origin cell to pq
        dist[rnd_row][rnd_col] = distance; 
        int num_Fin = 0;
        
        while(!minHeap.empty() && num_Fin != maze_.Total_Cells()){ 
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
                    int weight = maze_.get_Weight(current_cell , neighbor);
                    
                    if(weight == INT_MAX) 
                        continue; // There is no edge
                        
                    // Adding and updating distance values                    
                    if(weight < dist[neighbor->row][neighbor->col]){
                        dist[neighbor->row][neighbor->col] = weight;
                        current_cell->LinkCell(neighbor);   // Creating Link between Cells
                        minHeap.push({neighbor , weight}); // Inserting neighbor into minHeap
                    }
                }
            }
        }
    }
    
    void Init_Dist(){
        for(int r = 0; r < maze_.GetNumRows(); r++){
            for(int c = 0; c < maze_.GetNumCols(); c++){
                dist[r][c] = INT_MAX;
            }
        }
    }

    void Init_Final(){
        for(int r = 0; r < maze_.GetNumRows(); r++){
            for(int c = 0; c < maze_.GetNumCols(); c++){
                finalized[r][c] = false;
            }
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////////

public:

    Prim (Grid& maze):
    MazeGenerator(maze),
    dist(maze_.GetNumRows() , std::vector<int>(maze_.GetNumCols(), INT_MAX)),
    finalized(maze_.GetNumRows() , std::vector<bool>(maze_.GetNumCols(), false))
    {}    

    void Reset(){
        // Initialize all finalized values to false
        Init_Final();
        // Initialize all distance values to INT_MAX
        Init_Dist();
        //Clearing Priority Queue
        minHeap = std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare>();
        // Setting Random weight values to grid 
        //maze_.set_Rnd_Edges();
    }

    void Generate(int row , int col) override{
        maze_.init_Weights(); 
        maze_.set_Rnd_Edges();
        Prim_Solver(row , col);
    }

    void Gen_Rnd_Cell(int& random_row, int& random_col) {
        std::uniform_int_distribution<int> rows_rnd(0, maze_.GetNumRows() - 1); //rows
        std::uniform_int_distribution<int> cols_rnd(0, maze_.GetNumCols() - 1); //cols
        random_row = rows_rnd(rng_);
        random_col = cols_rnd(rng_);
    }



};

