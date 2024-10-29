using namespace std;
#include <iostream>
#include <cstring>
#include "Producto.h"

Producto::Producto()
{
    productoID = 0;
    nombreProducto[0] = '\0';
    precioUnitario = 0;
    stock = 0;
}
Producto::Producto(int _productoID, const char* _nombreProducto, float _precioUnitario, int _stock, const char* categoriaProducto)
{
    productoID = _productoID;

    strncpy(nombreProducto, _nombreProducto, sizeof(nombreProducto) - 1); // Copiar con seguridad
    nombreProducto[sizeof(nombreProducto) - 1] = '\0';

    precioUnitario = _precioUnitario;
    stock = _stock;

}

int Producto::getProductoID(){return productoID;}
const char* Producto::getNombre(){return nombreProducto;}
float Producto::getPrecioUnitario(){return precioUnitario;}


void Producto::setProductoID(int _productoID){productoID = _productoID;}

void Producto::setNombre(const char* _nombreProducto) {
    strncpy(nombreProducto, _nombreProducto, sizeof(nombreProducto) - 1); // Copiar con seguridad
    nombreProducto[sizeof(nombreProducto) - 1] = '\0';
}
void Producto::setPrecioUnitario(float _PrecioUnitario){precioUnitario = _PrecioUnitario;}

void Producto::mostrarProducto(){
    cout<< "ID PRODUCTO :" << getProductoID() << " Nombre producto: "<<getNombre() << " Percio unitario: "<< getPrecioUnitario() <<endl;
}


