#include "Cell_Renderer.h"

void  Cell_Renderer::Display(){

    if(!needsRedraw)return;

    for(int r = grid.GetNumRows() - 1; r >= 0; r--){
        for(int c = 0; c < grid.GetNumCols(); c++){
             Cell* cell = grid.GetCell(r , c);

             float x1 = grid.GetMargin() + (cell->row * grid.GetCell_Sz());
             float y1 = grid.GetMargin() + (cell->col * grid.GetCell_Sz());
             float x2 = grid.GetMargin() + ((cell->row + 1) * grid.GetCell_Sz());
             float y2 = grid.GetMargin() + ((cell->col + 1) * grid.GetCell_Sz());

             // Intensity color of each cell
             int color = dj.GetDistance(r , c);
             std::cout << std::setw(2) << color << " ";
             ofSetColor(3*color, 3*color, 3*color, 100);

             // Draw rectangles
             ofDrawRectangle(x1, y1, grid.GetCell_Sz(), grid.GetCell_Sz());

             //Draw Walls
             Cell* neighborN = cell->GetNeighbor(Direction::North);
             if(neighborN == nullptr || !cell->Linked(neighborN)){
                 ofDrawLine(x1, y1, x2, y1);
             }
             Cell* neighborW = cell->GetNeighbor(Direction::West);
             if(neighborW == nullptr || !cell->Linked(neighborW)){
                 ofDrawLine(x1, y1, x1, y2);
             }
             Cell* neighborE = cell->GetNeighbor((Direction::East));
             if(neighborE == nullptr || !cell->Linked(neighborE)){
                 ofDrawLine(x2, y1, x2, y2);
             }
             Cell* neighborS = cell->GetNeighbor((Direction::South));
             if(neighborS == nullptr || !cell->Linked(neighborS)){
                 ofDrawLine(x1, y2, x2, y2);
             }
         }
     }
     needsRedraw = false;
}


//TODO:
// find out how to integrate color gradient add-on
// implementation of ofxColorMap to differentiate distances between cells
