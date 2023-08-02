#ifndef CELL_RENDERER_H
#define CELL_RENDERER_H

#include "Maze_Generator.h"
#include "Binary_Tree.h"
#include "Dijkstra.h"
#include "Grid.h"

constexpr auto GRID_DIM_X = 50;
constexpr auto GRID_DIM_Y = 30;
constexpr auto MARG = 0;
constexpr auto CELL_SZ = 16;

class Cell_Renderer{
    Grid draw_maze;
    DijkstraSolver dj;

    //Create a 2D grid of rectangles
    std::vector<std::vector<ofRectangle>> rects;


public:
    Cell_Renderer() : draw_maze(GRID_DIM_X, GRID_DIM_Y, MARG, CELL_SZ),
                      rects(draw_maze.GetNumRows(), std::vector<ofRectangle>(draw_maze.GetNumCols())),
                      dj(draw_maze)
                      {}

    void Display();
};


#endif // CELL_RENDERER_H
