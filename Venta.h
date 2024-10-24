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
    int formaDePago;
    float importeDeVenta = 0;
public:

 Venta();
 Venta(int _nDeVenta, Fecha _fecha, Persona _vendedor, int _formaDePago,float _importeDeVenta);
 int getNDeVenta();
 Fecha getFecha();
 Persona getVendedor();
 int getFormaDePago();
float getImporteDeVenta();

 void setNDeVenta(int _nDeVenta);
 void setFecha(Fecha _fecha);
 void setFormaDePago(int _formaDePago);
 void setVendedor(Persona _vendedor);
 void setImporteDeVenta(float _importeDeVenta);

 void mostrarVenta();
};


#endif // VENTA_H_INCLUDED
