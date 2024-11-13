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
    Menu menu;
   menu.setColor(7);
    cout << "              DNI: ";
    menu.setColor(0);
    cout << getDNI() << endl;
    menu.setColor(7);
    cout << "              Nombre: ";
    menu.setColor(0);
    cout << getNombre() << endl;
    menu.setColor(7);
    cout << "              Apellido: ";
    menu.setColor(0);
    cout << getApellido() << endl;
    menu.setColor(7);
    cout << "              Email: ";
    menu.setColor(0);
    cout << getEmail() << endl;
    menu.setColor(7);
    cout << "              N Telefono: ";
    menu.setColor(0);
    cout << getnTelefono() << endl;
    menu.setColor(7);
    cout << "              Localidad: ";
    menu.setColor(0);
    cout << getLocalidad() << endl<<endl;
    menu.setColor(7);
}

void Persona::cargarPersona()
{
    Menu menu;

    int inputNumeros;
    char inputLetras[50];

    menu.setColor(7);
    cout << "0. Cancelar y volver al menu anterior "<<endl<<endl;

    cout << "Ingrese el DNI:" << endl;
    menu.setColor(0);
    cin >> inputNumeros;
    menu.setColor(7);
    if (inputNumeros == 0)
        {
            system ("cls");
            menu.mEmpleados();
        }
    setDNI(inputNumeros);


    menu.setColor(7);
    cout << "Ingrese el Nombre:" << endl;
    menu.setColor(0);
    cin.ignore();
    cin.getline(inputLetras, 50);
    if (strcmp(inputLetras, "0") == 0)
        {
            system ("cls");
            menu.mEmpleados();
        }
    setNombre(inputLetras);

   menu.setColor(7);
    cout << "Ingrese el Apellido:" << endl;
    menu.setColor(0);
    cin.getline(inputLetras, 50);
        menu.setColor(7);
        if (strcmp(inputLetras, "0") == 0)
        {
            system ("cls");
            menu.mEmpleados();
        }
    setApellido(inputLetras);


    menu.setColor(7);
    cout << "Ingrese el Email:" << endl;
    menu.setColor(0);
    cin.getline(inputLetras, 50);
    if (strcmp(inputLetras, "0") == 0)
    {
        system ("cls");
        menu.mEmpleados();
    }
    setEmail(inputLetras);

   menu.setColor(7);
    cout << "Ingrese el Telefono:" << endl;
   menu.setColor(0);
    cin >> inputNumeros;
    if (inputNumeros == 0)
        {
            system ("cls");
            menu.mEmpleados();

        }
    setnTelefono(inputNumeros);


   menu.setColor(7);
    cout << "Ingrese la Localidad:" << endl;
   menu.setColor(0);
    cin.ignore();
    cin.getline(inputLetras, 50);
    if (strcmp(inputLetras, "0") == 0)
        {
            system ("cls");
            menu.mEmpleados();
        }
    setLocalidad(inputLetras);
}

