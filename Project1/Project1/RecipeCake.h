#pragma once
//#ifndef RECIPECAKE_H_INCLUDED
#define RECIPECAKE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class RecipeCake
{
public:
	string name;
	int time;

	RecipeCake(); //default constructor
	RecipeCake(string n, int t); //constructor
	void setName(string n); //sets Name of an item
	string getName(); //returns Name of an item
	void setTime(int t); //set time of an item
	int getTime(); //returns time to made an item
};
//#endif // RECIPECAKE_H_INCLUDED