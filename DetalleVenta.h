#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED


class DetalleVenta{
private:
    int ventaID;
    int  productoID;
    int cantidadProducto;
    float precio;
    char categoriaProducto;
public:
    DetalleVenta();
    DetalleVenta(int ventaID, int productoID, int cantidadProducto, float precio, const char* categoriaProducto);


    int getVentaID();
    int getProductoID();
    int getCantidadProducto();
    float getPrecio();
    const char* getCategoriaProducto();

    void setVenta(int _ventaID);
    void setProductoID(int _productoID);
    void setCantidadProducto(int _cantidadProducto);
    void setPrecio(int _precio);
    void setCategoriaProducto(const char* _categoriaProducto);

    void mostrarDetalleDeVenta();
    void cargarDetalleDeVenta();

};

#endif // DETALLEVENTA_H_INCLUDED
