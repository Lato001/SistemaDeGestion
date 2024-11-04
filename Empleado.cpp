#include <iostream>
#include <string>
#include "rlutil.h"
using namespace std;

#include "Empleado.h"
#include "Persona.h"
#include "Fecha.h"
#include "ArchivoEmpleados.h"
#include "Menu.h"

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
       Menu::setColor(3);
    cout << "////////////////// ID EMPLEADO: "<< getID() <<" //////////////////"<<endl;
    mostrarPersona();
    Menu::setColor(3);
    cout<<"////////////////// Detalles en la empresa: "<<" //////////////////" <<endl;
    Menu::setColor(7);
    cout << "              Fecha de Ingreso: ";
    Menu::setColor(0);
    getFechaIngreso().mostrarFecha();;
    Menu::setColor(7);
    cout << "              Asistencias: ";
    Menu::setColor(0);
    cout<< getAsistencias() << endl;
    Menu::setColor(7);
    cout << "              Vacaciones Activas: ";
    Menu::setColor(0);
    cout<<getIsVacaciones() <<endl;
    Menu::setColor(7);
   //     rlutil::setColor(rlutil::CYAN);
  //  cout <<"//////////////////////////////////////////////////////////////"<< endl;

}
void Empleado::cargarEmpleado(){
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    int inputNumeros;
    char inputLetra;
    Fecha fechaACargar;

    cargarPersona();
       Menu::setColor(0);
    cout<<"Ingrese la Fecha de Ingreso: " <<endl;
       Menu::setColor(7);
    fechaACargar.cargarFecha();
    fechaDeIngreso = fechaACargar;
    empleadoID = (Empleados.CantidadRegistros()+1);
       Menu::setColor(0);
    cout<< "Ingrese las asistencias del empleado: " << endl;
       Menu::setColor(7);
    cin >> inputNumeros;
    asistencias = inputNumeros;
       Menu::setColor(0);
    cout<<"Esta en vacaciones S/N ? "<<endl;
      Menu::setColor(7);
    cin >> inputLetra;
    while(inputLetra != 'S' && inputLetra != 'N' ){
        Menu::setColor(4);
        cout<<"Opcion invalida" << endl;
        Menu::setColor(7);
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
