#pragma once
//#ifndef COMMANDTAKER_H_INCLUDED
#define COMMANDTAKER_H_INCLUDED
#include "RecipeCake.h"
#include "Cake.h"
#include <iostream>
#include <vector>
using namespace std;
class CommandTaker
{
public:
	vector <RecipeCake> carouselRecipe;
	vector <RecipeCake> list;
	vector <Cake> carousel;
	CommandTaker();
	void takeCommand(vector <RecipeCake> &tc, RecipeCake item);//preia comanda de la CommandPanel pentru prajiturile ce pot fi comandate
	void takeCommand(vector <Cake> &tc, Cake item);//preia comanda de la CarouselOfCakes pentru prajiturile ce pot fi cumparate din stoc
	void takeCommand(vector <RecipeCake> &tc, RecipeCake item, int nrOfCakes);
};
//#endif // COMMANDTAKER_H_INCLUDED