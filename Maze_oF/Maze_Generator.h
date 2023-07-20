#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include "Grid.h"
#include <random>

class MazeGenerator{
public:
    Grid& maze_;
    std::mt19937 rng_;
    std::string name_;

    MazeGenerator(Grid& maze, std::string name):
        maze_(maze), rng_((std::random_device())()), name_(name)
    {}

    const std::string& GetName(){
        return name_;
    }

    virtual void Generate() = 0;
};


#endif // MAZE_GENERATOR_H
