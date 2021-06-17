#pragma once
#include <string>

struct Athlete
{
	std::string name;
	double height;
	double weight;
};

bool LessWeight(const Athlete& left, const Athlete& right)
{
	return (left.weight < right.weight);
}

bool LessHeight(const Athlete& left, const Athlete& right)
{
	return (left.height < right.height);
}