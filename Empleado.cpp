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
    Menu::setColor(7);
    cout << "      ID EMPLEADO: ";
    Menu::setColor(0);
    cout << getID()<<endl;
    mostrarPersona();
    cout<<"          Detalles en la empresa:"<<endl;
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
    if (getIsVacaciones() == 1 )
    {
    cout<<"Si " <<endl;
    }
    else{
        cout<<"No "<<endl;
    }
    Menu::setColor(7);
    cout<<"              Sueldo: "<<getSueldo()<<endl;

}
void Empleado::cargarEmpleado(){
    Menu menu;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    int inputNumeros;
    char inputLetra;
    float inputSueldo=0;
    Fecha fechaACargar;

    cargarPersona();
       Menu::setColor(7);
    cout<<"Ingrese la Fecha de Ingreso: " <<endl;
       Menu::setColor(0);
    fechaACargar.cargarFecha();
    fechaDeIngreso = fechaACargar;

    if(Empleados.CantidadRegistros() == 0){
        empleadoID = 1;
    }else{

        empleadoID = Empleados.Leer((Empleados.CantidadRegistros()-1)).getID() + 1;
    }
    Menu::setColor(7);
    cout<< "Ingrese las asistencias del empleado: " << endl;
       Menu::setColor(0);
    cin >> inputNumeros;
    asistencias = inputNumeros;
    Menu::setColor(7);

    cout << "Esta en vacaciones S/N? " << endl;
       Menu::setColor(0);
    cin >> inputLetra;

    while (inputLetra != 'S' && inputLetra != 'N') {
        menu.mensajeDeError("Opción invalida! Intentelo de nuevo.");
    Menu::setColor(7);
        cout << "Esta en vacaciones S/N? " << endl;
    Menu::setColor(0);
        cin >> inputLetra;
    }

    if (inputLetra == 'S') {
        vacacionesActivas = true;
    Menu::setColor(7);
    } else {
        vacacionesActivas = false;
    }

    while (inputSueldo < 1)
    {
        Menu::setColor(7);
        cout << "Ingrese su sueldo: "<< endl;
        cin>>inputSueldo;
        Menu::setColor(0);
        if (inputSueldo > 0)
        {
            sueldo = inputSueldo;
        }
        else
        {
            menu.mensajeDeError("Opcion Invalida!");
        }
    }



}
