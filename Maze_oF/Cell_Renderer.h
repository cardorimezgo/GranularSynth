#ifndef CELL_RENDERER_H
#define CELL_RENDERER_H

#include "Grid.h"
#include "Maze_Solver.h"

class Cell_Renderer{

    Grid& grid;
    MazeSolver* m_solver;

    // Flag for drawing/redrawing Grid
    bool needsRedraw = true;

public:

    Cell_Renderer(Grid& _grid , MazeSolver* _m_solver) : 
        grid(_grid),
        m_solver(_m_solver)
    {}
     
    void Draw(int frame);
};

#endif // CELL_RENDERER_H
