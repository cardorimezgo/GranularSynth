#pragma once 

#include "Cell_Renderer.h"
#include "Weighted_Grid.h"

class Cell_Renderer_Wt : public Cell_Renderer{

public:

    Cell_Renderer_Wt():
    Cell_Renderer()
    {}

    void Draw(int frame, const Grid& grid, const vector<pair<int, pair<int, int>>>& sorted);
};