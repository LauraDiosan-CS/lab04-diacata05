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

	Produs p1(nume, Data(1,1,2020), 2.5);
	
	assert(strcmp(p1.getNume(), "nume") == 0);
	assert(p1.getPret() == 2.5);
	assert(p1.getData().getZi() == 1);
	assert(p1.getData().getLuna() == 1);
	assert(p1.getData().getAn() == 2020);

	Produs p2 = p1;

	assert(strcmp(p2.getNume(), "nume") == 0);
	assert(p2.getPret() == 2.5);
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
	char numeNou[] = "numeNou";

	Repo r;

	assert(r.getSize() == 0);

	Produs p1(nume, Data(), 1);

	r.addProdus(p1);

	assert(r.getSize() == 1);
	
	r.addProdus(p1);

	assert(r.getSize() == 2);

	Produs p2 = r.getProdus(0);

	assert(p2.getPret() == 1);

	Repo r2;

	Produs p3(nume, Data(29, 3, 2020), 1);

	r2.addProdus(p3);
	r2.addProdus(p3);
	r2.addProdus(p3);

	r2.updateProdus(1, Produs(nume, Data(29, 3, 2020), 2));

	assert(r2.getProdus(1).getPret() == 2);

	r2.updateProdus(1, Produs(numeNou, Data(29, 3, 2020), 2));

	assert(strcmp(r2.getProdus(1).getNume(), "numeNou") == 0);

	r2.updateProdus(1, Produs(numeNou, Data(30, 3, 2020), 2));

	assert(r2.getProdus(1).getData().getZi() == 30);

	assert(r2.getSize() == 3);

	r2.deleteProdus(1);

	assert(r2.getSize() == 2);

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

	s.create(nume, Data(28, 3, 2020), 10);
	s.create(nume, Data(28, 3, 2020), 11);
	s.create(nume, Data(28, 3, 2020), 12);

	assert(s.getRepo().getSize() == 4);

	s.del(1);

	assert(s.getRepo().getSize() == 3);

	Service s2;

	Data d;
	s2.create(nume, d.today(), 10);
	s2.create(nume, d.today(), 11);


	int numarProduse = s2.produseReaduseAstaziPeStoc();

	assert(numarProduse == 2);

	s2.reducereCu10Produse(Data(30, 3, 2020));

	assert(s2.read(0).getPret() == 9);
	assert(s2.read(1).getPret() == 9.9);
}

void teste() {
	testeProdus();
	testeRepo();
	testeData();
	testeService();
}