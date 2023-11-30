#ifndef GRID_H
#define GRID_H

#include "ofMain.h"
#include "Cell.h"
#include "Maze_Sz.h"
#include <unordered_set>
#include <vector>

class Grid{
    Maze_Sz& sz;

protected:
    //2D vector storing cells in the grid
    std::vector<std::vector<Cell*>>cells;

    //Stores list of cells masked out
    std::unordered_set<int>masked_cells_;

public:
    Grid(Maze_Sz& sz_):
        sz(sz_),
        cells(sz_.get_Total_Rows(), std::vector<Cell*>(sz_.get_Total_Cols(), nullptr))
    {
        for(int r = 0; r < sz_.get_Total_Rows(); r++){
            for(int c = 0; c < sz_.get_Total_Cols(); c++){
                // grid creation
                cells[r][c]= new Cell(r,c);
            }
        }
        // assigning cardinal directions to cells "configuring cells"
        Reset();
    }

    //Total number of cells in the maze
    int Total_Cells() const{ 
        return sz.get_Total_Cells();
    }
    // returns the number of rows
    int GetNumRows() const{
        return sz.get_Total_Rows();
    }

    // returns the number of cols
    int GetNumCols() const{
        return sz.get_Total_Cols();
    }

    // returns the margin size
    int  GetMargin() const{
        return sz.get_Margin();
    }

    // return size of square cell
    int GetCell_Sz() const{
        return sz.get_Cell_Sz();
    }

    //Returns the number of unmasked cells
    int GetNumCells() const{
        return sz.get_Total_Cols() * sz.get_Total_Rows() - masked_cells_.size();
    }

    Cell* const GetCell(int row, int col) const{
        return cells[row][col];
    }

    //Identifies invalid cells, including those on the outer edge of the maze
    bool IsInvalid(int r, int c){
        if(r >= sz.get_Total_Rows() || r < 0 || c >= sz.get_Total_Cols() || c < 0){
            return true;
        }
        return false;
    }

    //Text based display of cells in the maze
    void DebugDisplay();

    //close the dir side border of the cell at (row , col)
    bool Unlink(int row, int col, Direction dir);

    //open the dir side border of the cell at (row , col)
    bool Link(int row, int col, Direction dir);

    //Mask cell at (row , col) if valid, else return false
    bool Mask(int row, int col);

    //Unmask cell at [row, col] if valid, else return false
    bool Unmask(int row, int col);

    //close all walls of the Grid
    void Reset();

    //clean number of cells and maze structure
    void Reinitialize();


    ////////////////////////////////////////////////////////////
    /////////// SETTING WEIGHTED GRAPH FUNCTIONS

    std::unordered_map<std::pair<Cell*, Cell*>, int, hash_Cell_Ptr> adjacencyList;


    //Set all the weights to a given value
    void init_Weights();

    //Get the weight between two vertices
    int get_Weight(Cell* cell1, Cell* cell2);

    //Set all Edges to a random value
    void set_Rnd_Edges();

    //Print all edges for debugging purpose
    void printAdjacencyList();

    Cell* Get_Cell(int r, int c) {
        return cells[r][c];
    }

    ~Grid(); //Destructor

    /*
    //set weight based on audio data
    bool audio_Weight(Cell* cell);
    */
};

#endif // GRID_H
