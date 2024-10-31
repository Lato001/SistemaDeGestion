#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include "Empleado.h"
#include "Cliente.h"
#include "DetalleVenta.h"

class Venta
{
private:
    int nDeVenta;
    Fecha fecha;
    Empleado vendedor;
    Cliente comprador;
    int formaDePago;
    DetalleVenta detalleDeVenta;
    float TotalDeVenta = 0;
public:

    Venta();
    Venta(int _nDeVenta, Fecha _fecha, Empleado _vendedor, Cliente _comprador, int _formaDePago, DetalleVenta detalleDeVenta,float _TotalDeVenta);
    int getNDeVenta();
    Fecha getFecha();
    Empleado getVendedor();
    Cliente getComprador();
    int getFormaDePago();
    float getTotalDeVenta();
    DetalleVenta getDetalleDeVenta();

    void setNDeVenta(int _nDeVenta);
    void setFecha(Fecha _fecha);
    void setFormaDePago(int _formaDePago);
    void setVendedor(Empleado _vendedor);
    void setComprador(Cliente _comprador);
    void setTotalDeVenta(float _TotalDeVenta);

    void cargarVenta();
    void mostrarVenta();
};


#endif // VENTA_H_INCLUDED
