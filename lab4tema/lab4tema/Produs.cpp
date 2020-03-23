#include "Produs.h"
#include "Data.h"
#include <string.h>


/*
	descr: constructor implicit
	in: -
	out: entitate Produs
*/
Produs::Produs() {
	this->nume = NULL;
	this->data = Data();
	this->pret = 0;
}

/*
	descr: constructor cu parametrii
	in: char* n, Data d, unsigned int p
	out: entitate Produs cu parametrul pret setat
*/
Produs::Produs(char* n, Data d, unsigned int p) {
	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
	this->data = d;
	this->pret = p;
}

/*
	descr: constructor de copiere
	in: ref entitate Produs
	out: entitate Produs
*/
Produs::Produs(const Produs& p) {
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	this->data = p.data;
	this->pret = p.pret;
}

/*
	descr: destructor
	in: -
	out: -
*/
Produs::~Produs() {
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
}

/*
	descr: getter pentru atributul nume
	in: -
	out: integer - numele entitatii
*/
char* Produs::getNume() {
	return this->nume;
}

/*
	descr: getter pentru atributul data
	in: -
	out: integer - data entitatii
*/
Data Produs::getData() {
	return this->data;
}

/*
	descr: getter pentru atributul pret
	in: -
	out: integer - pret entitatii
*/
unsigned int Produs::getPret() {
	return this->pret;
}



/*
	descr: setter pentru atributul nume
	in: char* n
	out: -
*/
void Produs::setNume(char* n) {
	if (this->nume) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
}

/*
	descr: setter pentru atributul data
	in: Data d
	out: -
*/
void Produs::setData(Data d) {
	this->data = d;
}

/*
	descr: setter pentru prop. suma
	in: unsigned integer - noua suma
	out: -
*/
void Produs::setPret(unsigned int p) {
	this->pret = p;
}

char* Produs::toString() {
	char empty[] = "empty";
	if (this->nume != NULL) {
		int noChars = 45;
		char* s = new char[noChars];
		char* aux = new char[3];
		strcpy_s(s, noChars, "nume: ");
		strcat_s(s, noChars, this->nume);
		strcat_s(s, noChars, ", data: ");
		strcat_s(s, noChars, this->data.toString());
		strcat_s(s, noChars, ", pret: ");
		_itoa_s(this->pret, aux, 3, 10);
		strcat_s(s, noChars, aux);

		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		return s;
	}
	else
		return empty;
}

Produs& Produs::operator=(const Produs& p) {
	if (this != &p) {
		this->setNume(p.nume);
		this->setData(p.data);
		this->setPret(p.pret);
	}
	return *this;
}