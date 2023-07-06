#pragma once
#ifndef DIR_H
#define DIR_H


enum class Direction {
	North,
	South,
	West,
	East
};

Direction IntToDirection(int num);

//creation of custom unordered_map for Direction
//ref: https://marknelson.us/posts/2011/09/03/hash-functions-for-c-unordered-containers.html
struct EnumClassHash
{
	template <typename T>
	std::size_t operator() (T t) const
	{
		return static_cast<std::size_t>(t);
	}
};



#endif //DIR_H
