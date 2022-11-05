#include "CakeMaker.h"
#include "RecipeCake.h"
#include "Cake.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

CakeMaker::CakeMaker()
{

}

void CakeMaker::takeCommand(vector <RecipeCake> &tc, RecipeCake item)
{
	cm1.push_back(item);//pune in vector prajiturile ce sunt comandate
}

void CakeMaker::takeCommand(vector <Cake> &tc, Cake item)
{
	cm2.push_back(item);//pune in vector prajiturile ce trebuie realizare pentru a umple storage-ul la capacitate maxima
}

void CakeMaker::showProductsInCakeMaker()
{
	while(!cm2.empty())
   {
	   // get the top of the stack
		Cake c= cm2.back();
	   // remove the top of the stack
		cm2.pop_back();//extrage o prajitura din vector

		cout << c.getNume() << endl;//se afiseaza numele prajiturii ce trebuie realizata de cofetar
   }
}