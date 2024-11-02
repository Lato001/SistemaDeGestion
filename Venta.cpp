#include <iostream>
#include "rlutil.h"
#include "Fecha.h"
#include "Empleado.h"
#include "Cliente.h"
#include "ArchivoEmpleados.h"
#include "ArchivoClientes.h"
#include "Venta.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "Producto.h"

using namespace std;

Venta::Venta() {
    idVenta = 0;
    idEmpleado = 0;
    idCliente = 0;
    fecha;
    formaDePago = 0;
    importeTotal = 0;
    estado = false;
}

Venta::Venta(int _idVenta, int _idEmpleado, int _idCliente, Fecha _fecha, int _formaDePago, float _importeTotal, bool _estado) {
    idVenta = _idVenta;
    idEmpleado = _idEmpleado;
    idCliente = _idCliente;
    fecha = _fecha;
    formaDePago = _formaDePago;
    importeTotal = _importeTotal;
    estado = _estado;
}

int Venta::getIdVenta() { return idVenta; }
int Venta::getIdEmpleado() { return idEmpleado; }
int Venta::getIdCliente() { return idCliente; }
Fecha Venta::getFecha() { return fecha; }
int Venta::getFormaDePago() { return formaDePago; }
float Venta::getImporteTotal() { return importeTotal; }
bool Venta::getEstado() { return estado; }

void Venta::setidVenta(int _idVenta) { idVenta = _idVenta; }
void Venta::setFecha(Fecha _fecha) { fecha = _fecha; }
void Venta::setFormaDePago(int _formaDePago) { formaDePago = _formaDePago; }
void Venta::setidEmpleado(int _idEmpleado) { idEmpleado = _idEmpleado; }
void Venta::setidCliente(int _idCliente) { idCliente = _idCliente; }
void Venta::setImporteTotal(float _importeTotal) { importeTotal = _importeTotal; }
void Venta::setEstado(bool _estado) { estado = _estado; }

