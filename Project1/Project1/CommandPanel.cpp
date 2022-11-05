#include "RecipeCake.h"
#include "CommandPanel.h"

void CommandPanel::selectProduct(vector <RecipeCake> &r, RecipeCake item)//adauga o prajitura in cofetarie pentru a fi comandata/ adauga o prajitura la comanda
{
	rcakeItems.push_back(item);
}
void CommandPanel::selectProduct(vector <RecipeCake> &r, RecipeCake item, int nrOfProducts)
{
	for (unsigned int i = 0; i <= nrOfProducts; i++)
		rcakeItems.push_back(item);
}

void CommandPanel::showProducts()//afiseaza produsele ce pot fi comandate/ afiseaza prajituile comandate de o persoana
{
	for (unsigned int i = 0; i < rcakeItems.size(); i++)
	{
		cout << "Prajitura este " << rcakeItems.at(i).getName();
		cout << " si dureaza " << rcakeItems.at(i).getTime() << " minute, pana cand va fi gata!" << endl;
	}
}
bool CommandPanel::checkNames(string itemName)//verifica numele prajiturii care urmeaza a fi comandata
{
	for (int i = 0; i < rcakeItems.size(); i++)

		if (this->rcakeItems.at(i).getName() == itemName)
			return true;
		else
			return false;
}