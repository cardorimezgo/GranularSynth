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
 int margin = 20; // create constant value
 int cell_sz = 10; // create constant value
 for(int r = rows - 1; r >= 0; r--){
     for(int c = 0; c < cols; c++){
         Cell* cell = cells[r][c];
         float x1 = margin + (cell->row * cell_sz);
         float y1 = margin + (cell->col + cell_sz);
         float x2 = margin + ((cell->row + 1) * cell_sz);
         float y2 = margin + ((cell->col + 1) * cell_sz);
         /////////////////////
     }
 }
}


/*
void Grid::Display(){
    int gap= 20;
    for(int r = rows - 1; r >= 0; r--){
        //Print North wall
        for(int c = 0; c < cols; c++){
            Cell* cell = cells[r][c];
            Cell* neighbor = cell->GetNeighbor(Direction::North);

            //If neighbor does not exist or is bloqued of, display wall
            if(neighbor == nullptr || !cell->Linked(neighbor)){
                ofDrawLine(gap+15, gap, gap+30, gap); //oF line
            }
            else{
            }
        }
        //Print west wall
        for(int c = 0; c < cols; c++){
            Cell* cell = cells[r][c];
            Cell* neighbor = cell->GetNeighbor(Direction::West);
            //If neighbor does not exist or is bloqued of, display wall
            if(neighbor == nullptr || !cell->Linked(neighbor));
        }
}
}
*/

bool Grid::Unmask(int r, int c){
   if(IsInvalid(r, c))
       return false;

    Cell* cell = cells[r][c];
    if(!IsInvalid(r+1 , c))
        cell->AddNeighbor(Direction::North, cells[r + 1][c]);
    if(!IsInvalid(r-1 , c))
        cell->AddNeighbor(Direction::South, cells[r - 1][c]);
    if(!IsInvalid(r , c+1))
        cell->AddNeighbor(Direction::East, cells[r][c + 1]);
    if(!IsInvalid(r , c-1))
        cell->AddNeighbor(Direction::West, cells[r][c - 1]);
   return true;
}

void Grid::Reset(){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            auto* cell = cells[r][c];
            Unmask(r , c);
            cell->UnlinkCell(Direction::North);
            cell->UnlinkCell(Direction::South);
            cell->UnlinkCell(Direction::East);
            cell->UnlinkCell(Direction::West);
        }
    }
}

//bool Grid::

//bool Grid::Mask(int r, int c){

//}
