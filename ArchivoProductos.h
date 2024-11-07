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
        void FiltrarPorNombre(string _nombre);
        void FiltrarPorID(int productoID);
        void FiltrarPorCategoria (string _categoria);
        void ModificarProducto(int productoID);

        int BuscarPos(int productoID);
        int ContLineas(int ID);

        void eliminarArchivoProductos();
        void eliminarRegistroProducto(int productoID);
        void exportarProductosACSV(string nombreArchivoCSV);

        Producto Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Producto *vector);
};


#endif // ARCHIVOPRODUCTOS_H_INCLUDED
