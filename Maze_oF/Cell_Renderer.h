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

    Cell_Renderer(Grid& maze_):grid(maze_){}///////////////TESTER///////////////////////
     
    void Draw(int frame);
    void DrawTest(int frame, const vector<pair<int, pair<int, int>>>& sorted); ////////TEST
};

#endif // CELL_RENDERER_H
