#ifndef CELL_RENDERER_H
#define CELL_RENDERER_H

#include "Grid.h"

class Cell_Renderer{

    // Flag for drawing/redrawing Grid
    bool needsRedraw = true;

public:

    Cell_Renderer()
    {}
     //parameters:   //animation frame   //weiighted or unweighted grid  //list of ordered vertices or cells
    void Draw(int frame, const Grid& grid, const vector<pair<int, pair<int, int>>>& sorted);
};

#endif // CELL_RENDERER_H
