#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include "Persona.h"
#include "Cliente.h"

class Venta{
private:
    int nDeVenta;
    Fecha fecha;
    Persona vendedor;
    Empleado vendedorID;
    int formaDePago;
    float importeDeVenta;
public:

 Venta();
 Venta(int _nDeVenta, Fecha _fecha, Persona _vendedor, Empleado _vendedorID, int _formaDePago,float _importeDeVenta );
 int getNDeVenta();
 Fecha getFecha();
 Persona getVendedor();
 Empleado getVendedorID();
 int getFormaDePago();
 int getImporteDeVenta();

 void setNDeVenta(int _nDeVenta);
 void setFecha(Fecha _fecha);
 void setFormaDePago(int _formaDePago);
 void setVendedor(Persona _vendedor);
 void setVendedorID(Empleado _vendedorID);
 void setImporteDeVenta(float _importeDeVenta);

 void mostrarVenta();
};


#endif // VENTA_H_INCLUDED
