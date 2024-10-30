#include <iostream>
#include "Venta.h"
#include "Fecha.h"
#include "Persona.h"
#include "Empleado.h"
#include "ArchivoEmpleados.h"
#include "ArchivoClientes.h"
#include "ArchivoVentas.h"

using namespace std;

Venta::Venta(){
    nDeVenta = 0;
    fecha;
    vendedor;
    comprador;
    formaDePago = 0;
    detalleDeVenta;
    TotalDeVenta = 0;
}
Venta::Venta(int _nDeVenta, Fecha _fecha, Empleado _vendedor, Cliente _comprador, int _formaDePago, DetalleVenta detalleDeVenta, float _TotalDeVenta)
{
    nDeVenta = _nDeVenta;
    fecha = _fecha;
    vendedor = _vendedor;
    comprador = _comprador;
    formaDePago = _formaDePago;
    TotalDeVenta = _TotalDeVenta;
}

int Venta::getNDeVenta(){return nDeVenta;}
Fecha Venta::getFecha(){return fecha;}
Empleado Venta::getVendedor(){return vendedor;}
int Venta::getFormaDePago(){return formaDePago;}
float Venta::getTotalDeVenta(){return TotalDeVenta;}
DetalleVenta Venta::getDetalleDeVenta(){return detalleDeVenta;}

void Venta::setNDeVenta(int _nDeVenta){nDeVenta = _nDeVenta;}
void Venta::setFecha(Fecha _fecha){fecha = _fecha;}
void Venta::setFormaDePago(int _formaDePago){formaDePago = _formaDePago;}
void Venta::setVendedor(Empleado _vendedor){vendedor = _vendedor;}
void Venta::setTotalDeVenta(float _TotalDeVenta){TotalDeVenta = _TotalDeVenta;}

void Venta::mostrarVenta(){
    cout << "-----------------------------------" << endl;
    cout << "Nro DE VENTA: " << getNDeVenta() << endl;
    cout << "FECHA: ";
    getFecha().mostrarFecha();
    cout << "VENDEDOR: ";
    getVendedor().mostrarPersona();
    cout << "FORMA DE PAGO: " << getFormaDePago() << endl;
    cout << "---------------DETALLE DE VENTA--------------------" << endl;
    detalleDeVenta.mostrarDetalleDeVenta();
    cout << "---------------................--------------------" << endl;
    cout << "TOTAL DE VENTA: " << getTotalDeVenta();
    cout << "-----------------------------------" << endl;
}

void Venta::cargarVenta() {
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Empleado registroEmpleado;
    Cliente registroCliente;
    int inputNumeros;
    float montoTotalVenta;

    cout << "Ingrese el numero de venta: ";
    cin >> inputNumeros;
    nDeVenta = inputNumeros;

    cout << "FECHA: ";
    fecha.cargarFecha();


    int idVendedor = 0;
    bool vendedorValido = false;
    while (!vendedorValido) {
        cout << "Seleccione el vendedor (ID - Nombre):" << endl;
        for (int i = 0; i < Empleados.CantidadRegistros(); i++) {
            registroEmpleado = Empleados.Leer(i);
            cout << "ID: " << registroEmpleado.getID() << " - Nombre: " << registroEmpleado.getNombre() << endl;
        }
        cout << "Ingrese el ID del vendedor: ";
        cin >> idVendedor;

        if (idVendedor > 0 && idVendedor <= Empleados.CantidadRegistros()) {
            vendedor = Empleados.Leer(idVendedor -1);
            vendedorValido = true;
        } else {
            cout << "ID invalido. Intente nuevamente." << endl;
            system("pause");
            system("cls");
        }
    }


    int idCliente = 0;
    bool clienteValido = false;
    while (!clienteValido) {
        cout << "Seleccione el cliente (ID - Nombre):" << endl;
        for (int i = 0; i < Clientes.CantidadRegistros(); i++) {
            registroCliente = Clientes.Leer(i);
            cout << "ID: " << registroCliente.getID() << " - Nombre: " << registroCliente.getNombre() << endl;
        }
        cout << "Ingrese el ID del cliente: ";
        cin >> idCliente;

        if (idCliente > 0 && idCliente <= Clientes.CantidadRegistros()) {

            clienteValido = true;
            comprador = Clientes.Leer(idCliente -1);
        } else {
            cout << "ID invalido. Intente nuevamente." << endl;
            system("pause");
            system("cls");
        }
    }

    cout << "Seleccione forma de pago:" << endl;
    cout << "1. Efectivo\n2. Debito\n3. Credito" << endl;
    cin >> inputNumeros;
    formaDePago = inputNumeros;

    cout << "--------------- DETALLE DE VENTA --------------------" << endl;
    detalleDeVenta.cargarDetalleDeVenta();
    cout << "-----------------------------------------------------" << endl;

    cout << "Ingrese el monto total de la venta realizada: ";
    cin >> montoTotalVenta;
    TotalDeVenta = montoTotalVenta;

    cout << "-----------------------------------" << endl;
}

void listarClientes() {
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente registroCliente;

    cout << "Lista de Clientes (ID - Nombre):" << endl;
    for (int i = 0; i < Clientes.CantidadRegistros(); i++) {
        registroCliente = Clientes.Leer(i);
        cout << "ID: " << registroCliente.getID() << " - Nombre: " << registroCliente.getNombre() << endl;
    }
}
