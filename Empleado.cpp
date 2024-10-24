#include <iostream>
#include <string>
using namespace std;

#include "Empleado.h"
#include "Persona.h"
#include "Fecha.h"

Empleado::Empleado()
{
    fechaDeIngreso;
    empleadoID = 0;
    asistencias = 0;
    vacacionesActivas = false;
}
Empleado::Empleado(int _DNI, const char* _nombre,const char* _apellido,const char* _email, int _nTelefono, const char* _localidad, Fecha _fechaDeIngreso, int _empleadoID, int _asistencias, bool _vacacionesActivas) : Persona(_DNI, _nombre, _apellido, _email, _nTelefono, _localidad)
{
fechaDeIngreso = _fechaDeIngreso;
empleadoID = _empleadoID;
asistencias = _asistencias;
vacacionesActivas = _vacacionesActivas;
}
int Empleado::getID(){return empleadoID;}
int Empleado::getAsistencias() {return asistencias;}
bool Empleado::getIsVacaciones() {return vacacionesActivas;}
Fecha Empleado::getFechaIngreso() {return fechaDeIngreso;}

void Empleado::setempleadoID(int _empleadoID){empleadoID = _empleadoID;}
void Empleado::setAsistencias(int _asistencias){asistencias = _asistencias;}
void Empleado::setvacacionesActivas(bool _vacacionesActivas){vacacionesActivas = _vacacionesActivas;}
void Empleado::setfechadeingreso (Fecha _fechaDeIngreso){fechaDeIngreso = _fechaDeIngreso;}

void Empleado::mostrarEmpleado()
{
    mostrarPersona();
    Empleado uno;
    Fecha una;
       cout << "Empleado ID: " << uno.getID() << endl;
    cout << "Fecha de Ingreso: " << una.toString() << endl;
    cout << "Asistencias: " << uno.getAsistencias() << endl;
    cout << "Vacaciones Activas: " << uno.getIsVacaciones() << endl;
}
