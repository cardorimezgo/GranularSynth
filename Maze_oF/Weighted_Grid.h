#pragma once
#include <random>
#include "Grid.h"

class Weighted_Grid : public Grid{

public:
    std::unordered_map<std::pair<Cell* , Cell*>, int , hash_Cell_Ptr> adjacencyList;

    Weighted_Grid(int rows_, int cols_, int margin_, int cell_sz_) : 
    Grid(rows_, cols_, margin_, cell_sz_){        
        init_Weights();
        //set_Rnd_Edge(); ACTIVATE AFTER RUNNING TESTS
    }

    void init_Weights();

    int get_Weight(Cell* cell1, Cell* cell2);

    void SetWeight (int row1, int col1, int row2, int col2, int weight);
    
    
    //set random weights for edges between cells
    void set_Rnd_Edge();

    
    
    /*
    //set weight based on audio data
    bool audio_Weight(Cell* cell);
    */

    void printAdjacencyList();
};


