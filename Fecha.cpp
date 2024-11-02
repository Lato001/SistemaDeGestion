#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;

#include "Fecha.h"

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    anio = 0;
}

Fecha::Fecha(int _dia, int _mes, int _anio) {
    dia = _dia;
    mes = _mes;
    anio = _anio;
}

int Fecha::getDia() {
    return dia;
}

int Fecha::getMes() {
    return mes;
}

int Fecha::getAnio() {
    return anio;
}

void Fecha::setDia(int _dia) {
    dia = _dia;
}

void Fecha::setMes(int _mes) {
    mes = _mes;
}

void Fecha::setAnio(int _anio) {
    anio = _anio;
}

void Fecha::cargarFecha() {
    bool validacion = false;
    while (!validacion) {
        int input;
        rlutil::setColor(rlutil::BLACK);
        cout << "Ingrese el dia: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> input;
        dia = input;
        rlutil::setColor(rlutil::BLACK);
        cout << "Ingrese el mes: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> input;
        mes = input;
        rlutil::setColor(rlutil::BLACK);
        cout << "Ingrese el anio: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> input;
        anio = input;
        validacion = validar();
        if (validacion) {
            rlutil::setColor(rlutil::GREEN);
            cout << "La fecha se guardo correctamente" << endl;
        } else {
            rlutil::setColor(rlutil::RED);
            cout << "Error, Ingrese una fecha real" << endl;
        }
        rlutil::setColor(rlutil::WHITE);
    }
}

bool Fecha::validar() {
    if (anio < 2025) {
        if (mes < 1 || mes > 12) {
            return false;
        }
        switch (mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return (dia >= 1 && dia <= 31);
            case 4:
            case 6:
            case 9:
            case 11:
                return (dia >= 1 && dia <= 30);
            case 2:
                return (dia <= 29);
            default:
                return false;
        }
    } else {
        return false;
    }
}

void Fecha::RestarDia() {
    dia--;
    if (!validar()) {
        mes--;
        if (mes < 1) {
            mes = 12;
            anio--;
        }
        if (mes != 2) {
            int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            dia = diasPorMes[mes - 1];
        }
    }
}

void Fecha::mostrarFecha() {
    rlutil::setColor(rlutil::BLACK);
    cout << dia << "/" << mes << "/" << anio << endl;
    rlutil::setColor(rlutil::WHITE);
}

char* Fecha::toString() {
    char* buffer = new char[11];
    snprintf(buffer, 11, "%02d/%02d/%04d", dia, mes, anio);
    return buffer;
}
