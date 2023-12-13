#pragma once

class Maze_Sz {
	int rows_sz;
	int cols_sz;
	int margin;
	int cell_sz;

public:
	Maze_Sz():
	rows_sz(30),//30
	cols_sz(50),//50
	cell_sz(16),//16
	margin(0)
	{}

	bool set_Maze_Sz(int num);

	int get_Total_Cells();

	int get_Total_Rows();

	int get_Total_Cols();

	int get_Margin();

	int get_Cell_Sz();
};
