#include <iostream>
#include "include/tendik.hpp"


tendik::tendik(int id, std::string nama, int dd, int mm, int yy, std::string npp, std::string unit)
		: person(id, nama, dd, mm, yy), npp(npp), unit(unit)
{
}

void tendik::setUnit(std::string unit)
{
	this->unit = unit;
}

std::string tendik::getUnit()
{
	return this->unit;
}


std::string tendik::getNPP()
{
	return this->npp;
}
