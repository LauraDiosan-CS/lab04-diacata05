#include "Produs.h"

using namespace std;
/*
	descr: constructor implicit
	in: -
	out: entitate Produs
*/
Produs::Produs() {
	pret = 0;
}

/*
	descr: constructor cu parametrii
	in: unsigned integer - pretInitial
	out: entitate Produs cu parametrul pret setat
*/
Produs::Produs(unsigned int pretInitial) {
	this->pret = pretInitial;
}

/*
	descr: constructor de copiere
	in: ref entitate Produs
	out: entitate Produs
*/

Produs::Produs(const Produs& p) {
	this->pret = p.pret;
}

/*
	descr: destructor
	in: -
	out: -
*/
Produs::~Produs() {
}
/*
	descr: getter pentru atributul pret
	in: -
	out: integer - pret entitatii
*/
unsigned int Produs::getPret() {
	return pret;
}

/*
	descr: setter pentru prop. suma
	in: unsigned integer - noua suma
	out: -
*/
void Produs::setPret(unsigned int pretNou) {
	pret = pretNou;
}


Produs& Produs::operator=(const Produs& p) {
	if (this != &p) {
		this->pret = p.pret;
	}
	return *this;
}

char* Produs::toString() {
	char* s = new char[10];
	char* aux = new char[3];


	strcpy_s(s, 10, "pret: ");

	_itoa_s(this->pret, aux, 3, 10);

	strcat_s(s, 10, aux);

	if (aux) {
		delete[] aux;
		aux = NULL;
	}
	return s;
}