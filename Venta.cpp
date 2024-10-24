#include <iostream>
#include "Venta.h"
#include "Fecha.h"
#include "Persona.h"
#include "Empleado.h"

using namespace std;

Venta::Venta(){
    nDeVenta;
    fecha;
    vendedor;
    formaDePago;
    TotalDeVenta;
 }
 Venta::Venta(int _nDeVenta, Fecha _fecha, Persona _vendedor, int _formaDePago, float _TotalDeVenta)
 {
    nDeVenta = _nDeVenta;
    fecha = _fecha;
    vendedor = _vendedor;
    formaDePago = _formaDePago;
    TotalDeVenta = _TotalDeVenta;

 }

 int Venta::getNDeVenta(){return nDeVenta;}
 Fecha Venta::getFecha(){return fecha;}
 Persona Venta::getVendedor(){return vendedor;}
 int Venta::getFormaDePago(){return formaDePago;}
 float Venta::getTotalDeVenta(){return TotalDeVenta;}

 void Venta::setNDeVenta(int _nDeVenta){nDeVenta = _nDeVenta;}
 void Venta::setFecha(Fecha _fecha){fecha = _fecha;}
 void Venta::setFormaDePago(int _formaDePago){formaDePago = _formaDePago;}
 void Venta::setVendedor(Persona _vendedor){vendedor = _vendedor;}
 void Venta::setTotalDeVenta(float _TotalDeVenta){TotalDeVenta = _TotalDeVenta;}

 void Venta::mostrarVenta(){
     Persona venta;
     cout<<"-----------------------------------"<<endl;
    cout << "N de Venta: " << nDeVenta << endl;
    cout << "Fecha: " << fecha.toString() << endl;
    cout << "Vendedor: ";
    venta.mostrarPersona();
    cout<<endl;
    cout << "Forma de Pago: " << formaDePago << endl;
    cout << "Total a pagar: " << TotalDeVenta << endl;
    cout<<"-----------------------------------"<<endl;
 }
