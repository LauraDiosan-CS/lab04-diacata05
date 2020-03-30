#include "Service.h"
#include "Undo.h"

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
	in: char* name, Data data, double pret
	out: -
*/
void Service::create(char* name, Data data, double pret) {
	Produs p(name, data, pret);
	Undo::addOp(this->repo.getSize(), p);
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
	Undo::deleteOp(this->repo.getProdus(pos));
	this->repo.deleteProdus(pos);
}

/*
	descr: update nume
	in: int pos, Produs p
	out: -
*/
void Service::updateNume(int pos, char* nume) {
	Produs p = this->repo.getProdus(pos);
	Undo::updateOp(pos, p, 0);
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
	Undo::updateOp(pos, p,1);
	p.setData(data);
	this->repo.updateProdus(pos, p);
}
/*
	descr: update pret
	in: int pos, Produs p
	out: -
*/
void Service::updatePret(int pos, double pret) {
	Produs p = this->repo.getProdus(pos);
	Undo::updateOp(pos, p,2);
	p.setPret(pret);
	this->repo.updateProdus(pos, p);
}

/*
	descr: print
	in: -
	out: -
*/
void Service::print() {
	int size = this->repo.getSize();
	if (size == 0) {
		cout << "Nu exista produse in repo!" << endl;
	}
	else {
		Produs* produse = this->repo.getProduse();
		for (int i = 0; i < size; i++) {
			cout << "pos: " << i << ", " << produse[i].toString() << endl;
		}
	}
}

/*
	descr: afisare produse readuse astazi pe stoc
	in: Data d
	out: -
*/
int Service::produseReaduseAstaziPeStoc() {
	Data d;
	int numarProduse = 0;
	Produs* produse = this->repo.getProduseDupaData(d.today(), numarProduse);
	if (numarProduse == 0) {
		cout << "Nu s-au gasit produse!" << endl;
		return numarProduse;
	}
	Data today = d.today();
	for (int i = 0; i < numarProduse; i++) {
		if (produse[i].getData().equals(today)) {
			cout << produse[i].toString() << endl;
		}
	}
	return numarProduse;
}

/*
	descr: reducere cu 10 % a produselor cu data anterioara unei date date
	in: Data d
	out: -
*/
void Service::reducereCu10Produse(Data d) {
	Produs* produse = this->repo.getProduse();
	int size = this->repo.getSize();
	if (size == 0) {
		cout << "Nu exista produse!" << endl;
	}
	
	for (int i = 0; i < size; i++) {
		if (d > produse[i].getData()) {
			double pretInitial = produse[i].getPret();
			double pretDupaReducere = ((90 * pretInitial) / 100);
			produse[i].setPret(pretDupaReducere);
			this->repo.updateProdus(i, produse[i]);
		}
	}

	cout << "Toate produsele anterioare datei de " << d.toString() << " au fost reduse!" << endl;
}


Service& Service::operator=(const Service& s) {
	if (this != &s) {
		this->setRepo(s.repo);
	}
	return *this;
}