#include "Cake.h"
#include "CarouselOfCakes.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

CarouselOfCakes::CarouselOfCakes()
{

}

void CarouselOfCakes::addCake(vector <Cake> &s, Cake item)//adauga o prajitura in cofetarie/ adauga o prajitura pentru a fi vanduta
{
	storage.push_back(item);
	arrayEnd++;
}

int CarouselOfCakes::getCurrentCapacity()//returneaza numarul de elemente/prajituri din vectorul storage
{
	return arrayEnd;
}

void CarouselOfCakes::showProductsInCarousel()//afiseaza produsele din cofetarie/ afiseaza prajituile cumparate de o persoana
{
	for (unsigned int i = 0; i < storage.size(); i++)
	{
		cout << storage.at(i).getNume() << " " << storage.at(i).getQuantity() << endl;
	}
}

void CarouselOfCakes::UpdateQuantity(string itemName, int itemQuantity)//updateaza storage-ul prin scaderea din total a numarului de prajituri cumparate
{

	for (int i = 0; i < storage.size(); i++)//se parcurge vectorul cu prajituri 
	{
		if (this->storage.at(i).getNume() == itemName)//daca gaseste prajitura ce a fost comandata
		{
			int newQuantity = storage.at(i).getQuantity() - itemQuantity;//se scade numarul de bucati cumparate
			storage.at(i).setQuantity(newQuantity);
			return;
		}
		//storage.at(i) <=> storage[i]
	}
	cout << endl << "Acest produs nu se afla in stoc!" << endl;
}

int CarouselOfCakes::refillCarousel(string itemName)//updateaza storage-ul prin adunarea la total a numarului de prajituri cumparate + diferenta pana la maxCapacity=10
{
	for (int i = 0; i < storage.size(); i++)//cauta prajitura in vector
	{
		if (this->storage.at(i).getNume() == itemName)//daca o gaseste
		{
			difQuantity = maxCapacity - storage.at(i).getQuantity();//calculeaza diferenta pana la maxCapacity
			newQuantity = storage.at(i).getQuantity() + difQuantity;//se adauga la cantitatea existenta in cofetarie diferenta pana la maxCapacity
			storage.at(i).setQuantity(newQuantity);//se seteaza noua cantitate
		}
	}
	return difQuantity;//sa stie cofetarul cate prajituri trebuie sa faca
}

bool CarouselOfCakes::checkCarouselOfCakes(string itemName, int itemQuantity)//verifica numarul de prajituri de pe stoc, deoarece daca sunt mai putine de 3 nu se poate face vanzarea
{
	for (int i = 0; i < storage.size(); i++)//parcurge prajiturile din vector

		if ((this->storage.at(i).getNume() == itemName) && ((this->storage.at(i).getQuantity() <= lowLimit) || (this->storage.at(i).getQuantity() - itemQuantity) <= lowLimit))
		//nu se poate face vanzarea unei prajituri daca initial sunt mai putin de 3 bucati sau daca prin scaderea cantitatii dorite din totalul existent se ajunge la o valoare < 3
			return false;
		else
			return true;
}

bool CarouselOfCakes::checkNames(string itemName)//verifica numele prajiturii
{
	for (int i = 0; i < storage.size(); i++)

		if ((this->storage.at(i).getNume()) == itemName)
			return true;
		else
			return false;
}