#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
private:
    static const char WORD = 50;
    int productoID;
    char nombreProducto[WORD];
    float precioUnitario;
    int stock;
    char categoriaProducto[WORD];

public:
    Producto();
    Producto(int productoID, const char* nombreProducto, float precioUnitario, int stock, const char* categoriaProducto);

    int getProductoID();
    const char* getNombre();
    float getPrecioUnitario();
    const char* getCategoriaProducto();
    int getStock();

    void setProductoID(int _productoID);
    void setNombre(const char* _nombre);
    void setPrecioUnitario(float _precioUnitario);
    void setCategoriaProducto(const char* _categoriaProducto);
    void setStock(int _stock);

    void cargarProducto();
    void mostrarProducto();

};


#endif // PRODUCTO_H_INCLUDED
