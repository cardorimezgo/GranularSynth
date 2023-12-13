#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Maze_Solver.h"
#include <vector>
#include <map>

class Dijkstra : public MazeSolver {
    
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
        if (maze_.IsInvalid(r, c))
            return;

        auto* const origin = maze_.Get_Cell(r, c);
        auto current_cell = origin;
        int distance = 0;//0 distance to origin cell
        minHeap.push({ origin , distance }); //adding origin cell to pq
        flood_fill[r][c] = distance;
        int num_Fin = 0;

        while (!minHeap.empty() && num_Fin != maze_.Total_Cells()) {
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
                    int weight = maze_.get_Weight(current_cell, neighbor);

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
    Dijkstra(Grid& maze_) :
    MazeSolver(maze_),
    finalized(maze_.GetNumRows(), std::vector<bool>(maze_.GetNumCols(), false))
    {
        flood_fill.resize(maze_.GetNumRows(), std::vector<int>(maze_.GetNumCols(), INT_MAX));
    }    

    void Solve(int row , int col) override { 
        Dijkstra_Solver(row, col);
        //Sorting cells for the maze to be rendered 
        flood_fill_sort();
    }

    const std::vector<std::pair<int, std::pair<int, int>>>& Get_Flat_DS() override{
        return grid_flat;
    }

    void Clear_Solve_DS() override{
        MazeSolver::Clear_Solve_DS();
        finalized.clear();
        //Clearing Priority Queue
        std::priority_queue<cell_Dist, std::vector<cell_Dist>, Compare> empty;
        std::swap(minHeap , empty);
    }

};
#endif // DIJKSTRA_H
