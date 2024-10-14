#include <iostream>
#include "Persona.h"
#include <string>
#include <cstring>
Persona::Persona()
{
    DNI = 0;
    nombre[0] = '\0';
    apellido[0]= '\0';
    email= "";
    localidad[0] = '\0';
}
Persona::Persona(int _DNI, const char* _nombre,const char* _apellido,string _email,const char* _localidad)
{
    DNI = _DNI;
    strncpy(nombre, _nombre, sizeof(nombre) - 1); // Copiar con seguridad
    nombre[sizeof(nombre) - 1] = '\0';
    strncpy(apellido, _apellido, sizeof(apellido) - 1); // Copiar con seguridad
    apellido[sizeof(apellido) - 1] = '\0';
    email = _email;
    strncpy(localidad, _localidad, sizeof(localidad) - 1); // Copiar con seguridad
    localidad[sizeof(localidad) - 1] = '\0';
}

int Persona::getDNI(){return DNI;}
string Persona::getEmail(){return email;}
const char* Persona::getNombre(){return nombre;}
const char* Persona::getApellido(){return apellido;}
const char* Persona::getLocalidad(){return localidad;}

void Persona::setDNI(int _DNI){DNI = _DNI;}
void Persona::setNombre(const char* _nombre) {
    strncpy(nombre, _nombre, sizeof(nombre) - 1); // Copiar con seguridad
    nombre[sizeof(nombre) - 1] = '\0';
}
void Persona::setApellido(const char* _apellido) {
    strncpy(apellido, _apellido, sizeof(apellido) - 1); // Copiar con seguridad
    apellido[sizeof(apellido) - 1] = '\0';
}
void Persona::setEmail(string _email){email = _email;}
void Persona::setLocalidad(const char* _localidad) {
    strncpy(localidad, _localidad, sizeof(localidad) - 1); // Copiar con seguridad
    localidad[sizeof(localidad) - 1] = '\0';
}
void Persona::mostrarPersona(){
    cout<<"DNI: "<<getDNI()<<" Nombre: " << getNombre() << " Apellido: " << getApellido()<<" email: " << getEmail() << " localidad: " << getLocalidad() <<endl;
}


using namespace std;
