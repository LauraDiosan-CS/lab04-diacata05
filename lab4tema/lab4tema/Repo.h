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

	void addProdus(Produs& f);
	Produs* getProduse();
	int getSize();
	Produs& getProdus(int pos);
};

#endif