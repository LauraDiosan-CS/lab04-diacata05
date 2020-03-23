#include "Produs.h";
#include "Teste.h";
#include "Repo.h"
#include <iostream>

using namespace std;

void afisareMeniu() {
	cout << "1. Adaugare produs" << endl;
	cout << "2. Afisare produse" << endl;
	cout << "0. Exit" << endl;
}


int main() {
	teste();
	
	Repo r = Repo();
	Produs p = Produs();
	Produs* produseDeAfisat;

	bool finish = true;
	int optiune = 0;
	unsigned int pret = 0;

	while (finish) {
		afisareMeniu();
		cout << "Optiune: ";
		cin >> optiune;
		switch (optiune) {
		case 1:
			cout << "Pret: ";
			cin >> pret;
			p.setPret(pret);
			r.addProdus(p);
			break;
		case 2:
			produseDeAfisat = r.getAll();
			for (int i = 0; i < r.getSize(); i++) {
				cout << produseDeAfisat[i].toString() << endl;
			}
			break;
		case 0:
			finish = false;
			break;
		}
	}
}