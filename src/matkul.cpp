#include <iostream>
#include "include/matkul.hpp"

matkul::matkul(int idMatkul, std::string namaMatkul, std::string kodeMatkul, int sksMatkul)
		: idMatkul(idMatkul), namaMatkul(namaMatkul), kodeMatkul(kodeMatkul), sksMatkul(sksMatkul)
{
}
void matkul::setIdMatkul(int idMatkul){
    this->idMatkul = idMatkul;
}
int matkul::getIdMatkul(){
    return this->idMatkul;
}

void matkul::setMatkul(std::string namaMatkul){
    this->namaMatkul = namaMatkul;
}
std::string matkul::getMatkul(){
    return this->namaMatkul;
}

void matkul::setKodeMatkul(std::string kodeMatkul){
    this->kodeMatkul = kodeMatkul;
}
std::string matkul::getKodeMatkul(){
    return this->kodeMatkul;
}
void matkul::setSKSMatkul(int sksMatkul){
    this->sksMatkul;
}
int matkul::getSKSMatkul(){
    return this->sksMatkul;
}