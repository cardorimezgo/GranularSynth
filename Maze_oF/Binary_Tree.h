#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Maze_Generator.h"
#include <iostream>

class BinaryTreeGenerator: public MazeGenerator{
public:
    BinaryTreeGenerator(Grid& maze): MazeGenerator(maze, "BinaryTree")
    {}

    void Generate() override{
        //Generate Random integers from the set (1 , 2)
        std::uniform_int_distribution<int> dist2(1,2);

        for(int rows = 0; rows < maze_.GetNumRows(); rows++){
            for(int cols = 0; cols < maze_.GetNumCols(); cols++){
                int rand_int = dist2(rng_);

            //Open north wall if possible else east
            if(rand_int == 1){
                if(!maze_.Link(rows, cols, Direction::North))
                    maze_.Link(rows, cols, Direction::East);
            }else{
                if(!maze_.Link(rows, cols, Direction::East))
                    maze_.Link(rows, cols, Direction::North);
            }
         }
      }
    }
};

#endif // BINARY_TREE_H
