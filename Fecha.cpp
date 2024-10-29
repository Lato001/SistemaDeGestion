#include <iostream>
#include <cstring>
using namespace std;

#include "Fecha.h"

Fecha::Fecha(){
    dia = 0;
    mes = 0;
    anio = 0;
}

Fecha::Fecha(int _dia, int _mes, int _anio){
    dia = _dia;
    mes = _mes;
    anio = _anio;
}


int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

void Fecha::setDia(int _dia){
    dia = _dia;
}

void Fecha::setMes(int _mes){
    mes = _mes;
}

void Fecha::setAnio(int _anio){
    anio = _anio;
}
void Fecha::cargarFecha(){
    int input;
    cout << "Ingrese el dia"<<endl;
    cin >> input;
    dia = input;
    cout << "Ingrese el mes"<<endl;
    cin >> input;
    mes = input;
    cout << "Ingrese el anio"<<endl;
    cin >> input;
    anio = input;
}
void Fecha :: mostrarFecha(){
    cout<< dia << "/" << mes << "/" << anio<<endl;
}
char* Fecha::toString() {
    char* buffer = new char[11];
    snprintf(buffer, 11, "%02d/%02d/%04d", dia, mes, anio);
    return buffer;
}


