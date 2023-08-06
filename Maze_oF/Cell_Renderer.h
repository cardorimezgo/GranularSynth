#ifndef CELL_RENDERER_H
#define CELL_RENDERER_H

#include "Maze_Generator.h"
#include "Binary_Tree.h"
#include "Dijkstra.h"
#include "Grid.h"

class Cell_Renderer{
    Grid& grid;
    DijkstraSolver& dj;

    // Flag for drawing Grid
    bool needsRedraw = true;

public:
    Cell_Renderer(Grid& g , DijkstraSolver& d) : grid(g),
                                                 dj(d)
                                                 {}
    // Draw walls and rectangles, set colors for each cell
    void Display();
};


#endif // CELL_RENDERER_H
