#include "RecipeCake.h"

RecipeCake::RecipeCake()
{};

RecipeCake::RecipeCake(string n, int t)
{
	this->name = n;
	this->time = t;
};

void RecipeCake::setName(string n)
{
	name = n;
}
string RecipeCake::getName()
{
	return name;
};

void RecipeCake::setTime(int t)
{
	time = t;
}
int RecipeCake::getTime()
{
	return time;
};