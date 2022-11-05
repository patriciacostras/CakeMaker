#include "Cake.h"
using namespace std;

Cake::Cake()//constructor de initializare
{};

Cake::Cake(string nu, int q)
{
	this->nume = nu;
	this->quantity = q;
};
void Cake::setNume(string nu)
{
	nume = nu;
}
string Cake::getNume()
{
	return nume;
};

void Cake::setQuantity(int q)
{
	quantity = q;
}
int Cake::getQuantity()
{
	return quantity;
};