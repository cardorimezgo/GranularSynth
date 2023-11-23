#pragma once
#include <random>
#include "Grid.h"

class Weighted_Grid : public Grid{
//////////////////////na mas a ver que
public:
    std::unordered_map<std::pair<Cell* , Cell*>, int , hash_Cell_Ptr> adjacencyList;

    Weighted_Grid(int rows_, int cols_, int margin_, int cell_sz_) : 
    Grid(rows_, cols_, margin_, cell_sz_){        
        //init_Weights(); //EACH MAZE ALGO INITIALIZES WEIGHT VALUES DEPENDING ON NEEDS
        //set_Rnd_Edge(); //ACTIVATE AFTER RUNNING TESTS??
    }

    //Set all the weights to a given value
    void init_Weights();

    //Get the weight between two vertices
    int get_Weight(Cell* cell1, Cell* cell2);
    
    //Set all Edges to a random value
    void set_Rnd_Edges();
    
    //Print all edges for debugging purpose
    void printAdjacencyList();

    Cell* Get_Cell(int r, int c){
        return cells[r][c];
    }

    /*
    //set weight based on audio data
    bool audio_Weight(Cell* cell);
    */    
};


