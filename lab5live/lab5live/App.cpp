#include <iostream>
#include "Produs.h"
#include "Repo.h"
#include "Service.h"
#include "Teste.h"

using namespace std;

void afisareMeniu() {
	cout << "1. Adaugare produs" << endl;
	cout << "2. Citeste produs" << endl;
	cout << "3. Sterge produs" << endl;
	cout << "4. Update produs" << endl;
	cout << "5. Afisare produse" << endl;
	cout << "0. Exit" << endl;
}

void consola() {
	Service s;
	
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
			s.create(nume, Data(zi, luna, an), pret);
			break;
		}
		case 2:
		{
			s.print();
			int pos = 0;
			cout << "Pozitie: ";
			cin >> pos;
			Produs p = s.read(pos);
			cout << p.toString() << endl;
			break;
		}
		case 3:
		{
			s.print();
			int pos = 0;
			cout << "Pozitie: ";
			cin >> pos;
			s.del(pos);
			break;
		}
		case 4:
		{
			s.print();
			int pos = 0;
			cout << "Pozitie: ";
			cin >> pos;
			int atribut = 0;
			cout << "Alege atribut:" << endl;
			cout << "1. Nume" << endl;
			cout << "2. Data" << endl;
			cout << "3. Pret" << endl;
			cout << "-----------------" << endl;
			cout << "Atribut: ";
			cin >> atribut;
			switch (atribut) {
			case 1:
			{
				char* nume = new char[10];
				cout << "Nume: ";
				cin >> nume;
				s.updateNume(pos, nume);
				break;
			}
			case 2:
			{
				unsigned int zi = 1, luna = 1, an = 2000;
				cout << "Introduceti noua data:" << endl;
				cout << "--- Zi: ";
				cin >> zi;
				cout << "--- Luna: ";
				cin >> luna;
				cout << "--- An: ";
				cin >> an;
				s.updateData(pos, Data(zi, luna, an));
				break;
			}
			case 3:
			{
				unsigned int pret = 0;
				cout << "Pret: ";
				cin >> pret;
				s.updatePret(pos, pret);
				break;
			}
			default:
			{
				cout << "Nu exista astfel de optiune!" << endl;
			}
			}
			break;
		}
		case 5:
		{
			s.print();
			break;
		}
		case 0:
			finish = false;
			break;
		}
	}
}

int main(){
	cout << "Running tests..." << endl;
	teste();
	cout << "Tests passed!" << endl << "--------------------" << endl;

	consola();

	return 0;
}