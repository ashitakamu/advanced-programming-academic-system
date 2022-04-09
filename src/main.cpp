#include <iostream>
#include <vector>
#include <stdlib.h>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

int main(){
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;
	string nama, nrp, npp, departemen, pendidikan, unit;
	int dd, mm, yy, tahunmasuk;
	int idMhs = 0, idDsn = 0, idTndk = 0;
	int noID = 0;


	while(1) {
		cout << "Selamat datang di Universitas X" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tendik" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  7. Keluar Program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;

		switch (menu_terpilih) {
			case 1:
				{
					int pilihan;
					bool flag = true;
					while (flag){
						system("cls || clear");
						idMhs++;
						cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;
						cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;
						cout << "Masukkan NRP : "; cin >> nrp; cout << endl;
						cout << "Masukkan Departemen : "; cin.ignore(); getline(cin, departemen); cout << endl;
						cout << "Masukkan Tahun Masuk : "; cin >> tahunmasuk; cout << endl;
				
						mahasiswa mhs(idMhs,nama,dd,mm,yy,nrp,departemen,tahunmasuk);
						recMhs.push_back(mhs);
					
						cout << "Apakah anda ingin mengisi mahasiswa lagi?" << endl;
						cout << "  1. Ya" << endl;
						cout << "  2. Tidak" << endl;
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
						cout << "Dosen baru berhasil ditambahkan!";

						cout << "Apakah anda ingin mengisi dosen lagi?" << endl;
						cout << "  1. Ya" << endl;
						cout << "  2. Tidak" << endl;
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
						cout << "Tendik baru berhasil ditambahkan!";

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
					int pilihan;
					bool flag = true;
					system("cls || clear");
					for (int i = 0; i < recMhs.size(); i++){
						cout << recMhs[i].getId() << ". Nama Mahasiswa : " << recMhs[i].getNama() << endl;
						cout << "NRP : " << recMhs[i].getNRP() << endl << endl;
					}
					while (flag){
						cout << "Masukkan ID Mahasiswa yang ingin dilihat detailnya : "; cin >> noID;
						cout << endl;
						cout << recMhs[noID-1].getId() << ". Nama Mahasiswa : " << recMhs[noID-1].getNama() << endl;
						cout << "NRP : " << recMhs[noID-1].getNRP() << endl;
						cout << "Tanggal Lahir : " << recMhs[noID-1].getTglLahir() << "/" << recMhs[noID-1].getBulanLahir() << "/" << recMhs[noID-1].getTahunLahir() << endl;
						cout << "Departemen : " << recMhs[noID-1].getDepartemen() << endl;
						cout << "Tahun Masuk : " << recMhs[noID-1].getTahunMasuk() << endl << endl;

						cout << "1. Kembali ke Daftar Mahasiswa " << endl;
						cout << "2. Kembali ke Menu Utama " << endl;
						cout << "Masukkan pilihan anda : "; cin >> pilihan;
						if (pilihan == 1){
							continue;
						}else if(pilihan == 2){
							flag = false;
							system("cls || clear");
						}
					}
				}
				break;
			case 5:
				{
					int pilihan;
					bool flag = true;
					system("cls || clear");
					for (int i = 0; i < recDosen.size(); i++){
						cout << recDosen[i].getId() << ". Nama Dosen : " << recDosen[i].getNama() << endl;
						cout << "NRP : " << recDosen[i].getNPP() << endl << endl;
					}
					while (flag){
						cout << "Masukkan ID Dosen yang ingin dilihat detailnya : "; cin >> noID;
						cout << endl;
						cout << recDosen[noID-1].getId() << ". Nama Dosen : " << recDosen[noID-1].getNama() << endl;
						cout << "NPP : " << recDosen[noID-1].getNPP() << endl;
						cout << "Tanggal Lahir : " << recDosen[noID-1].getTglLahir() << "/" << recDosen[noID-1].getBulanLahir() << "/" << recDosen[noID-1].getTahunLahir() << endl;
						cout << "Departemen : " << recDosen[noID-1].getDepartemen() << endl;
						cout << "Pendidikan Terakhir : " << recDosen[noID-1].getPendidikan() << endl;

						cout << "1. Kembali ke Daftar Dosen " << endl;
						cout << "2. Kembali ke Menu Utama " << endl;
						cout << "Masukkan pilihan anda : "; cin >> pilihan;
						if (pilihan == 1){
							continue;
						}else if(pilihan == 2){
							flag = false;
							system("cls || clear");
						}
					}
				}
				break;
			case 6:
				{
					int pilihan;
					bool flag = true;
					system("cls || clear");
					for (int i = 0; i < recTendik.size(); i++){
						cout << recTendik[i].getId() << ". Nama Dosen : " << recTendik[i].getNama() << endl;
						cout << "NPP : " << recTendik[i].getNPP() << endl << endl;
					}
					while (flag){
						cout << "Masukkan ID Tendik yang ingin dilihat detailnya : "; cin >> noID;
						cout << endl;
						cout << recTendik[noID-1].getId() << ". Nama Tendik : " << recTendik[noID-1].getNama() << endl;
						cout << "NPP : " << recTendik[noID-1].getNPP() << endl;
						cout << "Tanggal Lahir : " << recTendik[noID-1].getTglLahir() << "/" << recTendik[noID-1].getBulanLahir() << "/" << recTendik[noID-1].getTahunLahir() << endl;
						cout << "Unit : " << recTendik[noID-1].getUnit() << endl;
						cout << "1. Kembali ke Daftar Tendik " << endl;
						cout << "2. Kembali ke Menu Utama " << endl;
						cout << "Masukkan pilihan anda : "; cin >> pilihan;
						if (pilihan == 1){
							continue;
						}else if(pilihan == 2){
							flag = false;
							system("cls || clear");
						}
					}
				}
				break;
			case 7:
				{
					return 0;
				}
			default:
				{
					cout << "Pilihan yang anda masukkan tidak sesuai!" << endl;
				}
				break;
		}
	}
	return 0;
}
