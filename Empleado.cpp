#include <iostream>

using namespace std;

#include "Persona.h"
#include "Empleado.h"
#include "Fecha.h"

Empleado::Empleado()
{
    empleadoID = 0;
    diasTrabajados = 0;
    ausentes = 0;
    vacacionesActivas = false;
}
