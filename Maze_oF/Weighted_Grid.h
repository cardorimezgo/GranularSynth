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

    //Set all the weights to a given value
    void init_Weights();

    //Get the weight between two vertices
    int get_Weight(Cell* cell1, Cell* cell2);

    //Modify weight between two vertices
    void set_Weight(int row1, int col1, int row2, int col2, int weight);
    
    //Set all Edges to a random value
    void set_Rnd_Edge();
    
    //Print all edges for debugging purpose
    void printAdjacencyList();

    /*
    //set weight based on audio data
    bool audio_Weight(Cell* cell);
    */

    
};


