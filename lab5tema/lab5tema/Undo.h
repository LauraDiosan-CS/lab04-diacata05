#ifndef UNDO_H
#define UNDO_H

#include "Produs.h";
#include "Repo.h";
#include "Service.h";

const int MAX = 10;

enum Operatie {
	add,
	del,
	update
};

enum Update {
	nume,
	dataU,
	pret
};

class Undo {
public:
	static int op[MAX];
	static int poz[MAX];
	static int updateType[MAX];
	static Repo repo;
	static int numar;

	static void addOp(int pos, Produs p);

	static void deleteOp(Produs p);

	static void updateOp(int pos, Produs p, int u);

	static void undo(Service &s);
private:
	Undo();
};

#endif

#pragma once
