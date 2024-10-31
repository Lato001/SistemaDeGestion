#include <iostream>
using namespace std;
#include "DetalleVenta.h"
DetalleVenta::DetalleVenta()
{
    productoID = 0;
    cantidadProducto = 0;
}
DetalleVenta::DetalleVenta(int _productoID, int _cantidadProducto)
{
    productoID = _productoID;
    cantidadProducto = _cantidadProducto;
}

    int DetalleVenta :: getProductoID(){return productoID;}
    int DetalleVenta :: getCantidadProducto(){return cantidadProducto;}

    void DetalleVenta :: setProductoID(int _productoID){productoID = _productoID;}
    void DetalleVenta :: setCantidadProducto(int _cantidadProducto){cantidadProducto = _cantidadProducto;}

    void DetalleVenta :: cargarDetalleDeVenta(){
        int input;
        cout<< "Ingrese el ID del producto: " << endl;
        cin>> input;
        productoID = input;
        cout<< "Ingrese la cantidad comprada del producto: " << endl;
        cin>> input;
        cantidadProducto = input;

    }
    void DetalleVenta :: mostrarDetalleDeVenta(){
    cout<<"-----------------------------------"<<endl;
    cout<< "ID DEL PRODUCTO: " << getProductoID()<<endl;
    cout<< "CANTIDAD DEL PRODUCTO: " << getCantidadProducto()<<endl;
    cout<<"-----------------------------------"<<endl;
    }
