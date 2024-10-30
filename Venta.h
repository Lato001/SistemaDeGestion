#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include "Persona.h"
#include "Cliente.h"
#include "DetalleVenta.h"

class Venta
{
private:
    int nDeVenta;
    Fecha fecha;
    Persona vendedor;
    int formaDePago;
    DetalleVenta detalleDeVenta;
    float TotalDeVenta = 0;
public:

    Venta();
    Venta(int _nDeVenta, Fecha _fecha, Persona _vendedor, int _formaDePago, DetalleVenta detalleDeVenta,float _TotalDeVenta);
    int getNDeVenta();
    Fecha getFecha();
    Persona getVendedor();
    int getFormaDePago();
    float getTotalDeVenta();
    DetalleVenta getDetalleDeVenta();

    void setNDeVenta(int _nDeVenta);
    void setFecha(Fecha _fecha);
    void setFormaDePago(int _formaDePago);
    void setVendedor(Persona _vendedor);
    void setTotalDeVenta(float _TotalDeVenta);
    void mostrarVenta();
    void cargarVenta();
};


#endif // VENTA_H_INCLUDED
