#pragma once
#ifndef REPO_H
#define REPO_H
#include "Produs.h";

class Repo {
private: 
	Produs* produse;
	int numarProduse;
public:
	Repo();
	Repo(Produs* prods, int nP);
	Repo(const Repo& rep);
	~Repo();
	void addProdus(Produs& p);
	int getSize();
	Produs* getAll();

	Repo& operator=(const Repo& rep);

};

#endif