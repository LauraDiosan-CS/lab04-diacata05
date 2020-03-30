#include "UI.h"
#include "Undo.h"

/*
	descr: constructor implicit;
	in: -
	out: entitate UI
*/
UI::UI() {}

/*
	descr: constructor cu parametrii
	in: Service s
	out: entitate UI cu atributul service setat
*/
UI::UI(Service s) {
	this->service = s;
}

/*
	descr: constructor de copiere
	in: -
	out: entitate UI
*/
UI::UI(const UI& ui) {
	this->service = ui.service;
}

/*
	descr: destructor
	in: -
	out: -
*/
UI::~UI() {};

/*
	descr: getter pentru atributul service
	in: -
	out: attributul service al entitatii
*/
Service UI::getService() {
	return this->service;
}

/*
	descr: setter pentru atributul service
	in: Service s
	out: -
*/
void UI::setService(Service s) {
	this->service = s;
}

/*
	descr: afisare meniu
	in: -
	out: -
*/
void UI::afisareMeniu() {
	cout << "1. Adaugare produs" << endl;
	cout << "2. Sterge produs" << endl;
	cout << "3. Update produs" << endl;
	cout << "4. Produse readuse astazi pe stoc" << endl;
	cout << "5. Reducere cu 10% a produselor anterioare datei date" << endl;
	cout << "6. Afisare produse" << endl;
	cout << "7. Undo" << endl;
	cout << "0. Exit" << endl;
}

/*
	descr: interfata create pentru utilizator
	in: -
	out: -
*/
void UI::uiCreate() {
	char* nume = this->readNume();
	Data d = this->readData();
	double pret = this->readPret();
	
	this->service.create(nume, d, pret);
}

/*
	descr: interfata read pentru utilizator
	in: -
	out: -
*/
void UI::uiRead() {
	this->service.print();
}

/*
	descr: interfata delete pentru utilizator
	in: -
	out: -
*/
void UI::uiDelete() {
	this->service.print();
	int pos = 0;
	cout << "Pozitie: ";
	cin >> pos;
	this->service.del(pos);
}

/*
	descr: interfata delete pentru utilizator
	in: -
	out: -
*/
void UI::uiUpdate() {
	this->service.print();
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
		char* nume = this->readNume();
		this->service.updateNume(pos, nume);
		break;
	}
	case 2:
	{
		Data d = this->readData();
		this->service.updateData(pos, d);
		break;
	}
	case 3:
	{
		double pret = this->readPret();
		this->service.updatePret(pos, pret);
		break;
	}
	default:
	{
		cout << "Nu exista astfel de optiune!" << endl;
	}
	}
}

/*
	descr: interfata cu utilizatorul funtionalitate afisare produse care au reajuns astazi pe stoc
	in: -
	out: -
*/
void UI::uiReadProduseReaduseAstaziPeStoc() {
	int numarProduse = this->service.produseReaduseAstaziPeStoc();
	if (numarProduse > 0) {
		cout << "S-a(u) gasit " << numarProduse << " produs(e)!" << endl;
	}
}

/*
	descr: interfata cu utilizatorul funtionalitate reducere cu 10% produse 
	in: -
	out: -
*/
void UI::uiReducere10() {
	Data d = this->readData();
	this->service.reducereCu10Produse(d);
}

/*
	descr: interfata cu utilizatorul
	in: -
	out: -
*/

void UI::consola() {
	bool finish = true;
	int optiune = 0;
	while (finish) {
		this->afisareMeniu();
		cout << "Optiune: ";
		cin >> optiune;
		switch (optiune) {
		case 1:
			this->uiCreate();
			break;
		case 2:
			this->uiDelete();
			break;
		case 3:
			this->uiUpdate();
			break;
		case 4:
			this->uiReadProduseReaduseAstaziPeStoc();
			break;
		case 5:
			this->uiReducere10();
			break;
		case 6:
			this->uiRead();
			break;
		case 7:
			Undo::undo(this->service);
			break;
		case 0:
			finish = false;
			break;
		default:
			cout << "Nu exista astfel de optiune!" << endl;
			break;
		}
	}
}

double UI::readPret() {
	double pret = 0;
	cout << "Pret: ";
	cin >> pret;
	return pret;
}

Data UI::readData() {
	unsigned int zi = 1, luna = 1, an = 2000;
	cout << "Introduceti noua data:" << endl;
	cout << "--- Zi: ";
	cin >> zi;
	cout << "--- Luna: ";
	cin >> luna;
	cout << "--- An: ";
	cin >> an;
	
	return Data(zi, luna, an);
}

char* UI::readNume() {
	char* nume = new char[10];
	cout << "Nume: ";
	cin >> nume;

	return nume;
}