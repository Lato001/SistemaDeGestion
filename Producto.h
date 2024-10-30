#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
private:
    int productoID;
    char nombreProducto[50];
    float precioUnitario;
    int stock;
    char categoriaProducto;
public:
    Producto();
    Producto(int productoID, const char* nombreProducto, float precioUnitario, int stock, const char* categoriaProducto);

    int getProductoID();
    const char* getNombre();
    float getPrecioUnitario();
    const char* getCategoriaProducto();

    void setProductoID(int _productoID);
    void setNombre(const char* _nombre);
    void setPrecioUnitario(float _precioUnitario);
    void setCategoriaProducto(const char* _categoriaProducto);

    void mostrarProducto();
    void cargarProducto();

};


#endif // PRODUCTO_H_INCLUDED
