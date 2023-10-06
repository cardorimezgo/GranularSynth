#include <iostream>
#include "Grid.h"

void Grid::DebugDisplay(){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cells[r][c]->PrintCell();
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

bool Grid::Mask(int r, int c){
    if(IsInvalid(r , c))
        return false;
    Cell* cell = cells[r][c];
    cell->DeleteNeighbor(Direction::North);
    cell->DeleteNeighbor(Direction::South);
    cell->DeleteNeighbor(Direction::East);
    cell->DeleteNeighbor(Direction::West);
    masked_cells_.insert(HashCell(cell, cols));
    return true;
}

bool Grid::Unmask(int r, int c){
   if(IsInvalid(r, c))
       return false;

    Cell* cell = cells[r][c];
    if(!IsInvalid(r-1 , c))
        cell->AddNeighbor(Direction::North, cells[r-1][c]);
    if(!IsInvalid(r+1 , c))
        cell->AddNeighbor(Direction::South, cells[r+1][c]);
    if(!IsInvalid(r , c+1))
        cell->AddNeighbor(Direction::East, cells[r][c+1]);
    if(!IsInvalid(r , c-1))
        cell->AddNeighbor(Direction::West, cells[r][c-1]);
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
