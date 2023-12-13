#include "Maze_Sz.h"
#include <iostream>

bool Maze_Sz::set_Maze_Sz(int num) {
	bool chose = false;

	switch (num) {
	case '1':
		rows_sz = 6;
		cols_sz = 10;
		cell_sz = 80;
		break;
	case '2':
		rows_sz = 15;
		cols_sz = 25;
		cell_sz = 32;
		break;
	case '3':
		rows_sz = 30;
		cols_sz = 50;
		cell_sz = 16;
		break;
	case '4':
		rows_sz = 60;
		cols_sz = 100;
		cell_sz = 8;
		break;
	case '0':		//Debugging
		rows_sz = 3;
		cols_sz = 3;
		cell_sz = 80;
		break;
	default:
		return false; // wrong key entered
	}
	std::cout << "maze size selected: " << num << std::endl;
	return true;
}

int Maze_Sz::get_Total_Cells() {
	return get_Total_Cols() * get_Total_Rows();
}


int Maze_Sz::get_Total_Rows() {
	return rows_sz;
}

int Maze_Sz::get_Total_Cols() {
	return cols_sz;
}

int Maze_Sz::get_Margin() {
	return margin;
}

int Maze_Sz::get_Cell_Sz() {
	return cell_sz;
}