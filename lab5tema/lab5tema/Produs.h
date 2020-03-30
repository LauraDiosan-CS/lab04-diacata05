#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include "Data.h"

using namespace std;

class Produs {
private:
	char* nume;
	Data data;
	double pret;
public:
	Produs();
	Produs(char* name, Data d, double p);
	Produs(const Produs& f);
	~Produs();
	Produs& operator=(const Produs& f);
	char* getNume();
	Data getData();
	double getPret();
	void setNume(char* n);
	void setData(Data data);
	void setPret(double p);

	char* toString();
};

#endif

#pragma once