#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include "Grid.h"
#include <random>

class MazeGenerator{
public:
    Grid& maze_;
    std::mt19937 rng_;
    std::string name_;

    MazeGenerator(Grid& maze):
    maze_(maze), rng_((std::random_device())())
    {}

    virtual ~MazeGenerator() {} //Virtual destructor

    virtual void Generate(int row , int col) = 0;

    virtual void Gen_Rnd_Cell(int& random_row, int& random_col) {}

    virtual void Clear_Gen_DS(){}
};


#endif // MAZE_GENERATOR_H
