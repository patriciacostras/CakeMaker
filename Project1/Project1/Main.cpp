#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "CommandPanel.h"
#include "CarouselOfCakes.h"
#include "CommandTaker.h"
#include "CakeMaker.h"
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;
CommandPanel shop;//obiect pentru a accesa toate prajiturile ce se pot comanda
CommandPanel rcake;//obiect prntru a accesa toate obiectele comandate de o persoana
CarouselOfCakes shop1;//obiect pentru a accesa prajiturile din storage
CarouselOfCakes cake1;//obiect pentru a accesa prajiturile cumparate de o persoana
CommandTaker shop2;
CommandTaker rcake2;
CakeMaker shop3;
CakeMaker rcake3;

void mainMenu();
void administratormenu()
{
	int op;

	cout << endl;
	cout << "=============================================    ADMINISTRATOR MENU   ========================================" << endl;
	cout << "| 1-Adaugare retete (in RecipeCake)                                                                          |" << endl;
	cout << "| 2-Lista de retete ce pot fi realizate in cofetaria noastra                                                 |" << endl;
	cout << "| 3-Adaugare denumire de prajituri ce pot fi comandate azi din stoc (in Cake)                                |" << endl;
	cout << "| 4-Lista de produse ce pot fi cumparate din stoc                                                            |" << endl;
	cout << "| 5-Umpleti cofetaria cu prajituri, daca stocul este scazut                                                  |" << endl;
	cout << "| 6-Iesire la meniul principal                                                                               |" << endl;
	cout << "==============================================================================================================" << endl;
	do
	{
		cout << endl;
		cout << "Introduceti o optiune " << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			RecipeCake addItem;
			string newItemName;
			int newItemTime;
			char x;
			cout << "Adaugati retete de prajituri ce pot fi facute la comanda(in RecipeCake)" << endl;
			do
			{
				cout << "Introduceti denumirea retetei: " << endl;
				cin.ignore();
				getline(cin, newItemName);
				addItem.setName(newItemName);

				cout << "Introduceti timpul de executie al acestei prajituri: " << endl;
				cin >> newItemTime;
				addItem.setTime(newItemTime);

				shop.selectProduct(shop.list, addItem);//adauga prajitura pentru a fi comandata(in CommandPanel)
				shop2.takeCommand(shop2.list, addItem);//adauga prajitura la comanda(in CommandTaker)

				cout << "Doriti sa mai adaugati retete? y = DA n = NU: ";
				cin >> x;
			} while (x == 'y');

			break;

		}
		case 2://afiseaza toate prajiturile posibile a fi realizate (cele din RecipeCake)
		{
			cout << "Puteti comanda urmatoarele prajituri ce pot fi realizate in cofetaria noastra:" << endl;
			shop.showProducts();
			break;
		}
		case 3:
		{
			Cake addItem2;
			string newItemName2;
			int newItemQ2;
			char x;
			cout << "Adaugati prajiturile ce pot fi cumparate din cofetarie astazi (in Cake)" << endl;
			do
			{
				cout << "Introduceti numele prajiturii: " << endl;
				cin.ignore();
				getline(cin, newItemName2);
				addItem2.setNume(newItemName2);

				cout << "Introduceti numarul de bucati din acesta prajitura existente in cofetarie la prima ora: " << endl;
				cin >> newItemQ2;
				addItem2.setQuantity(newItemQ2);

				shop1.addCake(shop1.list, addItem2);//adauga prajitura in storage

				cout << "Doriti sa mai adaugati alte  prajituri in cofetarie? y = DA n = NU: ";
				cin >> x;
			} while (x == 'y');
			break;
		}

		case 4:// afiseaza toate produsele ce pot fi cumparate din stoc (cele din CarouselOf Cakes)
		{
			cin.clear();
			cout << "Puteti alege urmatoarele prajituri din stoc:" << endl;
			shop1.showProductsInCarousel();
			break;
		}
		case 5:
		{
			Cake addItem4;
			string newItemName4;
			int newItemQ4;
			cout << "Refaceti stocul la capacitatea maxima de 10 bucati" << endl;
			cout << "Prajituri din stoc au acum urmatoarea cantitate:" << endl;
			shop1.showProductsInCarousel();
			cout << "Pentru ce prajitura refaceti stocul? ";
			cin >> newItemName4;
			cout << "Asteapta 5 secunde pana cand cofetarul face prajiturile" << endl;

			sleep_until(system_clock::now() + seconds(5));

			shop1.refillCarousel(newItemName4);
			cout << "Stocul a fost refacut!" << endl;
			shop1.showProductsInCarousel();

			addItem4.setNume(newItemName4);
			newItemQ4 = shop1.refillCarousel(newItemName4);
			addItem4.setQuantity(newItemQ4);
			rcake3.takeCommand(rcake3.cm2, addItem4);//se pune in vectorul pentru cofetar ce prajitura trebuie sa aiba stocul refacut

			break;
		}
		case 6:
			mainMenu();
			break;
		default:
			cout << "Nu avem aceasta optiune" << endl;
			break;
		}
	} while (op != 6);
}

