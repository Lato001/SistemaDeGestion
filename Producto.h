#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include "DetalleVenta.h"

class Producto : public DetalleVenta {
private:
    int productoID;
    int idLineaP;
    char nombreProducto[50];
    float precioUnitario;
    int stock;
    char categoriaProducto[50];
    int ID;

public:
    Producto();
    Producto(int, int, int, int, float, bool, int _productoID, int _idLineaP, const char* _nombreProducto, float _precioUnitario, int _stock, const char* _categoriaProducto, int _ID); //Constructor de la clase Producto

    int getProductoID();
    int getIdLineaP();
    const char* getNombre();
    float getPrecioUnitario();
    const char* getCategoriaProducto();
    int getStock();
    int getID();

    void setProductoID(int _productoID);
    void setIdLineaP (int _idLineaP);
    void setNombre(const char* _nombre);
    void setPrecioUnitario(float _precioUnitario);
    void setCategoriaProducto(const char* _categoriaProducto);
    void setStock(int _stock);

    void setID(int _ID);

    DetalleVenta getDetalleVenta();

    void cargarProducto();
    void mostrarProducto();

};


#endif // PRODUCTO_H_INCLUDED
