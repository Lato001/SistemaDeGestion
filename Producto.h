#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include "DetalleVenta.h"

class Producto : public DetalleVenta {
private:
    int productoID;
    char nombreProducto[50];
    float precioUnitario;
    int stock;
    char categoriaProducto[50];

public:
    Producto();
    Producto(int _productoID, const char* _nombreProducto, float _precioUnitario, int _stock, const char* _categoriaProducto); //Constructor de la clase Producto

    int getID();
    const char* getNombre();
    float getPrecioUnitario();
    const char* getCategoriaProducto();
    int getStock();

    void setProductoID(int _productoID);
    void setNombre(const char* _nombre);
    void setPrecioUnitario(float _precioUnitario);
    void setCategoriaProducto(const char* _categoriaProducto);
    void setStock(int _stock);

    void setID(int _ID);


    void cargarProducto();
    void mostrarProducto();

};


#endif // PRODUCTO_H_INCLUDED
