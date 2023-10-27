#pragma once

#include <iostream>

enum class Direction {
    North,
    South,
    West,
    East
};

Direction IntToDirection(int num);

Direction InvertDirection(Direction dir);

//creation of custom unordered_map for Direction
//ref: https://marknelson.us/posts/2011/09/03/hash-functions-for-c-unordered-containers.html
struct EnumClassHash{
    template <typename T>
    std::size_t operator() (T t) const
    {
        return static_cast<std::size_t>(t);
    }
};
