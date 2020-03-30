#ifndef UI_H
#define UI_H

#include "Service.h"

class UI {
private:
	Service service;
public:
	UI();
	UI(Service s);
	UI(const UI& ui);
	~UI();

	Service getService();
	void setService(Service s);
	
	void afisareMeniu();
	void uiCreate();
	void uiRead();
	void uiDelete();
	void uiUpdate();
	void uiReadProduseReaduseAstaziPeStoc();
	void uiReducere10();
	void consola();

	double readPret();
	Data readData();
	char* readNume();

};

#endif


#pragma once