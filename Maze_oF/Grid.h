#ifndef GRID_H
#define GRID_H

#include "ofMain.h"
#include "Cell.h"
#include <unordered_set>
#include <vector>

class Grid{

protected:
    int rows;
    int cols;
    int margin;
    int cell_sz;

    //2D vector storing cells in the grid
    std::vector<std::vector<Cell*>>cells;

    //Stores list of cells masked out
    std::unordered_set<int>masked_cells_;

public:
    Grid(int rows_, int cols_, int margin_, int cell_sz_):
        rows(rows_), cols(cols_),
        margin(margin_), cell_sz(cell_sz_),
        cells(rows_, std::vector<Cell*>(cols_,nullptr))
    {
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                // grid creation
                cells[r][c]= new Cell(r,c);
            }
        }
        // assigning cardinal directions to cells "configuring cells"
        Reset();
    }

    //Total number of cells in the maze
    int Total_Cells() const{
        return rows * cols; 
    }
    // returns the number of rows
    int GetNumRows() const{
        return rows;
    }

    // returns the number of cols
    int GetNumCols() const{
        return cols;
    }

    // returns the margin size
    int  GetMargin() const{
        return margin;
    }

    // return size of square cell
    int GetCell_Sz() const{
        return cell_sz;
    }

    //Returns the number of unmasked cells
    int GetNumCells() const{
        return cols * rows - masked_cells_.size();
    }

    Cell* const GetCell(int row, int col) const{
        return cells[row][col];
    }

    //Identifies invalid cells, including those on the outer edge of the maze
    bool IsInvalid(int r, int c){
        if(r >= rows || r < 0 || c >= cols || c < 0){
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

    /*
    //set weight based on audio data
    bool audio_Weight(Cell* cell);
    */
};

#endif // GRID_H
