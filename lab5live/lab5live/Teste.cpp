#pragma once

#include <assert.h>
#include "Produs.h"
#include "Repo.h"
#include "Data.h"
#include "Service.h"
#include <string>

void testeProdus() {
	char nume[] = "nume";
	char numeNou[] = "numeNou";

	Produs p1(nume, Data(1,1,2020), 10);
	
	assert(strcmp(p1.getNume(), "nume") == 0);
	assert(p1.getPret() == 10);
	assert(p1.getData().getZi() == 1);
	assert(p1.getData().getLuna() == 1);
	assert(p1.getData().getAn() == 2020);

	Produs p2 = p1;

	assert(strcmp(p2.getNume(), "nume") == 0);
	assert(p2.getPret() == 10);
	assert(p2.getData().getZi() == 1);
	assert(p2.getData().getLuna() == 1);
	assert(p2.getData().getAn() == 2020);

	p1.setNume(numeNou);
	p1.setData(Data(23, 3, 2020));
	p1.setPret(25);

	assert(strcmp(p1.getNume(), "numeNou") == 0);
	assert(p1.getPret() == 25);
	assert(p1.getData().getZi() == 23);
	assert(p1.getData().getLuna() == 3);
	assert(p1.getData().getAn() == 2020);

}

void testeRepo() {
	char nume[] = "nume";

	Repo r;

	assert(r.getSize() == 0);

	Produs p1(nume, Data(), 1);

	r.addProdus(p1);

	assert(r.getSize() == 1);
	
	r.addProdus(p1);

	assert(r.getSize() == 2);

	Produs p2 = r.getProdus(0);

	assert(p2.getPret() == 1);
}

void testeData() {
	Data d1;

	assert(d1.getZi() == 1);
	assert(d1.getLuna() == 1);
	assert(d1.getAn() == 2000);

	Data d2(23, 3, 2020);

	assert(d2.getZi() == 23);
	assert(d2.getLuna() == 3);
	assert(d2.getAn() == 2020);

	Data d3 = d2;

	assert(d3.getZi() == 23);
	assert(d3.getLuna() == 3);
	assert(d3.getAn() == 2020);

	d3.setZi(24);
	d3.setLuna(4);
	d3.setAn(2021);

	assert(d3.getZi() == 24);
	assert(d3.getLuna() == 4);
	assert(d3.getAn() == 2021);

	assert(d2 > d1);
	assert(d3 > d2);
	
}

void testeService() {
	char nume[] = "nume";
	char numeNou[] = "numeNou";

	Produs p1(nume, Data(1, 1, 2020), 10);

	Service s;

	s.create(nume, Data(), 10);

	assert(s.getRepo().getSize() == 1);

	s.updateData(0, Data(1, 2, 2020));
	s.updateNume(0, numeNou);
	s.updatePret(0, 15);

	assert(s.getRepo().getProdus(0).getData().getLuna() == 2);
	assert(strcmp(s.getRepo().getProdus(0).getNume(),numeNou)==0);
	assert(s.getRepo().getProdus(0).getPret() == 15);

	s.create(nume, Data(), 10);
	s.create(nume, Data(), 10);
	s.create(nume, Data(), 10);

	assert(s.getRepo().getSize() == 4);

	s.del(1);

	assert(s.getRepo().getSize() == 3);
	
}

void teste() {
	testeProdus();
	testeRepo();
	testeData();
	testeService();
}