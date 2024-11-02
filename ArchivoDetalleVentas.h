#ifndef ARCHIVODETALLEVENTAS_H_INCLUDED
#define ARCHIVODETALLEVENTAS_H_INCLUDED

#include "DetalleVenta.h"

using namespace std;

class ArchivoDetalleVentas {
private:
        string _nombreArchivo;

    public:
        ArchivoDetalleVentas(string nombreArchivo);
        bool Guardar(DetalleVenta detalleVenta);
        bool Guardar(DetalleVenta detalleVenta, int posicion);
        DetalleVenta Buscar(int idVenta);
        DetalleVenta Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, DetalleVenta *vector);
};
#endif // ARCHIVODETALLEVENTAS_H_INCLUDED
