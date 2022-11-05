#pragma once
//#ifndef COMMANDPANEL_H_INCLUDED
#define COMMANDPANEL_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "RecipeCake.h"

using namespace std;

class CommandPanel
{
public:
	vector <RecipeCake> rcakeItems;//pentru prajituri ce se pot comanda
	vector <RecipeCake> list;//pentru comanda unei persoane

	void selectProduct(vector <RecipeCake> &r, RecipeCake item);
	void selectProduct(vector <RecipeCake> &r, RecipeCake item, int nrOfProducts);
	void showProducts();
	bool checkNames(string itemName);
};
//#endif // COMMANDPANEL_H_INCLUDED