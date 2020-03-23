#pragma once
#ifndef DATA_H
#define DATA_H

using namespace std;

#include <string>
// clasa Data a fost creata deoarece in functionalitatile care urmeaza sa le implementez trebuie sa compar date
class Data {
private:
	unsigned int zi;
	unsigned int luna;
	unsigned int an;
public:
	Data();
	Data(unsigned int z, unsigned int l, unsigned int a);
	Data(const Data& d);
	~Data();
	unsigned int getZi();
	unsigned int getLuna();
	unsigned int getAn();
	void setZi(unsigned int z);
	void setLuna(unsigned int l);
	void setAn(unsigned int a);

	Data& operator=(const Data& d);
	bool operator>(const Data& d);
	char* toString();

};

#endif;