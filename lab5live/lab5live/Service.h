#ifndef SERVICE_H
#define SERVICE_H

#include "Repo.h";
class Service {
private:
	Repo repo;
public:
	Service();
	Service(Repo r);
	Service(const Service& s);
	~Service();

	Repo getRepo();
	void setRepo(Repo r);

	void create(char* name, Data data, unsigned int pret);
	Produs& read(int pos);
	Produs* readAll();
	void del(int pos);
	void updateNume(int pos, char* nume);
	void updateData(int pos, Data data);
	void updatePret(int pos, unsigned int pret);
	void print();

	Service& operator=(const Service& s);
};
#endif

#pragma once