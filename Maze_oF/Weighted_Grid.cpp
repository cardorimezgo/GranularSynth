#include "Weighted_Grid.h"

void Weighted_Grid::init_Weights(){
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            Cell* current_cell = cells[r][c];
            if(current_cell == nullptr) {
                continue;
            }
            auto neighbors = current_cell->GetNeighbors();
            for(Cell* neighbor : neighbors) {
                if(neighbor == nullptr) {
                    continue;
                }
                adjacencyList[{current_cell , neighbor}] = -1;
            }
        }
    }        
}

void Weighted_Grid::SetWeight(int row1, int col1, int row2, int col2, int weight){
    if(IsInvalid(row1 , col1) || IsInvalid(row2 , col2)){
            return;
        }
    Cell* cell1 = cells[row1][col1];
    Cell* cell2 = cells[row2][col2];

    adjacencyList[{cell1 , cell2}] = weight;
}

void Weighted_Grid::set_Rnd_Edge(){
    //std::random_device rd;
    //std::mt19937 gen(rd());
    //std::uniform_int_distribution<> distr(1 , 5);
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            Cell* current_cell = cells[r][c];
            if(current_cell == nullptr){/////////check
                //std::cout << "current_cell is null. Skipping" << std::endl;
                continue;
            }
            auto neighbors = current_cell->GetNeighbors();
            for(Cell* neighbor : neighbors){
                if(neighbor == nullptr){///////////check
                    //std::cout << "neighbor is null. Skipping" << std::endl;
                    continue;
                }

                //current_cell->PrintCell(true);
                
                //std::cout << "current_cell:" << current_cell << "  neighbor:" << neighbor << std::endl;

                /*
                if(current_cell->row < neighbor->row || current_cell->row < neighbor->row && 
                                                        current_cell->row == neighbor->row){

                    //std::cout << "Setting edge for (" << current_cell->row << ", " << current_cell->col
                             // << ") -> (" << neighbor->row << ", " << neighbor->col << ")." << std::endl;

                    adjacencyList[{current_cell , neighbor}] = 4;//distr(gen); //generating random edge values
                    
                }*/
            }

        }
    }
}

int Weighted_Grid::get_Weight(Cell* cell1 , Cell* cell2){
    // To search for an edge from cell1 to cell2
    auto it = adjacencyList.find({cell1, cell2});
    int weight;

    if (it != adjacencyList.end()) {
    // Edge from cell1 to cell2 exists, its weight is stored in it->second
    weight = it->second;
    std::cout << "Weight of edge from cell1 to cell2: " << weight << std::endl;
    } else {
    // Edge from cell1 to cell2 does not exist
    std::cout << "Edge from cell1 to cell2 does not exist" << std::endl;    
    }
    return weight;
}

void Weighted_Grid::printAdjacencyList() {
    for (const auto& entry : adjacencyList) {
        const auto& key = entry.first;  // std::pair<Cell*, Cell*> 
        const auto& value = entry.second;  // int

        std::cout << "(" << key.first->row << "," << key.first->row << ") -> "
                  << "(" << key.second->col << "," << key.second->col << ") : "
                  << value << std::endl;
    }
}

