#include "Repo.h"
#include <string.h>

/*
	descr: constructor implicit
	in: -
	out: entitate Repo
*/
Repo::Repo() {
	this->numarProduse = 0;
	this->produse = new Produs[MAX_PRODUSE];
}

/*
	descr: constructor cu parametrii
	in: ref - array de produse, integer - numarul de produse
	out: entitate Repo cu proprietati
*/
Repo::Repo(Produs* p, int nP) {
	this->numarProduse = nP;
	this->produse = new Produs[nP];
	for (int i = 0; i < this->numarProduse; i++)
		this->produse[i] = p[i];
}

/*
 descr: constructor de copiere
 in: entitate Repo de copiat
 out: entitate Repo
*/
Repo::Repo(const Repo& r) {
	this->numarProduse = r.numarProduse;
	this->produse = new Produs[numarProduse];
	for (int i = 0; i < this->numarProduse; i++)
		this->produse[i] = r.produse[i];
}


/*
	descr: destructor
	in: -
	out: -
*/
Repo::~Repo() {
	if (this->produse) {
		delete[] this->produse;
		this->produse = NULL;
	}
}

/*
	descr: adaugare produs
	in: Produs - p
	out: -
*/
void Repo::addProdus(Produs& p) {
	if (this->numarProduse == MAX_PRODUSE) {
		Produs* produseAux = new Produs[2 * MAX_PRODUSE];
		for (int i = 0; i < this->numarProduse; i++)
			produseAux[i] = this->produse[i];
		delete[] this->produse;
		this->produse = produseAux;
	}
	this->produse[numarProduse++] = p;
}

/*
	descr: get all
	in: -
	out: ref - toate produsele
*/
Produs* Repo::getProduse() {
	return this->produse;
}

/*
	descr: numarul de produse
	in: -
	out: integer - numarul
*/
int Repo::getSize() {
	return this->numarProduse;
}

/*
	descr: produs de pe pozitia pos
	in: integer pos
	out: entitate produs
*/
Produs& Repo::getProdus(int pos) {
	if ((pos >= 0) && (pos < this->numarProduse))
		return this->produse[pos];
}