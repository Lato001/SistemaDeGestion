#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "Persona.h"
#include "Fecha.h"

class Empleado : public Persona {
private:
    Fecha fechaDeIngreso;
    int empleadoID;
    int asistencias;
    bool vacacionesActivas;
    float sueldo;

public:
    Empleado();
    Empleado(int, const char *, const char*, const char*, int, const char*,Fecha _fechaDeIngreso, int _empleadoID, int _asistencias, bool _vacacionesActivas); //Constructor de la clase Empleado

    int getID();
    Fecha getFechaIngreso();
    int getAsistencias();
    bool getIsVacaciones();
    float getSueldo();

    void setfechadeingreso(Fecha _fechaDeIngreso);
    void setempleadoID(int _empleadoID);
    void setAsistencias(int _asistencias);
    void setvacacionesActivas(bool _vacacionesActivas);
    void setSueldo(float _sueldo);

    void cargarEmpleado();
    void mostrarEmpleado();

};

#endif // EMPLEADO_H_INCLUDED
