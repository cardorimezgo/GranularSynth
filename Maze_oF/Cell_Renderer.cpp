#include "Cell_Renderer.h"

void  Cell_Renderer::Display(){

    BinaryTreeGenerator generator(draw_maze);
    generator.Generate();

     DijkstraSolver dj(draw_maze);
     dj.Reset();
     dj.Solve();

 for(int r = draw_maze.GetNumRows() - 1; r >= 0; r--){
     for(int c = 0; c < draw_maze.GetNumCols(); c++){
         Cell* cell = draw_maze.GetCell(r , c);

         float x1 = MARG + (cell->row * CELL_SZ);
         float y1 = MARG + (cell->col * CELL_SZ);
         float x2 = MARG + ((cell->row + 1) * CELL_SZ);
         float y2 = MARG + ((cell->col + 1) * CELL_SZ);

         // Intensity color of each cell
         int color = dj.GetDistance(r , c);
         ofSetColor(3*color, 3*color, 3*color, 200);

         // Draw rectangles
         rects[r][c] = ofRectangle(x1, y1, CELL_SZ, CELL_SZ);
         ofDrawRectangle(rects[r][c]);

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
