#pragma once
#pragma once
//#ifndef CAKE_H_INCLUDED
#define CAKE_H_INCLUDED
#include <iostream>
using namespace std;

class Cake
{
public:
	string nume;
	int quantity;

	Cake();
	Cake(string nu, int q);
	void setNume(string nu);
	string getNume();
	void setQuantity(int q);
	int getQuantity();
};
//#endif // CAKE_H_INCLUDED