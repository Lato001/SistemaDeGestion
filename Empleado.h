#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "Persona.h"
#include "Fecha.h"

class Empleado {
private:
    Persona empleado;
    Fecha fechaDeIngreso;
    int empleadoID;
    int diasTrabajados;
    int ausentes;
    bool vacacionesActivas;

public:
    Empleado();
    Empleado(int _fechaDeIngreso, int _empleadoID, int _diasTrabajados, int _ausentes, bool _vacacionesActivas);
    int getID();
    Fecha getFechaIngreso();
    int getDiasTrabajados();
    int getAusentes();
    bool getIsVacaciones();

    void setfechadeingreso(int _fechaDeIngreso);
    void setempleadoID(int _empleadoID);
    void setdiasTrabajados(int _diasTrabajados);
    void setausentes(int _ausentes);
    void setvacacionesActivas(bool _vacacionesActivas);

    void mostrarEmpleado();

};

#endif // EMPLEADO_H_INCLUDED
