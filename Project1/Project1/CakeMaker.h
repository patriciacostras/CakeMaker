#pragma once
//#ifndef CAKEMAKER_H_INCLUDED
#define CAKEMAKER_H_INCLUDED
#include "Cake.h"
#include "RecipeCake.h"
#include <iostream>
#include <vector>
using namespace std;
class CakeMaker
{
public:
	vector <RecipeCake> cm1;//realizeaza prajiturile pe comanda
	vector <Cake> cm2;//realizeaza prajiturile pentru a umple storage-ul
	int count1 = 0;
	CakeMaker();
	void takeCommand(vector <RecipeCake> &tc, RecipeCake item);
	void takeCommand(vector <Cake> &tc, Cake item);
	void showProductsInCakeMaker();
};
//#endif // CAKEMAKER_H_INCLUDED