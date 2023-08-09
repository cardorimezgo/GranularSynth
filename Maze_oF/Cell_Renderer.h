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

    Cell_Renderer(Grid& g , DijkstraSolver& d) :
    grid(g),
    dj(d)
    {}

    void Draw_Walls();

    void Draw_Rects();

    void Anima_Maze(int cnt);
};


#endif // CELL_RENDERER_H
