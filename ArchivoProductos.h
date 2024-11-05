#ifndef ARCHIVOPRODUCTOS_H_INCLUDED
#define ARCHIVOPRODUCTOS_H_INCLUDED

#include "Producto.h"
using namespace std;

class ArchivoProductos {
private:
        string _nombreArchivo;

    public:
        ArchivoProductos(string nombreArchivo);
        bool Guardar(Producto producto);
        bool Guardar(Producto prodcuto, int posicion);
        Producto Buscar(int ID);
        void FiltrarProductos();
        int BuscarPos(int productoID);
        int ContLineas(int ID);
        Producto Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Producto *vector);
};


#endif // ARCHIVOPRODUCTOS_H_INCLUDED
