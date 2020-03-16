#pragma once
#ifndef PRODUS_H
#define PRODUS_H
using namespace std;

#include <string>

class Produs {
private:
	unsigned int pret;
public:
	Produs();
	Produs(unsigned int pretInitial);
	Produs(const Produs& p);
	~Produs();
	unsigned int getPret();
	void setPret(unsigned int pretNou);

	Produs& operator=(const Produs& p);
	char* toString();
};

#endif