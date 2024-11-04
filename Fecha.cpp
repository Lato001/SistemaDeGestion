#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;

#include "Fecha.h"
#include "Menu.h"

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
    Menu menu;
    bool validacion = false;
    while (!validacion) {
        int input;
        Menu::setColor(7);
        cout << "Ingrese el dia: ";
        Menu::setColor(0);
        cin >> input;
        dia = input;
        Menu::setColor(7);
        cout << "Ingrese el mes: ";
        Menu::setColor(0);
        cin >> input;
        mes = input;
        Menu::setColor(7);
        cout << "Ingrese el anio: ";
        Menu::setColor(0);
        cin >> input;
        anio = input;
        validacion = validar();
        if (validacion) {
            Menu::setColor(2);
            cout << "La fecha se guardo correctamente" << endl;
        } else {

            menu.mensajeDeError("Error, Ingrese una fecha real");
        }
        Menu::setColor(7);
    }
}

bool Fecha::validar() {
    if (anio > 1800 && anio < 2025) {
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
    Menu::setColor(0);
    cout << dia << "/" << mes << "/" << anio << endl;
    Menu::setColor(7);
}

char* Fecha::toString() {
    char* buffer = new char[11];
    snprintf(buffer, 11, "%02d/%02d/%04d", dia, mes, anio);
    return buffer;
}
