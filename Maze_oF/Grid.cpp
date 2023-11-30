#include <iostream>
#include "Grid.h"

void Grid::DebugDisplay(){
    for(int r = 0; r < sz.get_Total_Rows(); r++){
        for(int c = 0; c < sz.get_Total_Cols(); c++){
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
    masked_cells_.insert(HashCell(cell, sz.get_Total_Cols()));
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
    for(int r = 0; r < sz.get_Total_Rows(); r++){
        for(int c = 0; c < sz.get_Total_Cols(); c++){
            auto* cell = cells[r][c];
            Unmask(r , c);
            cell->UnlinkCell(Direction::North);
            cell->UnlinkCell(Direction::South);
            cell->UnlinkCell(Direction::East);
            cell->UnlinkCell(Direction::West);
        }
    }
}

void Grid::Reinitialize() {
    cells.clear();
    cells.resize(sz.get_Total_Rows(), std::vector<Cell*>(sz.get_Total_Cols(), nullptr));

    for (int r = 0; r < sz.get_Total_Rows(); r++) {
        for (int c = 0; c < sz.get_Total_Cols(); c++) {
            // grid creation
            cells[r][c] = new Cell(r, c);
        }
    }
    // assigning cardinal directions to cells "configuring cells"
    Reset();
}

void Grid::init_Weights() {
    for (int r = 0; r < sz.get_Total_Rows(); r++) {
        for (int c = 0; c < sz.get_Total_Cols(); c++) {
            Cell* current_cell = cells[r][c];
            if (current_cell == nullptr) {
                continue;
            }
            auto neighbors = current_cell->GetNeighbors();
            for (Cell* neighbor : neighbors) {
                if (neighbor == nullptr) {
                    continue;
                }//INT_MAX as sentinel value
                adjacencyList[{current_cell, neighbor}] = INT_MAX;
            }
        }
    }
}

// Creating random weight for grid 
void Grid::set_Rnd_Edges() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 3);

    for (int r = 0; r < sz.get_Total_Rows(); r++) {
        for (int c = 0; c < sz.get_Total_Cols(); c++) {
            Cell* current_cell = cells[r][c];
            if (current_cell == nullptr) {
                continue;
            }
            auto neighbors = current_cell->GetNeighbors();
            for (Cell* neighbor : neighbors) {
                if (neighbor == nullptr) {
                    continue;
                }//avoid over-writing edges between pairs of vertices u,v and v,u
                if (adjacencyList[{current_cell, neighbor}] == INT_MAX && adjacencyList[{neighbor, current_cell}] == INT_MAX) {
                    int rnd_weight = distr(gen);
                    adjacencyList[{current_cell, neighbor}] = rnd_weight;
                    adjacencyList[{neighbor, current_cell}] = rnd_weight;
                }
            }

        }
    }
}

int Grid::get_Weight(Cell* cell1, Cell* cell2) {
    int weight = INT_MAX;
    // To search for an edge from cell1 to cell2
    auto it = adjacencyList.find({ cell1, cell2 });

    if (it != adjacencyList.end()) {
        // Edge from cell1 to cell2 exists, its weight is stored in it->second
        weight = it->second;
        //std::cout << "Weight of edge from cell1 to cell2: " << weight << std::endl;
    }
    else {
        weight = INT_MAX;
        //std::cout << "Edge from cell1 to cell2 does not existRaspbery" << std::endl;    
    }
    return weight;
}

void Grid::printAdjacencyList() {
    for (const auto& entry : adjacencyList) {
        const auto& key = entry.first;  // std::pair<Cell*, Cell*> 
        const auto& value = entry.second;  // int

        std::cout << "(" << key.first->row << "," << key.first->col << ") -> "
            << "(" << key.second->row << "," << key.second->col << ") : "
            << value << std::endl;
    }
}

Grid::~Grid() {
    for (auto& row : cells) {
        for (auto cell : row) {
            cout << "deleting cell" << endl;
            delete cell;
        }
    }
}