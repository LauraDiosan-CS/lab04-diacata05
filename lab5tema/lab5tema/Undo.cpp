#include "Undo.h" 

int Undo::numar = -1;
int Undo::op[MAX];
int Undo::poz[MAX];
int Undo::updateType[MAX];

Repo Undo::repo;

void Undo::addOp(int pos, Produs p) {
	numar++;
	op[numar] = add;
	repo.addProdus(p);
	poz[numar] = pos;
	updateType[numar] = -1;
}

void Undo::deleteOp(Produs p) {
	numar++;
	op[numar] = del;
	repo.addProdus(p);
	poz[numar] = -1;
	updateType[numar] = -1;
}

void Undo::updateOp(int pos, Produs p, int u) {
	numar++;
	op[numar] = update;
	repo.addProdus(p);
	updateType[numar] = u;
	poz[numar] = pos;
}

void Undo::undo(Service& s) {
	switch (op[numar]) {
	case add:
		cout << "Undo operatiune: adaugare pe pos " << poz[numar] << " a produsului " << endl;
		cout << repo.getProdus(poz[numar]).toString() << endl;
		s.del(poz[numar]);
		numar = numar - 2;
		break;
	case del: {
		cout << "Undo operatiune: stergere a produsului " << endl;
		cout << repo.getProdus(numar).toString() << endl;
		Produs last = repo.getProdus(numar);
		s.create(last.getNume(), last.getData(), last.getPret());
		numar = numar - 2;
		break;
	}
	case update:
	{
		cout << "Undo operatiune: update a produsului " << endl;
		cout << repo.getProdus(numar).toString() << endl;
		Produs last = repo.getProdus(numar);
		switch (updateType[numar]) {
		case nume:
			s.updateNume(poz[numar], last.getNume());
			break;
		case dataU:
			s.updateData(poz[numar], last.getData());
			break;
		case pret:
			s.updatePret(poz[numar], last.getPret());
			break;
		}
		numar = numar - 2;
		break;
	}
	default:
		cout << "Nicio operatie realizata!" << endl;
		break;
	}
}