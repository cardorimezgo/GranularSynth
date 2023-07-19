#ifndef GRID_H
#define GRID_H

#include "ofMain.h"
#include "Cell.h"
#include <unordered_set>
#include <vector>


class Grid
{
    int rows;
    int cols;

    //2D vector storing cells in the grid
    std::vector<std::vector<Cell*>>cells;

    //Stores list of cells masked out
    //std::unordered_set<int>masked_cells_:

public:
    Grid(int rows_, int cols_) : rows(rows_), cols(cols_),
                                 cells(rows_, std::vector<Cell*>(cols_,nullptr))
    {
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                // grid creation
                cells[r][c]= new Cell(r,c);
            }
        }
        // assigning cardinal directions to cells "configuring cells"
        Reset();
    }

    // returns the number of rows
    int GetNumRows(){
        return rows;
    }

    // returns the number of cols
    int GetNumCols(){
        return cols;
    }

    //Returns the number of unmasked cells
    //int GetNumCells(){
//        return cols * rows - masked_cells_.size();
//    }

    Cell* const GetCell(int row, int col){
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

    void Display();

    //Unmask cell at [row, col] if valid, else return false
    bool Unmask(int row, int col);

    void Reset();

};



#endif // GRID_H
