#include "Teste.h"
#include "Produs.h"
#include "Repo.h"
#include <assert.h>;

void testeRepo() {
	Repo r = Repo();

	assert(r.getSize() == 0);

	Produs p(10), p1(2);

	r.addProdus(p);
	r.addProdus(p1);

	assert(r.getSize() == 2);
	assert(r.getAll()[0].getPret() == 10);
	assert(r.getAll()[1].getPret() == 2);
}

void testeProdus() {
	Produs p = Produs();

	assert(p.getPret() == 0);

	Produs p1(10);
	Produs p11(p1);

	assert(p1.getPret() == 10);
	assert(p11.getPret() == 10);

	Produs p2(11);

	assert(p2.getPret() == 11);
	p2.setPret(22);
	assert(p2.getPret() == 22);

	Produs p3(23);

	char* string = p3.toString();
	assert(strcmp(string, "pret: 23") == 0);
}


void teste() {
	testeRepo();
	testeProdus();
}