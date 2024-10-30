#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED


#include "Venta.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Venta.h"
#include "DetalleVenta.h"

using namespace std;

class ArchivoVentas {
private:
        string _nombreArchivo;

    public:
        ArchivoVentas(string nombreArchivo);
        bool Guardar(Venta venta);
        bool Guardar(Venta venta, int posicion);
        int Buscar(int nDeVenta);
        Venta Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, Venta *vector);
};

#endif // ARCHIVOVENTAS_H_INCLUDED
