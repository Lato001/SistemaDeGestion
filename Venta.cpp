#include <iostream>
#include "Venta.h"
#include "Fecha.h"
#include "Persona.h"
using namespace std;
Venta::Venta(){
    nDeVenta =0;
    fecha;
    vendedor;
    formaDePago = 0;
    importeDeVenta;
 }
 Venta::Venta(int _nDeVenta, Fecha _fecha, Persona _vendedor, int _formaDePago,int importeDeVenta ){

    nDeVenta = _nDeVenta;
    fecha = _fecha;
    vendedor = _vendedor;
    formaDePago= 0;
    importeDeVenta = importeDeVenta;

 }

 int Venta::getNDeVenta(){return nDeVenta;}
 Fecha Venta::getFecha(){return fecha;}
 Persona Venta::getVendedor(){return vendedor;}
 int Venta::getFormaDePago(){return formaDePago;}
 int Venta::getImporteDeVenta(){return importeDeVenta;}

 void Venta::setNDeVenta(int _nDeVenta){nDeVenta = _nDeVenta;}
 void Venta::setFecha(Fecha _fecha){fecha = _fecha;}
 void Venta::setFormaDePago(int _formaDePago){formaDePago = _formaDePago;}
 void Venta::setVendedor(Persona _vendedor){vendedor = _vendedor;}
 void Venta::setImporteDeVenta(float _importeDeVenta){importeDeVenta = _importeDeVenta;}

 void Venta::mostrarVenta(){
    cout<<"\n";
 }
