#include <iostream>
using namespace std;
#include "DetalleVenta.h"
DetalleVenta::DetalleVenta()
{
    ventaID = 0;
    productoID = 0;
    cantidadProducto = 0;
    precio = 0;
}
DetalleVenta::DetalleVenta(int _ventaID, int _prodcutoID, int _cantidadProducto, float _precio, const char* categoriaProducto)
{
    ventaID = _ventaID;
    productoID = _prodcutoID;
    cantidadProducto = _cantidadProducto;
    precio = _precio;
}

    int DetalleVenta :: getVentaID(){return ventaID;}
    int DetalleVenta :: getProductoID(){return productoID;}
    int DetalleVenta :: getCantidadProducto(){return cantidadProducto;}
    float DetalleVenta :: getPrecio(){return precio;}

    void DetalleVenta :: setVenta(int _ventaID){ventaID = _ventaID;}
    void DetalleVenta :: setProductoID(int _productoID){productoID = _productoID;}
    void DetalleVenta :: setCantidadProducto(int _cantidadProducto){cantidadProducto = _cantidadProducto;}
    void DetalleVenta :: setPrecio(int _precio){precio = _precio;}

    void DetalleVenta :: cargarDetalleDeVenta(){
        int input;
        float decimalInput;
        cout<< "ingrese el id de su venta: "<<endl;
        cin>> input;
        ventaID = input;
        cout<< "Ingrese el ID del producto: " << endl;
        cin>> input;
        productoID = input;
        cout<< "Ingrese el precio del producto: " << endl;
        cin>> input;
        precio = decimalInput;

    }
    void DetalleVenta :: mostrarDetalleDeVenta(){
    cout<<"-----------------------------------"<<endl;
    cout<< "ID DE VENTA: " << getVentaID()<<endl;
    cout<< "ID DEL PRODUCTO: " << getProductoID()<<endl;
    cout<< "CANTIDAD DEL PRODUCTO: " << getCantidadProducto()<<endl;
    cout<< "CATEGORIA DEL PRODUCTO: " << getCantidadProducto()<<endl;
    cout<< "PRECIO: " << getPrecio() << endl;
    cout<<"-----------------------------------"<<endl;
    }
