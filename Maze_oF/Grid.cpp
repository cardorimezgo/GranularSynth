#include <iostream>
#include "Grid.h"


void Grid::DebugDisplay(){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cells[r][c]->PrintCell();
        }
    }
}

void Grid::Display(){
    int gap= 20;
    for(int r = rows - 1; r >= 0; r--){
        //Print North wall
        for(int c = 0; c < cols; c++){
            Cell* cell = cells[r][c];
            Cell* neighbor = cell->GetNeighbor(Direction::North);
            ofDrawLine(gap+15, gap, gap+30, gap);
        }
}
}


//bool Grid::

//bool Grid::Mask(int r, int c){

//}
