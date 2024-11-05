#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED

#include "Persona.h"
#include "Empleado.h"

using namespace std;

class ArchivoEmpleados {
private:
        string _nombreArchivo;

    public:
        ArchivoEmpleados(string nombreArchivo);
        bool Guardar(Empleado empleado);
        bool Guardar(Empleado empleado, int posicion);

        Empleado Buscar(int empleadoID);

        void FiltrarEmpleados();
        void FiltrarPorNombre(string _nombre);
        void FiltrarPorOrdenAlfabetico();
        void FiltrarPorID(int _ID);
        void FiltrarPorFecha();
        void FiltrarPorAsistencias();
        void FiltrarPorVacacionesActivas(bool _vacaciones);

        void eliminarRegistroEmpleado();
        Empleado Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, Empleado *vector);
};

#endif // ARCHIVOEMPLEADOS_H_INCLUDED
