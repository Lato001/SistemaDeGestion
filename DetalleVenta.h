#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED


class DetalleVenta{
private:
    int  productoID;
    int cantidadProducto;
public:
    DetalleVenta();
    DetalleVenta(int productoID, int cantidadProducto);


    int getProductoID();
    int getCantidadProducto();

    void setProductoID(int _productoID);
    void setCantidadProducto(int _cantidadProducto);

    void cargarDetalleDeVenta();
    void mostrarDetalleDeVenta();

};

#endif // DETALLEVENTA_H_INCLUDED
