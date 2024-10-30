#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

Persona::Persona()
{
    DNI = 0;
    nombre[0] = '\0';
    apellido[0]= '\0';
    email[0]= '\0';
    nTelefono = 0;
    localidad[0] = '\0';
}
Persona::Persona(int _DNI, const char* _nombre,const char* _apellido,const char* _email, int _nTelefono, const char* _localidad)
{
    DNI = _DNI;

    strncpy(nombre, _nombre, sizeof(nombre) - 1); // Copiar con seguridad
    nombre[sizeof(nombre) - 1] = '\0';

    strncpy(apellido, _apellido, sizeof(apellido) - 1); // Copiar con seguridad
    apellido[sizeof(apellido) - 1] = '\0';

    strncpy(email, _email, sizeof(email) - 1); // Copiar con seguridad
    email[sizeof(email) - 1] = '\0';

    nTelefono = _nTelefono;

    strncpy(localidad, _localidad, sizeof(localidad) - 1); // Copiar con seguridad
    localidad[sizeof(localidad) - 1] = '\0';
}

int Persona::getDNI(){return DNI;}
const char* Persona::getNombre(){return nombre;}
const char* Persona::getApellido(){return apellido;}
const char* Persona::getEmail(){return email;}
int Persona::getnTelefono(){return nTelefono;}
const char* Persona::getLocalidad(){return localidad;}


void Persona::setDNI(int _DNI){DNI = _DNI;}

void Persona::setNombre(const char* _nombre) {
    strncpy(nombre, _nombre, sizeof(nombre) - 1); // Copiar con seguridad
    nombre[sizeof(nombre) - 1] = '\0';
}
void Persona::setApellido(const char* _apellido) {
    strncpy(apellido, _apellido, sizeof(apellido) -1); // Copiar con seguridad
    apellido[sizeof(apellido) - 1] = '\0';
}
void Persona::setEmail(const char* _email)
{
strncpy(email, _email, sizeof(email) - 1); // Copiar con seguridad
    email[sizeof(email) - 1] = '\0';
}

void Persona::setnTelefono(int _nTelefono){nTelefono = _nTelefono;}

void Persona::setLocalidad(const char* _localidad) {
    strncpy(localidad, _localidad, sizeof(localidad) - 1); // Copiar con seguridad
    localidad[sizeof(localidad) - 1] = '\0';
}
void Persona::mostrarPersona(){
    cout<<"              DNI: "<<getDNI()<<endl;
    cout<< "              Nombre: " << getNombre()<<endl;
    cout<< "              Apellido: " << getApellido()<<endl;
    cout<<"              email: " << getEmail() << endl;
    cout<<"              N Telefono: " << getnTelefono() << endl;
    cout<< "              localidad: " << getLocalidad() <<endl;
}
    void Persona::cargarPersona(){
    int inputNumeros;
    char inputLetras[WORD];

    cout<<"Ingrese el DNI:"<<endl;
    cin >> inputNumeros;
    setDNI(inputNumeros);

    cout<<"Ingrese el Nombre:"<<endl;
    cin.ignore();
    cin.getline(inputLetras, WORD);
    setNombre(inputLetras);

    cout<<"Ingrese el Apellido:"<<endl;
    cin.getline(inputLetras, WORD);
    setApellido(inputLetras);

    cout<<"Ingrese el email"<<endl;
    cin.getline(inputLetras, WORD);
    setEmail(inputLetras);

    cout<< "Ingrese el telefono"<<endl;
    cin>> inputNumeros;
    setnTelefono(inputNumeros);
    cout<<"Ingrese la localidad"<<endl;
    cin.ignore();
    cin.getline(inputLetras, WORD);
    setLocalidad(inputLetras);
}
