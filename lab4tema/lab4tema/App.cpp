#include <iostream>
#include "Produs.h"
#include "Repo.h"
#include "Teste.h"

using namespace std;

void afisareMeniu() {
	cout << "1. Adaugare produs" << endl;
	cout << "2. Afisare produse" << endl;
	cout << "0. Exit" << endl;
}

int main(){
	cout << "Running tests..." << endl;
	teste();
	cout << "Tests passed!" << endl << "--------------------" << endl;

	Repo r;
	bool finish = true;
	int optiune = 0;
	while (finish) {
		afisareMeniu();
		cout << "Optiune: ";
		cin >> optiune;
		switch (optiune) {
		case 1:
		{
			char* nume = new char[10];
			unsigned int pret = 0, zi = 1, luna = 1, an = 2000;
			cout << "Nume: ";
			cin >> nume;
			cout << "Data:" << endl;
			cout << "--- Zi: ";
			cin >> zi;
			cout << "--- Luna: ";
			cin >> luna;
			cout << "--- An: ";
			cin >> an;
			cout << "Pret: ";
			cin >> pret;
			Produs p(nume, Data(zi, luna, an), pret);
			r.addProdus(p);
			break;
		}
		case 2:
		{
			Produs* produse = r.getProduse();
			for (int i = 0; i < r.getSize(); i++) {
				cout << produse[i].toString() << endl;
			}
			break;
		}
		case 0:
			finish = false;
			break;
		}
	}
}