#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include "include/person.hpp"

class dosen : public person {
private:
	std::string npp;
	std::string departemen;
	std::string pendidikan;
public:
	dosen(int id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, std::string pendidikan);

	std::string getNPP();
	void setNPP(std::string npp);

	std::string getDepartemen();
	void setDepartemen(std::string departemen);

	std::string getPendidikan();
	void setPendidikan(std::string pendidikan);
};

#endif 
