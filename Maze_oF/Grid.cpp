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

 for(int r = rows - 1; r >= 0; r--){
     for(int c = 0; c < cols; c++){
         Cell* cell = cells[r][c];

         float x1 = margin + (cell->row * cell_sz);
         float y1 = margin + (cell->col * cell_sz);
         float x2 = margin + ((cell->row + 1) * cell_sz);
         float y2 = margin + ((cell->col + 1) * cell_sz);

         Cell* neighborN = cell->GetNeighbor(Direction::North);
         if(neighborN == nullptr || !cell->Linked(neighborN)){
             ofDrawLine(x1, y1, x2, y1);
         }
         Cell* neighborW = cell->GetNeighbor(Direction::West);
         if(neighborW == nullptr || !cell->Linked(neighborW)){
             ofDrawLine(x1, y1, x1, y2);
         }
         Cell* neighborE = cell->GetNeighbor((Direction::East));
         if(neighborE == nullptr || !cell->Linked(neighborE)){
             ofDrawLine(x2, y1, x2, y2);
         }
         Cell* neighborS = cell->GetNeighbor((Direction::South));
         if(neighborS == nullptr || !cell->Linked(neighborS)){
             ofDrawLine(x1, y2, x2, y2);
         }
      }
   }
}

bool Grid::Unlink(int r, int c, Direction dir){
    Cell* cell = cells[r][c];
    return cell->UnlinkCell(dir);
}

bool Grid::Link(int r, int c, Direction dir){
    Cell* cell = cells[r][c];
    return cell->LinkCell(dir);
}

bool Grid::Unmask(int r, int c){
   if(IsInvalid(r, c))
       return false;

    Cell* cell = cells[r][c];

    if(!IsInvalid(r , c - 1))
        cell->AddNeighbor(Direction::North, cells[r][c - 1]);
    if(!IsInvalid(r , c + 1))
        cell->AddNeighbor(Direction::South, cells[r][c + 1]);
    if(!IsInvalid(r + 1 , c))
        cell->AddNeighbor(Direction::East, cells[r + 1][c]);
    if(!IsInvalid(r - 1 , c))
        cell->AddNeighbor(Direction::West, cells[r - 1][c]);
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
