#include <iostream>
#include "Persona.h"

Persona::Persona()
{
    DNI = 0;
    nombre = "";
    apellido= "";
    email= "";
    localidad= "";
}
Persona::Persona(int _DNI, string _nombre,string _apellido,string _email,string _localidad)
{
    DNI = _DNI;
    nombre = _nombre;
    apellido = _apellido;
    email = _email;
    localidad = _localidad;
}

int Persona::getDNI(){return DNI;}
string Persona::getEmail(){return email;}
string Persona::getNombre(){return nombre;}
string Persona::getApellido(){return apellido;}
string Persona::getLocalidad(){return localidad;}

void Persona::setDNI(int _DNI){DNI = _DNI;}
void Persona::setNombre(string _nombre){nombre = _nombre;}
void Persona::setApellido(string _apellido){apellido = _apellido;}
void Persona::setEmail(string _email){email = _email;}
void Persona::setLocalidad(string _localidad){localidad = _localidad;}
void Persona::mostrarPersona(){
    cout<<"DNI: "<<getDNI()<<" Nombre: " << getNombre() << " Apellido: " << getApellido()<<" email: " << getEmail() << " localidad: " << getLocalidad() <<endl;
}


using namespace std;
