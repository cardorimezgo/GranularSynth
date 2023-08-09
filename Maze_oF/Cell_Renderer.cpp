#include "Cell_Renderer.h"

void  Cell_Renderer::Draw_Walls(){

    if(!needsRedraw)return;

    for(int r = grid.GetNumRows() - 1; r >= 0; r--){
        for(int c = 0; c < grid.GetNumCols(); c++){
             Cell* cell = grid.GetCell(r , c);

             // Calculating coordinates
             float x1 = grid.GetMargin() + (cell->row * grid.GetCell_Sz());
             float y1 = grid.GetMargin() + (cell->col * grid.GetCell_Sz());
             float x2 = grid.GetMargin() + ((cell->row + 1) * grid.GetCell_Sz());
             float y2 = grid.GetMargin() + ((cell->col + 1) * grid.GetCell_Sz());

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

void Cell_Renderer::Draw_Rects(){
    vector<pair<int , pair<int , int>>> sorted = dj.Sort_Distance();
    for(const auto& entry : sorted){

        int color = entry.first;
        int row = entry.second.first;
        int col = entry.second.second;

        float x1 = grid.GetMargin() + (row * grid.GetCell_Sz());
        float y1 = grid.GetMargin() + (col * grid.GetCell_Sz());

        // Intensity color of each cell
        ofSetColor(3*color, 3*color, 3*color, 200);
        //std::cout << std::setw(2) << color << " ";
        ofDrawRectangle(x1 , y1, grid.GetCell_Sz(), grid.GetCell_Sz());

    }
}

void Cell_Renderer::Anima_Maze(int cnt){
    ofSetColor(0,0,0,200);
    ofDrawCircle(20, cnt, 50);
}


//TODO:
// find out how to integrate color gradient add-on
// implementation of ofxColorMap to differentiate distances between cells
