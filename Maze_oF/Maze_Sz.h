#pragma once

class Maze_Sz {
	int rows_sz;
	int col_sz;
	int margin;
	int cell_sz;

public:
	Maze_Sz(){}

	//evaluate if it would be a good idea to remove this types of getter functions from Grid class
	// which return the same information (Get_Cell_sz, Get_Num_Cols, etc.)
	void set_Grid_Sz(int num);

	int get_Total_Cells();

	int get_Total_Rows();

	int get_Total_Cols();

	int get_Margin();

	int get_cell_Sz();


};
