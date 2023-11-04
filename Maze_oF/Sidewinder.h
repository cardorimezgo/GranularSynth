#pragma once
// start south west corner
// use of random function from Maze_Generator class
// random function alternate between two functions: 
// 1) carve east: link eastern neighbor
// 2) chose one of the group of cells to carve north
// each eastern cell that is carved should be stored in a group
// from the group of carved cells we randomly chose one and link north
// once we carved north on one of the grouped cells, we move east to the next cell (without carving east)
// cotinue the same process  
// when arriving to the east boundary of the grid, close the group of cells visited (even if its one) and link north
// go up the next row and repeat the same process
// When arriving to the top row, the option of linking north is deactivated, we can only link east (which will give us an open row corridor)
// every cell must be visited once 