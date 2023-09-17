#pragma once
#include "Grid.h"

class Weighted_Grid : public Grid{

public:
    std::unordered_map<std::pair<Cell* , Cell*>, int , hash_Cell_Ptr> adjacencyList;

    Weighted_Grid(int rows_, int cols_, int margin_, int cell_sz_) : Grid(rows_, cols_, margin_, cell_sz_){
        //We need to connect each cell to its neighbors then set edge values
        //Initialized all weights to zero  or data from audio processing     
    }

    bool SetWeight (int row1, int col1, int row2, int col2, int weight);
    
    /*
    //set weight for edge between cells
    bool random_Weight(Cell* cell);

    //set weight based on audio data
    bool audio_Weight(Cell* cell);
    */
};


