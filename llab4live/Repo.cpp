#include "Repo.h";

/*
	descr: constructor implicit
	in: -
	out: entitate Repo
*/
Repo::Repo() {
	this->produse = new Produs[100];
	this->numarProduse = 0;
}

/*
	descr: constructor cu parametrii
	in: ref - array de produse, integer - numarul de produse
	out: entitate Repo cu proprietati
*/
Repo::Repo(Produs* prods, int nP) {
	this->produse = new Produs[nP];
	this->numarProduse = nP;
	for (int i = 0; i < this->numarProduse; i++) {
		this->produse[i] = prods[i];
	}
}

/*
 descr: constructor de copiere
 in: entitate Repo de copiat
 out: entitate Repo
*/
Repo::Repo(const Repo& rep) {
	this->produse = rep.produse;
	this->numarProduse = rep.numarProduse;
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
	this->produse[numarProduse++] = p;
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
	descr: get all
	in: -
	out: ref - toate produsele
*/

Produs* Repo::getAll() {
	return this->produse;
}

Repo& Repo::operator=(const Repo& rep) {
	if (this != &rep) {
		this->produse = rep.produse;
		this->numarProduse = rep.numarProduse;
	}

	return *this;
}