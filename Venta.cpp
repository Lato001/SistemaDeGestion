#include <iostream>
#include "rlutil.h"
#include "Fecha.h"
#include "Empleado.h"
#include "Cliente.h"
#include "ArchivoEmpleados.h"
#include "ArchivoClientes.h"
#include "Venta.h"
#include "ArchivoVentas.h"
#include "ArchivoDetalleVentas.h"
#include "DetalleVenta.h"
#include "ArchivoProductos.h"
#include "Producto.h"
#include "Menu.h"

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
    Menu menu;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");
    Empleado registroEmpleado;
    Cliente registroCliente;
    DetalleVenta registroDetalle;
    float montoTotalVenta;

    if(Ventas.CantidadRegistros() == 0){
        idVenta = 1;
    }else{
        idVenta = Ventas.Leer((Ventas.CantidadRegistros()-1)).getIdVenta() + 1;
    }

    idVenta = Ventas.CantidadRegistros() + 1;
    int input = 0;
    char inputChar = 'n';
    bool vendedorValido = false, clienteValido = false, formaDePagoValida = false;

    rlutil::cls();
    Menu::setColor(7);
    cout << "Ingrese la fecha de la venta:" << endl;
    Menu::setColor(0);
    fecha.cargarFecha();
    rlutil::anykey();
    rlutil::cls();

    while (!vendedorValido) {
        Menu::setColor(7);
        cout << "Seleccione el Empleado (ID - Nombre):" << endl;
        Menu::setColor(7);

        for (int i = 0; i < Empleados.CantidadRegistros(); i++) {
            registroEmpleado = Empleados.Leer(i);
            cout << "ID: " << registroEmpleado.getID() << " - Nombre: " << registroEmpleado.getNombre() << endl;
        }
           Menu::setColor(7);
        cout << "Ingrese el ID del Empleado: ";
           Menu::setColor(0);        cin >> input;

        if (Empleados.Buscar(input).getID() != -1) {
            idEmpleado = input;
            vendedorValido = true;
        } else {

           menu.mensajeDeError("ID invalido. Intente nuevamente." );
            Menu::setColor(7);
            system("pause");
            system("cls");

        }
    }
    menu.setColor(7);
    cout<<"EMPLEADO ELEGIDO: "<<endl;
    Empleados.Buscar(idEmpleado).mostrarEmpleado();
    cout<<endl;

    system("pause");
    system("cls");

    while (!clienteValido) {
        Menu::setColor(7);
        cout << "Seleccione el cliente (ID - Nombre):" << endl;
        Menu::setColor(7);

        for (int i = 0; i < Clientes.CantidadRegistros(); i++) {
            registroCliente = Clientes.Leer(i);
            cout << "ID: " << registroCliente.getID() << " - Nombre: " << registroCliente.getNombre() << endl;
        }
         Menu::setColor(7);
        cout << "Ingrese el ID del cliente: ";
         Menu::setColor(0);        cin >> input;

        if (Clientes.Buscar(input).getID() != -1) {
            idCliente = input;
            clienteValido = true;
        } else {

            menu.mensajeDeError("ID invalido. Intente nuevamente.");
            Menu::setColor(7);
            system("pause");
            system("cls");
        }
    }
    rlutil::anykey();
    rlutil::cls();

    while (!formaDePagoValida) {
        Menu::setColor(7);
        cout << "Seleccione forma de pago:" << endl;
        cout << "1. Efectivo\n2. Debito\n3. Credito" << endl << "Opcion: ";
        Menu::setColor(0);
        cin >> input;
        formaDePago = input;

        if (formaDePago > 0 && formaDePago < 4) {
            formaDePagoValida = true;
            Menu::setColor(2);
            switch (formaDePago) {
                case 1: cout << "Metodo de pago seleccionado: Efectivo" << endl; break;
                case 2: cout << "Metodo de pago seleccionado: Debito" << endl; break;
                case 3: cout << "Metodo de pago seleccionado: Credito" << endl; break;
            }
            Menu::setColor(7);
        } else {

            menu.mensajeDeError("Metodo de pago no valido.");

        }
    }
    rlutil::anykey();
    rlutil::cls();

    bool validacionDetalles = false;
    while (!validacionDetalles) {
        Menu::setColor(7);
        cout << "--------------- DETALLE DE VENTA --------------------" << endl;
        Menu::setColor(0);
        registroDetalle.cargarDetalleDeVenta(getIdVenta());
        if (DetalleVentas.Guardar(registroDetalle)) {
            Menu::setColor(2);
            cout << "El detalle de venta se ha registrado correctamente" << endl;
            Menu::setColor(7);
        }

        cout << "-----------------------------------------------------" << endl;

        while (inputChar != 'S' && inputChar != 'N') {
            Menu::setColor(7);
            cout << "Desea registrar otro producto para esta venta? S/N: ";
            Menu::setColor(0);
            cin >> inputChar;
            if (inputChar != 'S' && inputChar != 'N') {

                menu.mensajeDeError("Opcion invalida! Vuelva a intentarlo" );

            }
        }

            Menu::setColor(0);
        if (inputChar == 'N') {
            validacionDetalles = true;
        }else{
            inputChar = 'n';
            Menu::setColor(7);            cout<< "Siguiente detalle!"<<endl;
        }
        rlutil::anykey();
        rlutil::cls();
    }
    for (int i = 1; i< DetalleVentas.ContLineas(idVenta) ;i++ ){
        montoTotalVenta += DetalleVentas.BuscarPorLinea(idVenta,i).getImporte();
    }
    importeTotal = montoTotalVenta;
}



void Venta::mostrarVenta() {
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoDetalleVentas DetallesVentas("ArchivoDetalleVentas.dat");
    Menu menu;
    Venta saldo;
    menu.setColor(7);
    cout << "------------ ID DE VENTA: " << getIdVenta() << " ------------------------" << endl;
    cout << "FECHA: ";
    getFecha().mostrarFecha();
    cout << "VENDEDOR: " << endl;

    Empleados.Buscar(getIdEmpleado()).mostrarEmpleado();
    cout << endl;
    cout << "COMPRADOR: " << endl;
    Clientes.Buscar(getIdCliente()).mostrarCliente();
    cout << endl;
    cout << "FORMA DE PAGO: ";
    menu.setColor(0);
    switch (getFormaDePago()) {
        case 1: cout << "Efectivo" << endl; break;
        case 2: cout << "Debito" << endl; break;
        case 3: cout << "Credito" << endl; break;
        menu.setColor(7);
    }
    cout << endl;
    menu.setColor(7);
    cout << "--------------- DETALLE DE VENTA --------------------" << endl;
    cout<< "ARTICULOS COMPRADOS: ";
    menu.setColor(0);
    cout << DetallesVentas.ContLineas(getIdVenta())<<endl<<endl;
    menu.setColor(7);
    for(int i = 0 ; i <= DetallesVentas.ContLineas(idVenta) ; i++ )
    {
        saldo.importeTotal += DetallesVentas.BuscarPorLinea(idVenta,i).getImporte();
    }
    DetallesVentas.Buscar(getIdVenta()).mostrarDetalleDeVenta();
    cout<<"Importe TOTAL de la Venta: ";
    menu.setColor(0);
    cout <<"$";
    cout<< saldo.getImporteTotal();
    menu.setColor(7);
    cout << endl;
    cout << "---------------------------------------------------" << endl;
}






