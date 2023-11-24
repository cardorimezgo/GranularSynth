#include "Cell_Renderer.h"

//Create flag for redrawing the maze (needsRedraw)

void Cell_Renderer::Draw(int frame) {
    const auto& sorted = m_solver->Get_Flat_DS();
    //m_solver->printGridFlat();////////////////////////
    if (frame <= sorted.size()) {
        int color = sorted[frame].first;
        int row = sorted[frame].second.first;
        int col = sorted[frame].second.second;

        float x1 = grid.GetMargin() + (col * grid.GetCell_Sz());
        float y1 = grid.GetMargin() + (row * grid.GetCell_Sz());
        float x2 = grid.GetMargin() + ((col + 1) * grid.GetCell_Sz());
        float y2 = grid.GetMargin() + ((row + 1) * grid.GetCell_Sz());
        
        // Intensity color of each cell //Filling Cells
        ofSetColor(0.5 * color, 0.5 * color, 0.5 * color, 220);
        ofDrawRectangle(x1, y1, grid.GetCell_Sz(), grid.GetCell_Sz());

        //Drawing Walls
        Cell* cell = grid.GetCell(row, col);

        Cell* neighborN = cell->GetNeighbor(Direction::North);
        if (neighborN == nullptr || !cell->Linked(neighborN)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x1, y1, x2, y1);
        }
        Cell* neighborW = cell->GetNeighbor(Direction::West);
        if (neighborW == nullptr || !cell->Linked(neighborW)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x1, y1, x1, y2);
        }
        Cell* neighborE = cell->GetNeighbor((Direction::East));
        if (neighborE == nullptr || !cell->Linked(neighborE)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x2, y1, x2, y2);
        }
        Cell* neighborS = cell->GetNeighbor((Direction::South));
        if (neighborS == nullptr || !cell->Linked(neighborS)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x1, y2, x2, y2);
        }
    }
    else {
        ofLog() << "Frame index out of bounds" << frame;
    }
}    

void Cell_Renderer::DrawTest(int frame, const vector<pair<int, pair<int, int>>>& sorted) {
    
    
    if (frame <= sorted.size()) {
        int color = sorted[frame].first;
        int row = sorted[frame].second.first;
        int col = sorted[frame].second.second;

        float x1 = grid.GetMargin() + (col * grid.GetCell_Sz());
        float y1 = grid.GetMargin() + (row * grid.GetCell_Sz());
        float x2 = grid.GetMargin() + ((col + 1) * grid.GetCell_Sz());
        float y2 = grid.GetMargin() + ((row + 1) * grid.GetCell_Sz());

        // Intensity color of each cell //Filling Cells
        ofSetColor(0.5 * color, 0.5 * color, 0.5 * color, 220);
        ofDrawRectangle(x1, y1, grid.GetCell_Sz(), grid.GetCell_Sz());

        //Drawing Walls
        Cell* cell = grid.GetCell(row, col);

        Cell* neighborN = cell->GetNeighbor(Direction::North);
        if (neighborN == nullptr || !cell->Linked(neighborN)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x1, y1, x2, y1);
        }
        Cell* neighborW = cell->GetNeighbor(Direction::West);
        if (neighborW == nullptr || !cell->Linked(neighborW)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x1, y1, x1, y2);
        }
        Cell* neighborE = cell->GetNeighbor((Direction::East));
        if (neighborE == nullptr || !cell->Linked(neighborE)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x2, y1, x2, y2);
        }
        Cell* neighborS = cell->GetNeighbor((Direction::South));
        if (neighborS == nullptr || !cell->Linked(neighborS)) {
            ofSetColor(255, 255, 255, 100);
            ofDrawLine(x1, y2, x2, y2);
        }
    }
    else {
        ofLog() << "Frame index out of bounds" << frame;
    }
}



