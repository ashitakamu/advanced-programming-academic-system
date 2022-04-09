#include <iostream>

#include "include/dosen.hpp"


dosen::dosen(int id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, std::string pendidikan)
		: person(id, nama, dd, mm, yy), npp(npp), departemen(departemen), pendidikan(pendidikan)
{
}
std::string dosen::getDepartemen(){
	return this -> departemen;
}
void dosen::setPendidikan(std::string pendidikan)
{
	this->pendidikan = pendidikan;
}
std::string dosen::getNPP(){
	return this->npp;
}

std::string dosen::getPendidikan()
{
	return this->pendidikan;
}

