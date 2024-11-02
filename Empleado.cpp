#include <iostream>
#include <string>
#include "rlutil.h"
using namespace std;

#include "Empleado.h"
#include "Persona.h"
#include "Fecha.h"
#include "ArchivoEmpleados.h"

Empleado::Empleado()
{
    fechaDeIngreso;
    empleadoID = 0;
    asistencias = 0;
    vacacionesActivas = false;
    sueldo = 0;
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
float Empleado::getSueldo(){return sueldo;}

void Empleado::setempleadoID(int _empleadoID){empleadoID = _empleadoID;}
void Empleado::setAsistencias(int _asistencias){asistencias = _asistencias;}
void Empleado::setvacacionesActivas(bool _vacacionesActivas){vacacionesActivas = _vacacionesActivas;}
void Empleado::setfechadeingreso (Fecha _fechaDeIngreso){fechaDeIngreso = _fechaDeIngreso;}
void Empleado::setSueldo(float _sueldo){sueldo = _sueldo;}
void Empleado::mostrarEmpleado()
{
       rlutil::setColor(rlutil::CYAN);
    cout << "////////////////// ID EMPLEADO: "<< getID() <<" //////////////////"<<endl;
    mostrarPersona();
    rlutil::setColor(rlutil::CYAN);
    cout<<"////////////////// Detalles en la empresa: "<<" //////////////////" <<endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "              Fecha de Ingreso: ";
    rlutil::setColor(rlutil::BLACK);
    getFechaIngreso().mostrarFecha();;
    rlutil::setColor(rlutil::WHITE);
    cout << "              Asistencias: ";
    rlutil::setColor(rlutil::BLACK);
    cout<< getAsistencias() << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "              Vacaciones Activas: ";
    rlutil::setColor(rlutil::BLACK);
    cout<<getIsVacaciones() <<endl;
    rlutil::setColor(rlutil::WHITE);
   //     rlutil::setColor(rlutil::CYAN);
  //  cout <<"//////////////////////////////////////////////////////////////"<< endl;

}
void Empleado::cargarEmpleado(){
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    int inputNumeros;
    char inputLetra;
    Fecha fechaACargar;

    cargarPersona();
       rlutil::setColor(rlutil::BLACK);
    cout<<"Ingrese la Fecha de Ingreso: " <<endl;
       rlutil::setColor(rlutil::WHITE);
    fechaACargar.cargarFecha();
    fechaDeIngreso = fechaACargar;
    empleadoID = (Empleados.CantidadRegistros()+1);
       rlutil::setColor(rlutil::BLACK);
    cout<< "Ingrese las asistencias del empleado: " << endl;
       rlutil::setColor(rlutil::WHITE);
    cin >> inputNumeros;
    asistencias = inputNumeros;
       rlutil::setColor(rlutil::BLACK);
    cout<<"Esta en vacaciones S/N ? "<<endl;
       rlutil::setColor(rlutil::WHITE);
    cin >> inputLetra;
    while(inputLetra != 'S' && inputLetra != 'N' ){
        rlutil::setColor(rlutil::RED);
        cout<<"Opcion invalida" << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        cin >> inputLetra;
    }
    if(inputLetra == 'S'){
        vacacionesActivas = true;
    }else{
        vacacionesActivas = false;
    }

}
