#include "Maze_Sz.h"

void set_Grid_Sz(int num) {
	switch (num) {
	case '1':
		rows_sz = 6;
		col_sz = 10;
		cell_sz = 80;
		break;
	case '2':
		rows_sz = 15;
		col_sz = 25;
		cell_sz = 32;
		break;
	case '3':
		rows_sz = 30;
		col_sz = 50;
		cell_sz = 16;
		break;
	case '4':
		rows_sz = 60;
		col_sz = 100;
		cell_sz = 8;
		break;
		}
}