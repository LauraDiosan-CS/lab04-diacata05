#pragma once
#ifndef REPO_H
#define REPO_H

#include "Produs.h"

const int MAX_PRODUSE = 10;

class Repo {
private:
	Produs* produse;
	int numarProduse;
public:
	Repo();
	Repo(Produs* p, int nP);
	Repo(const Repo& r);
	~Repo();

	void setNumarProduse(int nP);

	void addProdus(Produs& f);
	Produs* getProduse();
	int getSize();
	void deleteProdus(int pos);
	void updateProdus(int pos, Produs p);
	Produs& getProdus(int pos);

	Repo& operator=(const Repo& r);
};

#endif