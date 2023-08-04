#include "Cell_Renderer.h"

void  Cell_Renderer::Display(){

 for(int r = draw_maze.GetNumRows() - 1; r >= 0; r--){
     for(int c = 0; c < draw_maze.GetNumCols(); c++){
         Cell* cell = draw_maze.GetCell(r , c);

         float x1 = marg + (cell->row * cell_sz);
         float y1 = marg + (cell->col * cell_sz);
         float x2 = marg + ((cell->row + 1) * cell_sz);
         float y2 = marg + ((cell->col + 1) * cell_sz);

         // Intensity color of each cell
         int color = dj.GetDistance(r , c);
         ofSetColor(3*color, 3*color, 3*color, 200);

         // Draw rectangles
         //rects[r][c] = ofRectangle(x1, y1, CELL_SZ, CELL_SZ);
         ofDrawRectangle(x1, y1, cell_sz, cell_sz);

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
}

//TODO:
// find out how to integrate color gradient add-on
// implementation of ofxColorMap to differentiate distances between cells