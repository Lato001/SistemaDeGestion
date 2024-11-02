#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;

#include "Persona.h"

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
    rlutil::setColor(rlutil::BLACK);
    cout << "              DNI: " << getDNI() << endl;
    cout << "              Nombre: " << getNombre() << endl;
    cout << "              Apellido: " << getApellido() << endl;
    cout << "              Email: " << getEmail() << endl;
    cout << "              N Telefono: " << getnTelefono() << endl;
    cout << "              Localidad: " << getLocalidad() << endl;
    rlutil::setColor(rlutil::WHITE);
}

void Persona::cargarPersona() {
    int inputNumeros;
    char inputLetras[50];

    rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el DNI:" << endl;
       rlutil::setColor(rlutil::WHITE);
    cin >> inputNumeros;
    setDNI(inputNumeros);

   rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el Nombre:" << endl;
       rlutil::setColor(rlutil::WHITE);
    cin.ignore();
    cin.getline(inputLetras, 50);
    setNombre(inputLetras);

   rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el Apellido:" << endl;
       rlutil::setColor(rlutil::WHITE);
    cin.getline(inputLetras, 50);
    setApellido(inputLetras);

   rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el Email:" << endl;
       rlutil::setColor(rlutil::WHITE);
    cin.getline(inputLetras, 50);
    setEmail(inputLetras);

   rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el Telefono:" << endl;
       rlutil::setColor(rlutil::WHITE);
    cin >> inputNumeros;
    setnTelefono(inputNumeros);

   rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese la Localidad:" << endl;
    rlutil::setColor(rlutil::WHITE);
    cin.ignore();
    cin.getline(inputLetras, 50);
    setLocalidad(inputLetras);
}