void productsmenu()
{
	int op;

	cout << endl;
	cout << "=============================================    PRODUCTS MENU   =============================================" << endl;
	cout << "| 1-Lista de retete ce pot fi realizate in cofetaria noastra                                                 |" << endl;
	cout << "| 2-Lista de produse ce pot fi cumparate din stoc                                                            |" << endl;
	cout << "| 3-Pune o comanda  (alege prajituri ce pot fi comandate si pregatite intr-un interval de timp)              |" << endl;
	cout << "| 4-Cumpara prajituri din stoc (alege prajituri ce pot fi comandate pe loc)                                  |" << endl;
	cout << "| 5-Finalizati comanda! Va multumim! :)                                                                      |" << endl;
	cout << "| 6-Iesire la meniul principal                                                                               |" << endl;
	cout << "==============================================================================================================" << endl;
	do
	{
		cout << "\n Introduceti o optiune " << endl;
		cin >> op;
		switch (op)
		{

		case 1://afiseaza toate prajiturile posibile a fi realizate (cele din RecipeCake)
		{

			cout << "Puteti comanda urmatoarele prajituri ce pot fi realizate in cofetaria noastra:" << endl;
			shop.showProducts();
			break;
		}
		case 2:// afiseaza toate produsele ce pot fi cumparate din stoc (cele din CarouselOf Cakes)
		{
			cout << "Puteti alege urmatoarele prajituri din stoc, daca sunt mai mult de 3 bucati, altfel se comanda:" << endl;
			shop1.showProductsInCarousel();
			break;
		}
		case 3:
		{
			RecipeCake addItem1;
			string newItemName1;
			int newItemTime1;
			char x;

			cout << "Adaugare comanda (in CommandPannel):" << endl;
			do
			{
				cout << "Introduceti numele prajiturii pentru care se face o comanda: " << endl;
				cin.ignore();
				getline(cin, newItemName1);
				if (shop1.checkNames(newItemName1) == true)//verifica daca numele prajiturii exista pe stoc
				{
					addItem1.setName(newItemName1);
					cout << "Introduceti timpul de executie aferent " << endl;
					cin >> newItemTime1;
					addItem1.setTime(newItemTime1);
				}
				else
					cout << "Aceasta denumire de prajitura nu exista la noi in cofetarie" << endl;

				rcake.selectProduct(rcake.rcakeItems, addItem1);
				rcake3.takeCommand(rcake3.cm1, addItem1);// adaugare si in lista de comenzi pentru cakemakermenu/CakeMaker
				cout << "Doriti sa mai comandati si alta prajitura? y = DA n = NU: ";
				cin >> x;
			} while (x == 'y');
			break;
		}
		case 4:
		{
			int k = 0;
			Cake addItem3;
			string newItemName3;
			int newItemQ3;
			int a;
			char x, z;
			cout << "Cumparare prajituri din stoc (in CarouselOfCakes), daca sunt mai mult de 3 bucati, altfel se comanda:" << endl;
			cout << "Azi avem pe stoc tipuri de prajituri intr-un numar de: ";
			a = shop1.getCurrentCapacity();
			cout << a << endl;
			cout << "\n Aceste prajituri sunt: " << endl;
			shop1.showProductsInCarousel();

			do
			{
				cout << "\n Introduceti numele prajiturii pe care o cumparati: " << endl;
				cin.ignore();
				getline(cin, newItemName3);
				if (shop1.checkNames(newItemName3) == true)//verifica daca numele prajiturii comandate exista 
				{
					addItem3.setNume(newItemName3);
					cout << "\n Introduceti numarul de bucati pe care le cumparati" << endl;
					cin >> newItemQ3;
					addItem3.setQuantity(newItemQ3);
					if (shop1.checkCarouselOfCakes(newItemName3, newItemQ3) == false)//verifica daca sunt in storage minim 3 bucati din prajitura ce se vrea cumparata
					{
						cout << "Aceasta prajitura nu se poate cumpara din stoc, deoarece sunt/vor fi mai putin de 3 bucati, dar se poate comanda" << endl;
					}
					else
					{
						cake1.addCake(cake1.storage, addItem3);
						shop1.UpdateQuantity(newItemName3, newItemQ3);//daca se vinde o prajitura se scade din totalul din storage

					}
				}
				else
					cout << "Aceasta denumire de prajitura nu este la noi in cofetarie" << endl;

				cout << "Doriti sa mai cumparati si alta prajitura? y = DA n = NU: ";
				cin >> x;
			} while (x == 'y');

			break;
		}
		case 5:
		{

			if (rcake.rcakeItems.size() == 0)
				cout << "Nu ai comandat nimic! :(" << endl;
			else
			{
				cout << "Ati comandat: " << endl;
				rcake.showProducts();
			}
			if (cake1.storage.size() == 0)
				cout << "Nu ai cumparat nimic din produsele existente pe stoc in cofetarie! :(" << endl;
			else
			{
				cout << "Ati cumparat: " << endl;
				cake1.showProductsInCarousel();
			}
			break;
		}
		case 6:
			mainMenu();
			break;
		default:
			cout << "Nu avem aceasta optiune" << endl;
			break;
		}
	} while (op != 6);
}

