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
DetalleVenta::DetalleVenta(int _ventaID, int _prodcutoID, int _cantidadProducto, float _precio)
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
