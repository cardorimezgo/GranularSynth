#pragma
#include "Cell.h"

struct Weighted_Edge : public Cell{
    int weight;

    //set weight for edge between cells
    void set_Weight(Cell* cell);
};
