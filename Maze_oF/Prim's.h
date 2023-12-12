#pragma once

#include "Maze_Generator.h"
#include <random>
#include <vector>
#include <map>


class Prim: public MazeGenerator{

// DS for storing cells that have already been processed
std::vector<std::vector<bool>> finalized;
std::priority_queue<Cells_Edge, std::vector<Cells_Edge>, std::greater<> > minHeap;

void Prim_Solver(int rnd_row, int rnd_col) {

    if (maze_.IsInvalid(rnd_row, rnd_col))
        return;

    auto* const origin = maze_.Get_Cell(rnd_row, rnd_col);
    auto current_cell = origin;
    int num_Fin = 1;

    finalized[current_cell->row][current_cell->col] = true;

    while (num_Fin != maze_.Total_Cells()) { // total number of cells should be visited.
            
        vector<Cells_Edge> cell_wt = maze_.get_Weights(current_cell);

        for (const auto& c_w : cell_wt) { // adding weights to the priority queue
            if (!finalized[c_w.neighbor_c->row][c_w.neighbor_c->col]) {
                minHeap.push(c_w);
            }
        }

        // Least weight value from cell
        Cells_Edge pq_top = minHeap.top(); 
        Cell* neighbor  = pq_top.neighbor_c;
        current_cell = pq_top.current_c;

        if (finalized[current_cell->row][current_cell->col] && finalized[neighbor->row][neighbor->col]) {
            minHeap.pop();
            continue;
        }

        // If the neighbor of the current cell with the lowest weight value is not part of the maze ,link them.
        // check for cell not linked to neighbor (avoid loops)
        // removing root from minHeap when the two cells have been linked
        //Adding cell to finalized list
        if (!finalized[neighbor->row][neighbor->col] && !current_cell->Linked(neighbor)) {
            current_cell->LinkCell(neighbor);
            current_cell = neighbor;
            minHeap.pop();
            finalized[current_cell->row][current_cell->col] = true;
            num_Fin++;
        }
    }
}

public:

    Prim (Grid& maze_):
    MazeGenerator(maze_),
    finalized(maze_.GetNumRows() , std::vector<bool>(maze_.GetNumCols(), false))
    {}    

    void Generate(int row , int col) override{
        maze_.init_Weights(); 
        maze_.set_Rnd_Edges();
        finalized.resize(maze_.GetNumRows(), std::vector<bool>(maze_.GetNumCols(), false));////!!!!!errror
        Prim_Solver(row , col);
    }

    void Gen_Rnd_Cell(int& random_row, int& random_col) {
        std::uniform_int_distribution<int> rows_rnd(0, maze_.GetNumRows() - 1); //rows
        std::uniform_int_distribution<int> cols_rnd(0, maze_.GetNumCols() - 1); //cols
        random_row = rows_rnd(rng_);
        random_col = cols_rnd(rng_);
    }
    
    void Clear_Gen_DS() override {
        MazeGenerator::Clear_Gen_DS();
        finalized.clear();
        //Clearing Priority Queue
        std::priority_queue<Cells_Edge, std::vector<Cells_Edge>, std::greater<> > empty;
        std::swap(minHeap, empty);
    }
    
};

