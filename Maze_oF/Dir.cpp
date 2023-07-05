#include <iostream>
#include "Dir.h"

Direction IntToDirection(int num) {
	switch (num) {
	case 0: return Direction::North;
	case 1: return Direction::South;
	case 2: return Direction::West;
	case 3: return Direction::East;
	default: std::cerr << "Invalid Direction" << std::endl;
	}
}