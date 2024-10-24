#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED


class DetalleVenta{
private:
    int ventaID;
    int  productoID;
    int cantidadProducto;
    float precio;
public:
    DetalleVenta();
    DetalleVenta(int ventaID, int productoID, int cantidadProducto, float precio);


    int getVentaID();
    int getProductoID();
    int getCantidadProducto();
    float getPrecio();
    void setVenta(int _ventaID);
    void setProductoID(int _productoID);
    void setCantidadProducto(int _cantidadProducto);
    void setPrecio(int _precio);

};

#endif // DETALLEVENTA_H_INCLUDED
