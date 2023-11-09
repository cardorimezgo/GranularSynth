#pragma once

enum class Maze_Algos {
    Binary_Tree,
    Sidewinder,
    Aldous_Broder,
    Wilsons,
    Hunt_and_Kill,
    Recursive_Backtracker,
    Growing_Tree,
    Ellers,
    Prims,
    Kruskals
};

void Setup_Maze(Maze_Algos type);
