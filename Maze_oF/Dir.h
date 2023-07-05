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


struct EnumClassHash
{
	template <typename T>
	std::size_t operator() (T t) const
	{
		return static_cast<std::size_t>(t);
	}
};
















#endif