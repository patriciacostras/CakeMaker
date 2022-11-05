#include "CommandTaker.h"
#include <iostream>
#include <vector>
using namespace std;

CommandTaker::CommandTaker()
{

}

void CommandTaker::takeCommand(vector <RecipeCake> &tc, RecipeCake item)
{
	carouselRecipe.push_back(item);
}

void CommandTaker::takeCommand(vector <Cake> &tc, Cake item)
{
	carousel.push_back(item);
}

void CommandTaker::takeCommand(vector <RecipeCake> &tc, RecipeCake item, int nrOfCakes)
{
	for (unsigned int i = 0; i <= nrOfCakes; i++)
		carouselRecipe.push_back(item);
}