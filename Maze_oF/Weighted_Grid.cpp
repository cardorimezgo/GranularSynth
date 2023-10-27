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
                }//INT_MAX as sentinel value
                adjacencyList[{current_cell , neighbor}] = INT_MAX;
            }
        }
    }        
}

// Creating random weight for grid 
void Weighted_Grid::set_Rnd_Edges(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0 , 3);
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            Cell* current_cell = cells[r][c];
            if(current_cell == nullptr){
                continue;
            }
            auto neighbors = current_cell->GetNeighbors();
            for(Cell* neighbor : neighbors){
                if(neighbor == nullptr){
                    continue;
                }//avoid over-writing edges between pairs of vertices u,v and v,u
                if(adjacencyList[{current_cell , neighbor}] == INT_MAX && adjacencyList[{neighbor , current_cell}] == INT_MAX){
                    int rnd_weight = distr(gen);
                    adjacencyList[{current_cell , neighbor}] = rnd_weight;
                    adjacencyList[{neighbor , current_cell}] = rnd_weight;
                }
            }

        }
    }
}

int Weighted_Grid::get_Weight(Cell* cell1 , Cell* cell2){
    int weight = INT_MAX;
    // To search for an edge from cell1 to cell2
    auto it = adjacencyList.find({cell1, cell2});

    if (it != adjacencyList.end()) {
    // Edge from cell1 to cell2 exists, its weight is stored in it->second
        weight = it->second;
        //std::cout << "Weight of edge from cell1 to cell2: " << weight << std::endl;
    } else {
        weight = INT_MAX;
        //std::cout << "Edge from cell1 to cell2 does not existRaspbery" << std::endl;    
    }
    return weight;
}

void Weighted_Grid::printAdjacencyList() {
    for (const auto& entry : adjacencyList) {
        const auto& key = entry.first;  // std::pair<Cell*, Cell*> 
        const auto& value = entry.second;  // int

        std::cout << "(" << key.first->row << "," << key.first->col << ") -> "
                  << "(" << key.second->row << "," << key.second->col << ") : "
                  << value << std::endl;
    }
}

