#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "Persona.h"
#include "Fecha.h"

class Empleado {
private:
    Persona empleado;
    Fecha fechaDeIngreso;
    int empleadoID;
    int asistencias;
    bool vacacionesActivas;

public:
    Empleado();
    Empleado(Fecha _fechaDeIngreso, int _empleadoID, int _asistencias, bool _vacacionesActivas);
    int getID();
    Fecha getFechaIngreso();
    int getAsistencias();
    bool getIsVacaciones();

    void setfechadeingreso(Fecha _fechaDeIngreso);
    void setempleadoID(int _empleadoID);
    void setAsistencias(int _asistencias);
    void setvacacionesActivas(bool _vacacionesActivas);

    void mostrarEmpleado();

};

#endif // EMPLEADO_H_INCLUDED
