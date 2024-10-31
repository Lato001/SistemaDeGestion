#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED


class DetalleVenta{
private:
    int idVenta;
    int idLinea;
    int idProducto;
    int cantidadProducto;
    float importe;
    bool estado;
public:
    DetalleVenta();
    DetalleVenta(int _idVenta, int _idLinea, int _idProducto, int _cantidadProducto, float _importe, bool _estado);


    int getIdVenta();
    int getIdLinea();
    int getIdProducto();
    int getCantidadProducto();
    float getImporte();
    bool getEstado();

    void setIdVenta(int _idVenta);
    void setIdLinea(int _idLinea);
    void setIdProducto(int _idProducto);
    void setCantidadProducto( int _cantidadProducto);
    void setImporte(float _importe);
    void setEstado(bool _estado);

    void cargarDetalleDeVenta();
    void mostrarDetalleDeVenta();

};

#endif // DETALLEVENTA_H_INCLUDED
