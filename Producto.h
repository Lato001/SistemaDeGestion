#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
private:
    int productoID;
    char nombreProducto[50];
    float precioUnitario;
    int stock;
    //sumar factura total
    //sumar categoriaProducto
public:
    Producto();
    Producto(int productoID, const char* nombreProducto, float precioUnitario, int stock);

    int getProductoID();
    const char* getNombre();
    float getPrecioUnitario();

    void setProductoID(int _productoID);
    void setNombre(const char* _nombre);
    void setPrecioUnitario(float _precioUnitario);

    // sumar cargar Producto();
    void mostrarProducto();

};


#endif // PRODUCTO_H_INCLUDED
