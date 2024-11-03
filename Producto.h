#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
private:
    int productoID;
    int idLineaP;
    char nombreProducto[50];
    float precioUnitario;
    int stock;
    char categoriaProducto[50];

public:
    Producto();
    Producto(int productoID, int _idLineaP, const char* nombreProducto, float precioUnitario, int stock, const char* categoriaProducto);

    int getProductoID();
    int getIdLineaP();
    const char* getNombre();
    float getPrecioUnitario();
    const char* getCategoriaProducto();
    int getStock();

    void setProductoID(int _productoID);
    void setIdLineaP (int _idLineaP);
    void setNombre(const char* _nombre);
    void setPrecioUnitario(float _precioUnitario);
    void setCategoriaProducto(const char* _categoriaProducto);
    void setStock(int _stock);

    void cargarProducto();
    void mostrarProducto();

};


#endif // PRODUCTO_H_INCLUDED
