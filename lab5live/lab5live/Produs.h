#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include "Data.h"

using namespace std;

const int MAX_NUME = 10;

class Produs {
private:
	char* nume;
	Data data;
	unsigned int pret;
public:
	Produs();
	Produs(char* name, Data d, unsigned int p);
	Produs(const Produs& f);
	Produs(char* s);
	~Produs();
	Produs& operator=(const Produs& f);
	char* getNume();
	Data getData();
	unsigned int getPret();
	void setNume(char* n);
	void setData(Data data);
	void setPret(unsigned int p);

	char* toString();
	bool compare(Produs& f);
};

#endif

#pragma once