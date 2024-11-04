#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;

#include "Persona.h"
#include "Menu.h"

Persona::Persona() {
    DNI = 0;
    nombre[0] = '\0';
    apellido[0] = '\0';
    email[0] = '\0';
    nTelefono = 0;
    localidad[0] = '\0';
}

Persona::Persona(int _DNI, const char* _nombre, const char* _apellido, const char* _email, int _nTelefono, const char* _localidad) {
    DNI = _DNI;

    strncpy(nombre, _nombre, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';

    strncpy(apellido, _apellido, sizeof(apellido) - 1);
    apellido[sizeof(apellido) - 1] = '\0';

    strncpy(email, _email, sizeof(email) - 1);
    email[sizeof(email) - 1] = '\0';

    nTelefono = _nTelefono;

    strncpy(localidad, _localidad, sizeof(localidad) - 1);
    localidad[sizeof(localidad) - 1] = '\0';
}

int Persona::getDNI() { return DNI; }
const char* Persona::getNombre() { return nombre; }
const char* Persona::getApellido() { return apellido; }
const char* Persona::getEmail() { return email; }
int Persona::getnTelefono() { return nTelefono; }
const char* Persona::getLocalidad() { return localidad; }

void Persona::setDNI(int _DNI) { DNI = _DNI; }

void Persona::setNombre(const char* _nombre) {
    strncpy(nombre, _nombre, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
}
void Persona::setApellido(const char* _apellido) {
    strncpy(apellido, _apellido, sizeof(apellido) - 1);
    apellido[sizeof(apellido) - 1] = '\0';
}
void Persona::setEmail(const char* _email) {
    strncpy(email, _email, sizeof(email) - 1);
    email[sizeof(email) - 1] = '\0';
}

void Persona::setnTelefono(int _nTelefono) { nTelefono = _nTelefono; }

void Persona::setLocalidad(const char* _localidad) {
    strncpy(localidad, _localidad, sizeof(localidad) - 1);
    localidad[sizeof(localidad) - 1] = '\0';
}

void Persona::mostrarPersona() {
    Menu::setColor(0);
    cout << "              DNI: " << getDNI() << endl;
    cout << "              Nombre: " << getNombre() << endl;
    cout << "              Apellido: " << getApellido() << endl;
    cout << "              Email: " << getEmail() << endl;
    cout << "              N Telefono: " << getnTelefono() << endl;
    cout << "              Localidad: " << getLocalidad() << endl;
    Menu::setColor(7);
}

void Persona::cargarPersona() {
    int inputNumeros;
    char inputLetras[50];

    Menu::setColor(0);
    cout << "Ingrese el DNI:" << endl;
    Menu::setColor(7);
    cin >> inputNumeros;
    setDNI(inputNumeros);

   Menu::setColor(0);
    cout << "Ingrese el Nombre:" << endl;
    Menu::setColor(7);
    cin.ignore();
    cin.getline(inputLetras, 50);
    setNombre(inputLetras);

   Menu::setColor(0);
    cout << "Ingrese el Apellido:" << endl;
    Menu::setColor(7);
    cin.getline(inputLetras, 50);
    setApellido(inputLetras);

   Menu::setColor(0);
    cout << "Ingrese el Email:" << endl;
    Menu::setColor(7);
    cin.getline(inputLetras, 50);
    setEmail(inputLetras);

   Menu::setColor(0);
    cout << "Ingrese el Telefono:" << endl;
   Menu::setColor(7);
    cin >> inputNumeros;
    setnTelefono(inputNumeros);

   Menu::setColor(0);
    cout << "Ingrese la Localidad:" << endl;
   Menu::setColor(7);
    cin.ignore();
    cin.getline(inputLetras, 50);
    setLocalidad(inputLetras);
}

