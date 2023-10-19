#include "Cell_Renderer_Wt.h"

void Cell_Renderer_Wt::Draw(int frame, const Grid& grid, const vector<pair<int, pair<int, int>>>& sorted){
        try {
        //Dynamic cast to safely downcast to Weighted_Grid
        const Weighted_Grid& w_grid = dynamic_cast<const Weighted_Grid&>(grid);

    } catch (const std::bad_cast& e) {
        std::cout<<"Cell_Renderer_Wt dynamic_cast error"<<std::endl;
        return;
    }
    }
