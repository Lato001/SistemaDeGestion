#include <iostream>
#include <string>
using namespace std;

#include "Persona.h"
#include "Empleado.h"
#include "Fecha.h"

Empleado::Empleado()
{
    fechaDeIngreso;
    empleadoID = 0;
    asistencias = 0;
    vacacionesActivas = false;
}
Empleado::Empleado(Fecha _fechaDeIngreso, int _empleadoID, int _asistencias, bool _vacacionesActivas){
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

void mostrarEmpleado()
{
    Empleado uno;
    Fecha una;
       cout << "Empleado ID: " << uno.getID() << endl;
    cout << "Fecha de Ingreso: " << una.toString() << endl;
    cout << "Asistencias: " << uno.getAsistencias() << endl;
    cout << "Vacaciones Activas: " << uno.getIsVacaciones() << endl;
}
