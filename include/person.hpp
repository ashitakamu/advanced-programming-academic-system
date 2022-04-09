#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>

class person {
private:
	int id;
	std::string nama;
	int dd, mm, yy;

public:
	person(int id, std::string nama, int dd, int mm, int yy);

	void setId(int id);
	int getId();

	void setNama(std::string nama);
	std::string getNama();

	void setTglLahir(int dd, int mm, int yy);
	int getTglLahir();
	int getBulanLahir();
	int getTahunLahir();	
};


#endif
