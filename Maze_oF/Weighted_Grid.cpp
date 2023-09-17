#include "Weighted_Grid.h"


bool Weighted_Grid::SetWeight(int row1, int col1, int row2, int col2, int weight){
    if(IsInvalid(row1 , col1) || IsInvalid(row2 , col2)){
            return;
        }
    Cell* cell1 = cells[row1][col1];
    Cell* cell2 = cells[row2][col2];

    adjacencyList[{cell1 , cell2}] = weight;
}

