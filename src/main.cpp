#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <unistd.h>
#include <stdlib.h>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matkul.hpp"

using namespace std;

string uname = "admin", pass = "admin", unameInput, passInput;
void defaultError(){
	cout << "Pilihan tidak tersedia!" << endl;
	sleep(3);
	system("cls || clear");
}

void login(){
	bool ulang = false, ulangTapiSelamatDatang = true;
	int i = 0, pilihan;
	while (ulangTapiSelamatDatang){
		system("cls || clear");
		cout << "Selamat Datang di Benedetta Academy" << endl;
		cout << "1. Keluar program" << endl;
		cout << "2. Masuk sebagai admin" << endl;
		cout << "Masukkan pilihan anda : "; cin >> pilihan;
		switch (pilihan){
		case 1:
			system("cls || clear");
			exit(0);
		case 2:
			ulangTapiSelamatDatang = false;
			ulang = true;
			break;
		default:
			defaultError();
		}
	}
	while (ulang){
		i++;
		system("cls || clear");
		cout << "Masukkan username (admin) : "; cin >> unameInput; cout << endl;
		cout << "Masukkan password (admin) : "; cin >> passInput; cout << endl;
		if ((uname.compare(unameInput) == 0) && (pass.compare(passInput) == 0)){
			ulang = false;
			break;
		}else if((uname.compare(unameInput) != 0) && (pass.compare(passInput) == 0)){
			cout << "Username anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else if ((uname.compare(unameInput) == 0) && (pass.compare(passInput) != 0)){
			cout << "Password anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else{
			cout << "Username dan password salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}
	}
}

int main(){
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;
	vector<matkul> recMatkul;

	int menu_terpilih;
	string nama, nrp, npp, departemen, pendidikan, unit, namaMatkul, kodeMatkul;
	int dd, mm, yy, tahunmasuk, semester, sksMatkul;
	set<string> matkulTerambil;
	int idMhs = 0, idDsn = 0, idTndk = 0, idMatkul = 0;
	int noID = 0;
	
	login();
	
	while(1) {
		cout << "Selamat datang di Benedetta Academy" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tendik" << endl;
		cout << "  4. Jumlah Matkul                : " << recMatkul.size() << " matkul" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  7. Tambah Matkul" << endl;
		cout << "  8. Tampilkan semua Matkul" <<endl;
		cout << "  9. Keluar" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;

		switch (menu_terpilih) {
			case 1:
				{
					if (recMatkul.empty()){
						cout << "Belum ada matkul ditambahkan!";
						sleep(3);
						system("cls || clear");
						break;
					}
					int pilihan;
					bool flag = true, flagMatkul = true;
					while (flag){
						system("cls || clear");
						idMhs++;
						cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;
						cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;
						cout << "Masukkan NRP : "; cin >> nrp; cout << endl;
						cout << "Masukkan Departemen : "; cin.ignore(); getline(cin, departemen); cout << endl;
						cout << "Masukkan Tahun Masuk : "; cin >> tahunmasuk; cout << endl;
						cout << "Masukkan Semester : "; cin >> semester; cout << endl << endl;

						for (int i = 0; i < recMatkul.size(); i++){
							cout << recMatkul[i].getIdMatkul() << ". Nama Matkul : " << recMatkul[i].getMatkul() << endl << endl;
						}
						while (flagMatkul){
							cout << "Masukkan ID matkul yang diambil : "; cin >> noID;
							cout << endl;
							
							matkulTerambil.insert(recMatkul[noID-1].getMatkul());
							cout << endl;
							cout << "Ingin mengambil matkul lagi?" << endl;
							cout << "1. Ya" << endl;
							cout << "2. Tidak" << endl;
							cout << "Pilihan anda : "; cin >> pilihan;
							switch (pilihan){
							case 1:
								continue;
							case 2:
								{
									flagMatkul = false;
									cout << "Matkul Mahasiswa " << nama << " berhasil ditambahkan!" << endl << endl;
									sleep(3);
								}
								break;
							default:
								defaultError();
								break;
							}	
						}
						system("cls || clear");
						mahasiswa mhs(idMhs, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semester, matkulTerambil);
						recMhs.push_back(mhs);
					
						cout << "Apakah anda ingin mengisi mahasiswa lagi?" << endl;
						cout << "  1. Ya" << endl;
						cout << "  2. Tidak" << endl;
						cout << "Pilihan anda : ";
						cin >> pilihan;
						if (pilihan == 1){
							continue;
						}else if(pilihan == 2){
							flag = false;
							system("cls || clear");
						}
					}
				}
				break;
			case 2:
				{
					int pilihan;
					bool flag = true;
					while (flag){
						system("cls || clear");
						idDsn++;
						cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;
						cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;
						cout << "Masukkan NPP : "; cin >> npp; cout << endl;
						cout << "Masukkan Departemen : "; cin.ignore(); getline(cin, departemen); cout << endl;
						cout << "Masukkan Pendidikan Terakhir : "; cin.ignore(); getline(cin, pendidikan); cout << endl;
				
						dosen dsn(idDsn,nama,dd,mm,yy,npp,departemen,pendidikan);
						recDosen.push_back(dsn);
						cout << "Dosen baru berhasil ditambahkan!" << endl << endl;

						cout << "Apakah anda ingin mengisi dosen lagi?" << endl;
						cout << "  1. Ya" << endl;
						cout << "  2. Tidak" << endl;
						cout << "Masukkan pilihan anda : ";
						cin >> pilihan;
						if (pilihan == 1){
							continue;
						}else if(pilihan == 2){
							flag = false;
							system("cls || clear");
						}
					}
				}
				break;
			case 3:
				{
					int pilihan;
					bool flag = true;
					while (flag)
					{
						system("cls || clear");
						idTndk++;
						cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;
						cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;
						cout << "Masukkan NPP : "; cin >> npp; cout << endl;
						cout << "Masukkan Unit : "; cin.ignore(); getline(cin, unit); cout << endl;
					
						tendik tndk(idTndk,nama,dd,mm,yy,npp,unit);
						recTendik.push_back(tndk);
						cout << "Tendik baru berhasil ditambahkan!" << endl << endl;

						cout << "Apakah anda ingin mengisi tendik lagi?" << endl;
						cout << "  1. Ya" << endl;
						cout << "  2. Tidak" << endl;
						cout << "Masukkan pilihan anda : ";
						cin >> pilihan;
						if (pilihan == 1){
							continue;
						}else if(pilihan == 2){
							flag = false;
							system("cls || clear");
						}
					}
				}
				break;
			case 4:
				{
					if (recMhs.empty()){
						system("cls || clear");
						cout << "Tidak ada Mahasiswa terdaftar!";
						sleep(3);
						system("cls || clear");
						break;
					}
					int pilihan;
					bool flag = true;
					while (flag){
						system("cls || clear");
						for (int i = 0; i < recMhs.size(); i++){
							cout << recMhs[i].getId() << ". Nama Mahasiswa : " << recMhs[i].getNama() << endl;
							cout << "   NRP : " << recMhs[i].getNRP() << endl << endl;
						}

						cout << "Masukkan ID Mahasiswa yang ingin dilihat detailnya : "; cin >> noID;
						system("cls || clear");
						cout << recMhs[noID-1].getId() << ". Nama Mahasiswa : " << recMhs[noID-1].getNama() << endl;
						cout << "   NRP : " << recMhs[noID-1].getNRP() << endl;
						cout << "   Tanggal Lahir : " << recMhs[noID-1].getTglLahir() << "/" << recMhs[noID-1].getBulanLahir() << "/" << recMhs[noID-1].getTahunLahir() << endl;
						cout << "   Departemen : " << recMhs[noID-1].getDepartemen() << endl;
						cout << "   Tahun Masuk : " << recMhs[noID-1].getTahunMasuk() << endl;
						cout << "   Semester : " << recMhs[noID-1].getSemester() << endl;
						cout << "   Matkul diambil : " << endl;
						set<string>::iterator it;		
						for (it = matkulTerambil.begin(); it != matkulTerambil.end(); it++){
							cout << "     " << *it << endl;
						}
						
						cout << endl;
						cout << "1. Kembali ke Daftar Mahasiswa " << endl;
						cout << "2. Kembali ke Menu Utama " << endl;
						cout << "3. Edit Detail Mahasiswa" << endl;
						cout << "Masukkan pilihan anda : "; cin >> pilihan;
						
						switch (pilihan){
						case 1:
							continue;
						case 2:
							{
								flag = false;
								system("cls || clear");
							}
							break;			
						case 3:
							{
								system("cls || clear");
								int uhuk;
								bool uhuk1 = true;
								while (uhuk1)
								{
									cout << "Data yang ingin diubah : " << endl;
									cout << "1. Nama" << endl;
									cout << "2. NRP" << endl;
									cout << "3. Tanggal Lahir" << endl;
									cout << "4. Departemen" << endl;
									cout << "5. Tahun Masuk" << endl;
									cout << "6. Semester" << endl;
									cout << "7. Matkul diambil" << endl;
									cout << "8. Kembali ke daftar mahasiswa" << endl;
									cout << "Masukkan pilihan : "; cin >> uhuk;
									switch (uhuk){
									case 1:
										{
											cout << "Masukkan nama baru : ";
											cin.ignore(); getline(cin, nama);
											recMhs[noID-1].setNama(nama);
											cout << "Nama berhasil diubah!";
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 2:
										{
											cout << "Masukkan NRP baru : ";
											cin.ignore(); cin >> nrp;
											recMhs[noID-1].setNRP(nrp);
											cout << "NRP berhasil dirubah!";
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 3:
										{
											cout << "Masukkan TTL baru (dd mm yy) : ";
											cin.ignore(); cin >> dd >> mm >> yy;
											recMhs[noID-1].setTglLahir(dd,mm,yy);
											cout << "TTL berhasil dirubah!";
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 4:
										{
											cout << "Masukkan departemen baru : ";
											cin.ignore(); getline(cin, departemen);
											recMhs[noID-1].setDepartemen(departemen);
											cout << "Departemen berhasil diubah!";
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 5:
										{
											cout << "Masukkan tahun masuk baru : ";
											cin.ignore(); cin >> tahunmasuk;
											recMhs[noID-1].setTahunMasuk(tahunmasuk);
											cout << "Tahun masuk berhasil diubah!";
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 6:
										{
											cout << "Masukkan Semester baru : ";
											cin.ignore(); cin >> semester;
											recMhs[noID-1].setSemester(semester);
											cout << "Semester berhasil diubah!";
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 7:
										{
											int choice;
											system("cls || clear");
											set<string>::iterator it;
											for (it = matkulTerambil.begin(); it != matkulTerambil.end(); it++){
												cout << *it << endl;
											}
											cout << "1. Menambah Matkul Mahasiswa " << recMhs[noID-1].getNama() << endl;
											cout << "2. Hapus semua matkul diambil" << endl;
											cout << "Pilihan anda : "; cin >> choice;
											switch(choice){
												case 1:
													{
														for (int i = 0; i < recMatkul.size(); i++){
															cout << recMatkul[i].getIdMatkul() << ". Nama Matkul : " << recMatkul[i].getMatkul() << endl << endl;
														}
														bool flagMatkul = true;
														while (flagMatkul){
															cout << "Masukkan ID matkul yang diambil : "; cin >> noID;
															cout << endl;
								
															matkulTerambil.insert(recMatkul[noID-1].getMatkul());
															cout << endl;
															cout << "Ingin mengambil matkul lagi?" << endl;
															cout << "1. Ya" << endl;
															cout << "2. Tidak" << endl;
															cout << "Pilihan anda : "; cin.ignore(); cin >> pilihan;
															switch (pilihan){
															case 1:
																continue;
															case 2:
																{
																	flagMatkul = false;
																	cout << "Matkul Mahasiswa " << nama << " berhasil ditambahkan!" << endl << endl;
																	sleep(3);
																	system("cls || clear");
																}
																break;
															default:
																defaultError();
																break;
															}	
														}
													}
													break;
												// case 2:
												// 	{
												// 		int matkulDihapus;
												// 		set<string>::iterator it;
												// 		for (it = matkulTerambil.begin(); it != matkulTerambil.end(); it++){
												// 			cout << *it << endl;
												// 		}
												// 		set<string>::iterator itr;
												// 		cout << "Masukkan matkul yang ingin dihapus : "; cin.ignore(); cin >> matkulDihapus;
												// 		itr = matkulTerambil.begin();
												// 		for (int i = 0; i < matkulDihapus; i++){
												// 			itr++;
												// 		}
												// 		matkulTerambil.erase(itr);
												// 		cout << "Matkul berhasil dihapus!";
												// 	}
												case 2:
													{
														matkulTerambil.clear();
														cout << "Matkul mahasiswa berhasil dihapus!" << endl;
														sleep(3);
														system("cls || clear");
													}
													break;
												default:
													{
														defaultError();
													}
													break;
												}
										}
										break;
									case 8:
										{
											uhuk1 = false;
											break;
										}
									default:
										{
											defaultError();
										}
										continue;
									}
								}
								break;
							}
						default:
							defaultError();
							continue;
						}
					}
				}
				break;
			case 5:
				{
					if (recDosen.empty()){
						system("cls || clear");
						cout << "Tidak ada Dosen terdaftar!";
						sleep(3);
						system("cls || clear");
						break;
					}
					int pilihan;
					bool flag = true;
					system("cls || clear");
					for (int i = 0; i < recDosen.size(); i++){
						cout << recDosen[i].getId() << ". Nama Dosen : " << recDosen[i].getNama() << endl;
						cout << "NRP : " << recDosen[i].getNPP() << endl << endl;
					}
					while (flag){
						cout << "Masukkan ID Dosen yang ingin dilihat detailnya : "; cin >> noID;
						system("cls || clear");
						cout << recDosen[noID-1].getId() << ". Nama Dosen : " << recDosen[noID-1].getNama() << endl;
						cout << "   NPP : " << recDosen[noID-1].getNPP() << endl;
						cout << "   Tanggal Lahir : " << recDosen[noID-1].getTglLahir() << "/" << recDosen[noID-1].getBulanLahir() << "/" << recDosen[noID-1].getTahunLahir() << endl;
						cout << "   Departemen : " << recDosen[noID-1].getDepartemen() << endl;
						cout << "   Pendidikan Terakhir : " << recDosen[noID-1].getPendidikan() << endl;

						cout << "1. Kembali ke Daftar Dosen " << endl;
						cout << "2. Kembali ke Menu Utama " << endl;
						cout << "3. Edit Detail Dosen" << endl;
						cout << "Masukkan pilihan anda : "; cin >> pilihan;
						
						switch (pilihan){
						case 1:
							continue;
						case 2:
							{
								flag = false;
								system("cls || clear");
							}
							break;		
						case 3:
							{
								system("cls || clear");
								int uhuk;
								bool uhuk1 = true;
								while (uhuk1)
								{
									cout << "Data yang ingin diubah : " << endl;
									cout << "1. Nama" << endl;
									cout << "2. NRP" << endl;
									cout << "3. Tanggal Lahir" << endl;
									cout << "4. Departemen" << endl;
									cout << "5. Pendidikan Terakhir" << endl;
									cout << "6. Kembali ke daftar dosen" << endl;
									cout << "Masukkan pilihan : "; cin >> uhuk;
									switch (uhuk){
									case 1:
										{
											cout << "Masukkan nama baru : ";
											cin.ignore(); getline(cin, nama);
											recDosen[noID-1].setNama(nama);
											cout << "Nama berhasil diubah!";
											uhuk1 = false;
										}
										break;
									case 2:
										{
											cout << "Masukkan NPP baru : ";
											cin.ignore(); cin >> npp;
											recDosen[noID-1].setNPP(npp);
											cout << "NRP berhasil dirubah!";
											uhuk1 = false;
										}
										break;
									case 3:
										{
											cout << "Masukkan TTL baru (dd mm yy) : ";
											cin.ignore(); cin >> dd >> mm >> yy;
											recDosen[noID-1].setTglLahir(dd,mm,yy);
											cout << "TTL berhasil dirubah!";
											uhuk1 = false;
										}
										break;
									case 4:
										{
											cout << "Masukkan departemen baru : ";
											cin.ignore(); getline(cin, departemen);
											recDosen[noID-1].setDepartemen(departemen);
											cout << "Departemen berhasil diubah!";
											uhuk1 = false;
										}
										break;
									case 5:
										{
											cout << "Masukkan pendidikan terakhir baru : ";
											cin.ignore(); cin >> pendidikan;
											recDosen[noID-1].setPendidikan(pendidikan);
											cout << "Pendidikan terakhir berhasil diubah!";
											uhuk1 = false;
										}
										break;
									case 6:
										{
											uhuk1 = false;
											break;
										}
									default:
										{
											defaultError();
										}
										continue;
									}
								}
								break;
							}
						default:
							defaultError();
							continue;
						}
					}
				}
				break;
			case 6:
				{
					if (recTendik.empty()){
						system("cls || clear");
						cout << "Tidak ada Tendik terdaftar!";
						sleep(3);
						system("cls || clear");
						break;
					}
					int pilihan;
					bool flag = true;
					system("cls || clear");
					for (int i = 0; i < recTendik.size(); i++){
						cout << recTendik[i].getId() << ". Nama Tendik : " << recTendik[i].getNama() << endl;
						cout << "NPP : " << recTendik[i].getNPP() << endl << endl;
					}
					while (flag){
						cout << "Masukkan ID Tendik yang ingin dilihat detailnya : "; cin >> noID;
						system("cls || clear");
						cout << recTendik[noID-1].getId() << ". Nama Tendik : " << recTendik[noID-1].getNama() << endl;
						cout << "   NPP : " << recTendik[noID-1].getNPP() << endl;
						cout << "   Tanggal Lahir : " << recTendik[noID-1].getTglLahir() << "/" << recTendik[noID-1].getBulanLahir() << "/" << recTendik[noID-1].getTahunLahir() << endl;
						cout << "   Unit : " << recTendik[noID-1].getUnit() << endl;
						
						cout << "1. Kembali ke Daftar Tendik " << endl;
						cout << "2. Kembali ke Menu Utama " << endl;
						cout << "3. Edit Detail Tendik" << endl;
						cout << "Masukkan pilihan anda : "; cin >> pilihan;
						
						switch (pilihan){
						case 1:
							continue;
						case 2:
							{
								flag = false;
								system("cls || clear");
							}
							break;			
						case 3:
							{
								system("cls || clear");
								int uhuk;
								bool uhuk1 = true;
								while (uhuk1)
								{
									cout << "Data yang ingin diubah : " << endl;
									cout << "1. Nama" << endl;
									cout << "2. NPP" << endl;
									cout << "3. Tanggal Lahir" << endl;
									cout << "4. Unit" << endl;
									cout << "5. Kembali ke daftar tendik" << endl;
									cout << "Masukkan pilihan : "; cin >> uhuk;
									switch (uhuk){
									case 1:
										{
											cout << "Masukkan nama baru : ";
											cin.ignore(); getline(cin, nama);
											recTendik[noID-1].setNama(nama);
											cout << "Nama berhasil diubah!" << endl;
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 2:
										{
											cout << "Masukkan NPP baru : ";
											cin.ignore(); cin >> npp;
											recTendik[noID-1].setNPP(npp);
											cout << "NRP berhasil dirubah!" << endl;
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 3:
										{
											cout << "Masukkan TTL baru (dd mm yy) : ";
											cin.ignore(); cin >> dd >> mm >> yy;
											recTendik[noID-1].setTglLahir(dd,mm,yy);
											cout << "TTL berhasil dirubah!" << endl;
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 4:
										{
											cout << "Masukkan unit baru : ";
											cin.ignore(); getline(cin, unit);
											recTendik[noID-1].setUnit(unit);
											cout << "Unit berhasil diubah!" << endl;
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 5:
										{
											uhuk1 = false;
											break;
										}
									default:
										{
											defaultError();
										}
										continue;
									}
								}
							}
							break;
						default:
							defaultError();
							continue;
						}
					}
				}
				break;
			case 7:
				{
					int pilihan;
					bool flag = true;
					while (flag){
						system("cls || clear");
						idMatkul++;
						cout << "Masukkan Nama Mata Kuliah : "; cin.ignore(); getline(cin, namaMatkul); cout << endl;
						cout << "Masukkan Kode Matkul : "; cin >> kodeMatkul; cout << endl;
						cout << "Masukkan SKS Matkul : "; cin >> sksMatkul; cout << endl;

						matkul mtkl(idMatkul, namaMatkul, kodeMatkul, sksMatkul);
						recMatkul.push_back(mtkl);

						cout << "Apakah anda ingin mengisi matkul lagi?" << endl;
						cout << "  1. Ya" << endl;
						cout << "  2. Tidak" << endl;
						cout << "Masukkan pilihan anda : ";
						cin >> pilihan;
						if (pilihan == 1){
							continue;
						}else if(pilihan == 2){
							flag = false;
							system("cls || clear");
						}
					}
					break;
				}
				break;
			case 8:
				{
					if (recMatkul.empty()){
						system("cls || clear");
						cout << "Tidak ada Matkul terdaftar!";
						sleep(3);
						system("cls || clear");
						break;
					}
					int pilihan;
					bool flag = true;
					while (flag){
						system("cls || clear");
						for (int i = 0; i < recMatkul.size(); i++){
							cout << recMatkul[i].getIdMatkul() << ". Nama Matkul : " << recMatkul[i].getMatkul() << endl << endl;
						}

						cout << "Masukkan ID Matkul yang ingin dilihat detailnya : "; cin >> noID; 
						system("cls || clear");
						cout << recMatkul[noID-1].getIdMatkul() << ". Nama Matkul : " << recMatkul[noID-1].getMatkul() << endl;
						cout << "   Kode Matkul : " << recMatkul[noID-1].getKodeMatkul() << endl;
						cout << "   SKS Matkul : " << recMatkul[noID-1].getSKSMatkul() << endl << endl;

						cout << "1. Kembali ke Daftar Matkul " << endl;
						cout << "2. Kembali ke Menu Utama " << endl;
						cout << "3. Edit Detail Matkul" << endl;
						cout << "Masukkan pilihan anda : "; cin >> pilihan;

						switch (pilihan){
						case 1:
							continue;
						case 2:
							{
								flag = false;
								system("cls || clear");
							}
							break;
						case 3:
							{
								system("cls || clear");
								int uhuk;
								bool uhuk1 = true;
								while (uhuk1){
									cout << "Data yang ingin diubah : " << endl;
									cout << "1. Nama Matkul" << endl;
									cout << "2. Kode Matkul" << endl;
									cout << "3. SKS Matkul" << endl;
									cout << "4. Kembali ke menu utama" << endl;
									cout << "Masukkan pilihan : "; cin >> uhuk;
									switch (uhuk){
									case 1:
										{
											cout << "Masukkan nama matkul baru : ";
											cin.ignore(); getline(cin, namaMatkul);
											recMatkul[noID-1].setMatkul(namaMatkul);
											cout << "Nama matkul berhasil diubah!" << endl;
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 2:
										{
											cout << "Masukkan kode matkul baru : ";
											cin.ignore(); cin >> kodeMatkul;
											recMatkul[noID-1].setKodeMatkul(kodeMatkul);
											cout << "Kode Matkul berhasil diubah!" << endl;
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 3:
										{
											cout << "Masukkan SKS Matkul baru : ";
											cin.ignore(); cin >> sksMatkul;
											recMatkul[noID-1].setSKSMatkul(sksMatkul);
											cout << "SKS Matkul berhasil diubah!" << endl;
											sleep(3);
											uhuk1 = false;
										}
										break;
									case 4:
										{
											uhuk1 = false;
											break;
										}
									default:
										defaultError();
										break;
									}
								}
							}
							break;
						default:
							defaultError();
							break;
						}

					}
					
				}
				break;
			case 9:
				{
					system("cls || clear");
					login();
				}
				break;
			default:
				{
					defaultError();
				}
				break;
		}
	}
	return 0;
}
