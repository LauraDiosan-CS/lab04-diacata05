#include "Service.h"

/*
	descr: constructor implicit
	in: -
	out: entitate Service
*/
Service::Service() {}

/*
	descr: constructor cu parametrii
	in: Repo r
	out: entitate Service cu atributul repo setat
*/
Service::Service(Repo r) {
	this->repo = r;
}

/*
	descr: constructor de copiere
	in: Service& s
	out: entitate Service
*/
Service::Service(const Service& s) {
	this->repo = s.repo;
}

/*
	descr: destructor
	in: -
	out -
*/
Service::~Service(){}

/*
	descr: getter pentru atributul repo
	in: -
	out: atributul repo
*/
Repo Service::getRepo() {
	return this->repo;
}

/*
	descr: setter pentru attributul repo
	in: Repo r
	out: -
*/
void Service::setRepo(Repo r) {
	this->repo = r;
}

/*
	descr: create
	in: char* name, Data data, unsigned int pret
	out: -
*/
void Service::create(char* name, Data data, unsigned int pret) {
	Produs p(name, data, pret);
	this->repo.addProdus(p);
}

/*
	descr: read
	in: int pos
	out: Produs &
*/
Produs& Service::read(int pos) {
	return this->repo.getProdus(pos);
}

/*
	descr: read all
	in: -
	out: Produs*
*/
Produs* Service::readAll() {
	return this->repo.getProduse();
}

/*
	descr: delete
	in: -
	out: -
*/
void Service::del(int pos) {
	this->repo.deleteProdus(pos);
}

/*
	descr: update nume
	in: int pos, Produs p
	out: -
*/
void Service::updateNume(int pos, char* nume) {
	Produs p = this->repo.getProdus(pos);
	p.setNume(nume);
	this->repo.updateProdus(pos, p);
}
/*
	descr: update data
	in: int pos, Produs p
	out: -
*/
void Service::updateData(int pos, Data data) {
	Produs p = this->repo.getProdus(pos);
	p.setData(data);
	this->repo.updateProdus(pos, p);
}
/*
	descr: update pret
	in: int pos, Produs p
	out: -
*/
void Service::updatePret(int pos, unsigned int pret) {
	Produs p = this->repo.getProdus(pos);
	p.setPret(pret);
	this->repo.updateProdus(pos, p);
}

/*
	descr: print
	in: -
	out: -
*/
void Service::print() {
	Produs* produse = this->repo.getProduse();
	for (int i = 0; i < this->repo.getSize(); i++) {
		cout << "pos: " << i << ", " << produse[i].toString() << endl;
	}
}


Service& Service::operator=(const Service& s) {
	if (this != &s) {
		this->setRepo(s.repo);
	}
	return *this;
}