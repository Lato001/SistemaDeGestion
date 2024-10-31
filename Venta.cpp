#include <iostream>
#include "Venta.h"
#include "Fecha.h"
#include "Empleado.h"
#include "ArchivoEmpleados.h"
#include "ArchivoClientes.h"
#include "ArchivoVentas.h"


using namespace std;

Venta::Venta(){
    idVenta = 0;
    idEmpleado;
    idCliente;
    fecha;
    formaDePago = 0;
    importeTotal = 0;
    estado = false;
}
Venta::Venta(int _idVenta, Fecha _fecha, int _idEmpleado, int _idCliente, int _formaDePago, float _importeTotal, bool _estado);
{
    idVenta = _idVenta;
    idEmpleado = _idEmpleado;
    idCliente = _idCliente;
    fecha = _fecha;
    formaDePago = _formaDePago;
    importeTotal = _importeTotal;
}

    int getIdVenta() {return idVenta;}
    int getIdEmpleado() {return idEmpleado;}
    int getIdCliente(){return idCliente;}
    Fecha getFecha(){return fecha;}
    int getFormaDePago(){return formaDePago;}
    float getImporteTotal(){return importeTotal;}
    bool getEstado(){return estado;}

    void Venta::setidVenta(int _idVenta){idVenta = _idVenta;} //Cambio
    void Venta::setFecha(int _fecha){fecha = _fecha;}
    void Venta::setFormaDePago(int _formaDePago) {formaDePago = _formaDePago;}
    void Venta::setidEmpleado(int _idEmpleado) {idEmpleado = _idEmpleado;} //Cambio
    void Venta::setidCliente(int _idCliente) {idCliente = _idCliente} //Cambio
    void Venta::setImporteTotal(float _ImporteTotal) {importeTotal = _importeTotal;} //CambioD
    void Venta::setEstado(bool _estado) {estado = _estado;}

void Venta::mostrarVenta(){
    cout <<"------------" << "Nro DE VENTA: " << getIdVenta() << "------------------------" << endl;
    cout << "FECHA: ";
    getFecha().mostrarFecha();
    cout << "VENDEDOR: "<<endl;
//    getVendedor().mostrarPersona();
    getIdEmpleado().//?
    cout<< endl;
    cout << "CCOMPRADOR: "<<endl;
//    getComprador().mostrarPersona();
    getIdCliente().//?
    cout<< endl;
    cout << "FORMA DE PAGO: " << getFormaDePago() << endl<<endl;
    cout << "---------------DETALLE DE VENTA--------------------" << endl;
    detalleDeVenta.mostrarDetalleDeVenta();
    cout << "---------------------------------------------------" << endl;
    cout << "TOTAL DE VENTA: " << getImporteTotal()<<endl;
    cout << "---------------------------------------------------" << endl;
}

void Venta::cargarVenta() {
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoVentas Ventas("ArchivoVentas.dat");
    Empleado registroEmpleado;
    Cliente registroCliente;
    int inputNumeros;
    float montoTotalVenta;
    idVenta = Ventas.CantidadRegistros()+1;


    cout << "Ingrese la fecha de la venta: " << endl;
    fecha.cargarFecha();
    system("pause");
    system("cls");

    int idEmpleado = 0;
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
            vendedor = Empleados.Leer(idVendedor - 1);
            vendedorValido = true;
        } else {
            cout << "ID invalido. Intente nuevamente." << endl;
            system("pause");
            system("cls");
        }
    }
     system("pause");
     system("cls");

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
            comprador = Clientes.Leer(idCliente - 1);
        } else {
            cout << "ID invalido. Intente nuevamente." << endl;
            system("pause");
            system("cls");
        }
    }
     system("pause");
     system("cls");


    cout << "Seleccione forma de pago:" << endl << "1. Efectivo\n2. Debito\n3. Credito" << endl << "Opcion: " ;
    cin >> inputNumeros;
    formaDePago = inputNumeros;


    switch (formaDePago) {
        case 1:
            cout << "Metodo de pago seleccionado: Efectivo" << endl;
            break;
        case 2:
            cout << "Metodo de pago seleccionado: Debito" << endl;
            break;
        case 3:
            cout << "Metodo de pago seleccionado: Credito" << endl;
            break;
        default:
            cout << "Metodo de pago no valido." << endl;
            break;
    }
     system("pause");
     system("cls");

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

