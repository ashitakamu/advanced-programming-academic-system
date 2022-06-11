#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__


#include <iostream>
#include <set>
#include <string>
#include "include/person.hpp"

class mahasiswa : public person {
private:
	std::string nrp;
	std::string departemen;
	int tahunmasuk;
	int semesterke;
	int skslulus;
	float ipk;
	std::set<std::string> matkulDiambil;
	std::vector<float> ips;

public:
	mahasiswa(int id, std::string nama, int dd, int mm, int yy, std::string nrp, std::string departemen, int tahunmasuk, int semesterke, std::set<std::string> matkulDiambil);
	std::string getNRP();
	void setNRP(std::string newNRP);

	std::string getDepartemen();
	void setDepartemen(std::string newDepartemen);

	void setSemester(int semesterke);
	int getSemester();

	void setTahunMasuk(int tahunmasuk);
	int getTahunMasuk();
	
	// void setSKSLulus(int skslulus);
	// int getSKSLulus();
	
	// float getIPK();
	// void setIPK(float ips);
	// void hitungIPK();

	// void setIPS(int semester, float ips);
	// float getIPS(int semester);
	// std::vector<float> getAllIPS();

	void setMatkulDiambil(std::string matkul);
	std::set<std::string> getMatkulDiambil();
};

#endif
