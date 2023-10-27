#include <iostream>
#include "Dir.h"

Direction IntToDirection(int num)
{
    switch (num) {
    case 0: return Direction::North;
    case 1: return Direction::South;
    case 2: return Direction::West;
    case 3: return Direction::East;
    default: std::cerr << "Invalid Direction" << std::endl;
    }

    //Just to avoid warnings: Control reaches end of function
    return Direction::North;
}

Direction InvertDirection(Direction dir)
{
    if(dir == Direction::North)
        return Direction::South;
    else if (dir == Direction::South)
        return Direction::North;
    else if (dir == Direction::East)
        return Direction::West;
    else
        return Direction::East;
}
