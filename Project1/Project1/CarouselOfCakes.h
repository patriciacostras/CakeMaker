#pragma once
//#ifndef CAROUSELOFCAKES_H_INCLUDED
#define CAROUSELOFCAKES_H_INCLUDED
#include "Cake.h"
#include <iostream>
#include <vector>
using namespace std;

class CarouselOfCakes
{
public:

	vector <Cake> storage;
	vector <Cake> list;

	int newQuantity;
	int difQuantity;
	int arrayEnd = 0;
	unsigned int maxCapacity = 10;
	unsigned int lowLimit = 3;

	CarouselOfCakes();
	void addCake(vector <Cake> &s, Cake item);
	int getCurrentCapacity();
	virtual void showProductsInCarousel();
	void UpdateQuantity(string itemName, int itemQuantity);
	int refillCarousel(string itemName);
	bool checkCarouselOfCakes(string itemName, int itemQuantity);
	bool checkNames(string itemName);
};
//#endif // CAROUSELOFCAKES_H_INCLUDED