void Venta::cargarVenta() {
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoProductos DetalleVentas("ArchivoDetalleVentas.dat");
    Empleado registroEmpleado;
    Cliente registroCliente;
    Producto registroDetalle;
    float montoTotalVenta;
    idVenta = Ventas.CantidadRegistros() + 1;
    int input = 0;
    char inputChar = 'n';
    bool vendedorValido = false, clienteValido = false, formaDePagoValida = false;

    rlutil::cls();
    rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese la fecha de la venta:" << endl;
    rlutil::setColor(rlutil::WHITE);
    fecha.cargarFecha();
    rlutil::anykey();
    rlutil::cls();

    while (!vendedorValido) {
        rlutil::setColor(rlutil::BLACK);
        cout << "Seleccione el Empleado (ID - Nombre):" << endl;

        for (int i = 0; i < Empleados.CantidadRegistros(); i++) {
            registroEmpleado = Empleados.Leer(i);
            cout << "ID: " << registroEmpleado.getID() << " - Nombre: " << registroEmpleado.getNombre() << endl;
        }
        cout << "Ingrese el ID del cliente: ";
           rlutil::setColor(rlutil::WHITE);
        cin >> input;

        if (input > 0 && input <= Empleados.CantidadRegistros()) {
            idEmpleado = input;
            vendedorValido = true;
        } else {
            rlutil::setColor(rlutil::RED);
            cout << "ID invalido. Intente nuevamente." << endl;
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
        }
    }
    rlutil::anykey();
    rlutil::cls();

    while (!clienteValido) {
        rlutil::setColor(rlutil::BLACK);
        cout << "Seleccione el cliente (ID - Nombre):" << endl;

        for (int i = 0; i < Clientes.CantidadRegistros(); i++) {
            registroCliente = Clientes.Leer(i);
            cout << "ID: " << registroCliente.getID() << " - Nombre: " << registroCliente.getNombre() << endl;
        }
        cout << "Ingrese el ID del cliente: ";
         rlutil::setColor(rlutil::WHITE);
        cin >> input;

        if (input > 0 && input <= Clientes.CantidadRegistros()) {
            idCliente = input;
            clienteValido = true;
        } else {
            rlutil::setColor(rlutil::RED);
            cout << "ID invalido. Intente nuevamente." << endl;
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
        }
    }
    rlutil::anykey();
    rlutil::cls();

    while (!formaDePagoValida) {
        rlutil::setColor(rlutil::BLACK);
        cout << "Seleccione forma de pago:" << endl;
        cout << "1. Efectivo\n2. Debito\n3. Credito" << endl << "Opcion: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> input;
        formaDePago = input;

        if (formaDePago > 0 && formaDePago < 4) {
            formaDePagoValida = true;
            rlutil::setColor(rlutil::GREEN);
            switch (formaDePago) {
                case 1: cout << "Metodo de pago seleccionado: Efectivo" << endl; break;
                case 2: cout << "Metodo de pago seleccionado: Debito" << endl; break;
                case 3: cout << "Metodo de pago seleccionado: Credito" << endl; break;
            }
            rlutil::setColor(rlutil::WHITE);
        } else {
            rlutil::setColor(rlutil::RED);
            cout << "Metodo de pago no valido." << endl;
            rlutil::setColor(rlutil::WHITE);
        }
    }
    rlutil::anykey();
    rlutil::cls();

    bool validacionDetalles = false;
    while (!validacionDetalles) {
        rlutil::setColor(rlutil::BLACK);
        cout << "--------------- DETALLE DE VENTA --------------------" << endl;
        rlutil::setColor(rlutil::WHITE);
        registroDetalle.cargarDetalleDeVenta(getIdVenta());
        registroDetalle.mostrarDetalleDeVenta();
        rlutil::anykey();
        if (DetalleVentas.Guardar(registroDetalle)) {
            rlutil::setColor(rlutil::GREEN);
            cout << "El detalle de venta se ha registrado correctamente" << endl;
            rlutil::setColor(rlutil::WHITE);
        }

        cout << "-----------------------------------------------------" << endl;

        while (inputChar != 'S' && inputChar != 'N') {
 rlutil::setColor(rlutil::BLACK);
            cout << "Desea registrar otro producto para esta venta? S/N: ";
             rlutil::setColor(rlutil::WHITE);
            cin >> inputChar;
            if (inputChar != 'S' && inputChar != 'N') {
                rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida! Vuelva a intentarlo" << endl;
                rlutil::setColor(rlutil::WHITE);
            }
        }
        if (inputChar == 'N') {
            validacionDetalles = true;
        }else{
            inputChar = 'n';
            cout<< "Siguiente detalle!"<<endl;
        }
        rlutil::anykey();
        rlutil::cls();
    }
}



void Venta::mostrarVenta() {
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoProductos DetallesVentas("ArchivoDetalleVentas.dat");
    Venta saldo;
    cout << "------------ Nro DE VENTA: " << getIdVenta() << " ------------------------" << endl;
    cout << "FECHA: ";
    getFecha().mostrarFecha();
    cout << "VENDEDOR: " << endl;

    Empleados.Buscar(getIdEmpleado()).mostrarEmpleado();
    cout << endl;
    cout << "COMPRADOR: " << endl;
    Clientes.Buscar(getIdCliente()).mostrarCliente();
    cout << endl;
    cout << "FORMA DE PAGO: ";
    switch (getFormaDePago()) {
        case 1: cout << "Efectivo" << endl; break;
        case 2: cout << "Debito" << endl; break;
        case 3: cout << "Credito" << endl; break;
    }
    cout << endl;

    cout << "--------------- DETALLE DE VENTA --------------------" << endl;
    cout<< "ARTICULOS COMPRADOS: " << DetallesVentas.ContLineas(getIdVenta())<<endl<<endl;
            for(int i = 0 ; i <DetallesVentas.ContLineas(idVenta) ; i++ )
    {
        saldo.importeTotal += DetallesVentas.BuscarPorLinea(idVenta,i).getImporte();
    }
    DetallesVentas.Buscar(getIdVenta()).mostrarDetalleDeVenta();
    cout<<"Importe TOTAL de la Venta: "<< saldo.getImporteTotal();
    cout << "---------------------------------------------------" << endl;
}