void cakemakermenu()
{
	int op;

	cout << endl;
	cout << "=============================================    CAKEMAKER MENU   ============================================" << endl;
	cout << "| 1-Lista de retete ce pot fi realizate in cofetaria noastra                                                 |" << endl;
	cout << "| 2-Lista de produse ce pot fi cumparate din stoc                                                            |" << endl;
	cout << "| 3-Umpleti cofetaria cu prajituri, daca stocul este scazut sau realizati prajituri la comanda               |" << endl;
	cout << "| 4-Iesire la meniul principal                                                                               |" << endl;
	cout << "==============================================================================================================" << endl;
	do
	{
		cout << "Introduceti o optiune " << endl;
		cin >> op;
		switch (op)
		{
		case 1://afiseaza toate prajiturile posibile a fi realizate (cele din RecipeCake)
		{

			cout << "Puteti comanda urmatoarele prajituri ce pot fi realizate in cofetaria noastra:" << endl;
			shop.showProducts();
			break;
		}

		case 2:// afiseaza toate produsele ce pot fi cumparate din stoc (cele din CarouselOf Cakes)
		{
			cin.clear();
			cout << "Puteti alege urmatoarele prajituri din stoc:" << endl;
			shop1.showProductsInCarousel();
			break;
		}
		case 3:
		{
			cout << "Realizati urmatoarele prajituri la comanda:" << endl;
			rcake.showProducts();//numarul de prajituri comandate este = cu numarul de prajituri realizate de CakeMaker, deci putem folosi functia showProduts in ambele cazuri
			cout << endl;
			cout << "Realizati  prajituri pentru a umple storage-ul la capacitatea maxima, pentru un numar de:" << endl;
			rcake3.showProductsInCakeMaker();//showProductsInCakeMaker afiseaza diferenta de prajituri ce trebuie facute pentru storage pana la maxCapacity, iar showProductsInCarousel afiseaza prajiturile existente in storage
			cout << endl;
			cout << "Asteptati 5 secunde pana se realizeaza prajiturile" << endl;

			sleep_until(system_clock::now() + seconds(5));

			cout << "Prajiturile au fost realizate" << endl;
			break;

		}
		case 4:
			mainMenu();
			break;
		default:
			cout << "Nu avem aceasta optiune" << endl;
			break;
		}
	} while (op != 4);
}


void mainMenu()
{

	int opt;


	cout << "  ________________________________________________________________________________ " << endl;
	cout << "   ******   B U N   V E N I T   I N   C O F E T A R I A   N O A S T R A!  *******  " << endl;
	cout << "  ________________________________________________________________________________ " << endl;
	cout << " |                 ****************   MAIN MENU   *****************               | " << endl;
	cout << " |                            1. ADMINISTRATOR MODE                               | " << endl;
	cout << " |                            2. CAKE SALER->PLACE ORDER                          | " << endl;
	cout << " |                            3. CAKE MAKER                                       | " << endl;
	cout << " |                            4. EXIT                                             | " << endl;
	cout << " |________________________________________________________________________________| " << endl;
	do
	{
		cout << "Introduceti o optiune: " << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			administratormenu();
			break;
		case 2:
			productsmenu();
			break;
		case 3:
			cakemakermenu();
			break;
		case 4:
			cout << "IESIRE DIN MENIU";
			exit(0);
		default:
			cout << "Nu avem aceasta optiune" << endl;
			break;
		}
	} while (opt != 4);
}

int main()
{
	mainMenu();
	return 0;
}