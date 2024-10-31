#include <iostream>

#include "Fecha.h"
///CLIENTES Y EMPLEADOS
#include "Empleado.h"
#include "Cliente.h"
#include "ArchivoEmpleados.h"
#include "ArchivoClientes.h"
///VENTA
#include "Venta.h"
#include "ArchivoVentas.h"
///DETALLES DE VENTA
#include "ArchivoDetalleVentas.h"
#include "DetalleVenta.h"


using namespace std;

Venta::Venta()
{
    idVenta = 0;
    idEmpleado = 0;
    idCliente = 0;
    fecha;
    formaDePago = 0;
    importeTotal = 0;
    estado = false;
}
Venta::Venta(int _idVenta,  int _idEmpleado, int _idCliente, Fecha _fecha, int _formaDePago, float _importeTotal, bool _estado)
{
    idVenta = _idVenta;
    idEmpleado = _idEmpleado;
    idCliente = _idCliente;
    fecha = _fecha;
    formaDePago = _formaDePago;
    importeTotal = _importeTotal;
}

int Venta::getIdVenta(){return idVenta;}
int  Venta::getIdEmpleado(){return idEmpleado;}
int  Venta::getIdCliente(){return idCliente;}
Fecha  Venta::getFecha(){return fecha;}
int  Venta::getFormaDePago(){return formaDePago;}
float  Venta::getImporteTotal(){return importeTotal;}
bool  Venta::getEstado(){return estado;}

void Venta::setidVenta(int _idVenta){idVenta = _idVenta;}
void Venta::setFecha(Fecha _fecha){fecha = _fecha;}
void Venta::setFormaDePago(int _formaDePago){formaDePago = _formaDePago;}
void Venta::setidEmpleado(int _idEmpleado){idEmpleado = _idEmpleado;}
void Venta::setidCliente(int _idCliente){idCliente = _idCliente;}
void Venta::setImporteTotal(float _importeTotal){importeTotal = _importeTotal;}
void Venta::setEstado(bool _estado){estado = _estado;}

void Venta::cargarVenta()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");
    Empleado registroEmpleado;
    Cliente registroCliente;
    DetalleVenta registroDetalle;
    float montoTotalVenta;
    idVenta = Ventas.CantidadRegistros()+1;
    int input = 0;
    char inputChar = 'n';
    bool vendedorValido= false, clienteValido = false, formaDePagoValida = false;

    cout << "Ingrese la fecha de la venta: " << endl;
    fecha.cargarFecha();
    system("pause");
    system("cls");

    while (!vendedorValido)
    {
        cout << "Seleccione el vendedor (ID - Nombre):" << endl;
        for (int i = 0; i < Empleados.CantidadRegistros(); i++)
        {
            registroEmpleado = Empleados.Leer(i);
            cout << "ID: " << registroEmpleado.getID() << " - Nombre: " << registroEmpleado.getNombre() << endl;
        }
        cout << "Ingrese el ID del vendedor: ";
        cin >> input;

        if (input > 0 && input <= Empleados.CantidadRegistros())
        {
            idEmpleado = input;
            vendedorValido = true;
        }
        else
        {
            cout << "ID invalido. Intente nuevamente." << endl;
            system("pause");
            system("cls");
        }
    }
    system("pause");
    system("cls");


    while (!clienteValido)
    {
        cout << "Seleccione el cliente (ID - Nombre):" << endl;
        for (int i = 0; i < Clientes.CantidadRegistros(); i++)
        {
            registroCliente = Clientes.Leer(i);
            cout << "ID: " << registroCliente.getID() << " - Nombre: " << registroCliente.getNombre() << endl;
        }
        cout << "Ingrese el ID del cliente: ";
        cin >> input;

        if (input > 0 && input <= Clientes.CantidadRegistros())
        {
            idCliente = input;
            clienteValido = true;
        }
        else
        {
            cout << "ID invalido. Intente nuevamente." << endl;
            system("pause");
            system("cls");
        }
    }
    system("pause");
    system("cls");


    while(!formaDePagoValida)
    {

        cout << "Seleccione forma de pago:" << endl << "1. Efectivo\n2. Debito\n3. Credito" << endl << "Opcion: " ;
        cin >> input;
        formaDePago = input;

        if(formaDePago > 0 && formaDePago < 4)
        {
            formaDePagoValida = true;
            switch (formaDePago)
            {
            case 1:
                cout << "Metodo de pago seleccionado: Efectivo" << endl;
                break;
            case 2:
                cout << "Metodo de pago seleccionado: Debito" << endl;
                break;
            case 3:
                cout << "Metodo de pago seleccionado: Credito" << endl;
                break;
            }
        }
        else
        {
            cout << "Metodo de pago no valido." << endl;
        }
    }
    system("pause");
    system("cls");


    bool validacionDetalles = false;
    while(!validacionDetalles)
    {

        cout << "--------------- DETALLE DE VENTA --------------------" << endl;
        ///CREAR LOGICA PARA PODER CARGAR LOGICA DE DETALLE DE VENTA EN ARCHIVO DETALLE DE VENTAS
        registroDetalle.cargarDetalleDeVenta();
        if(DetalleVentas.Guardar(registroDetalle))
        {
            cout<< "El detalle de venta se ha registrado correctamente"<<endl;
        }

        cout << "-----------------------------------------------------" << endl;
        while(inputChar != 'S' && inputChar != 'N')
        {
            cout<< "Desea registrar otro producto para esta venta? S/N: ";
            cin >> inputChar;
            if(inputChar != 'S' && inputChar != 'N')
            {
                cout << "Opcion invalida! Vuelva a intentarlo";
            }
        }
        if(inputChar == 'N')
        {

            validacionDetalles = true;
        }
/*
Hacer esto una vez que se haya validado si hay un detalle de venta anterior al que se quiere registrar.
  else
        {

            validacionDetalles = true;
        }
*/

        system("pause");
        system("cls");
        /*


        cout << "TOTAL DE LA VENTA REALIZADA: " << DetalleVentas.Buscar(getIdVenta()).getImporte()<<endl;
        ///CREAR LA LOGICA PARA EL TOTAL DE LA VENTA REALIZADA


        */
        cout << "-----------------------------------" << endl;
    }
}


void listarClientes()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente registroCliente;

    cout << "Lista de Clientes (ID - Nombre): " << endl;
    for (int i = 0; i < Clientes.CantidadRegistros(); i++)
    {
        registroCliente = Clientes.Leer(i);
        cout << "ID: " << registroCliente.getID() << " - Nombre: " << registroCliente.getNombre() << endl;
    }

}
}
void Venta::mostrarVenta()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");

    cout <<"------------" << "Nro DE VENTA: " << getIdVenta() << "------------------------" << endl;

    cout << "FECHA: ";
    getFecha().mostrarFecha();
    cout << "VENDEDOR: "<<endl;
    Empleados.Buscar(getIdEmpleado()).mostrarEmpleado();
    cout<< endl;
    cout << "COMPRADOR: "<<endl;
    Clientes.Buscar(getIdCliente()).mostrarCliente();
    cout<< endl;
    cout << "FORMA DE PAGO: " << getFormaDePago() << endl<<endl;
    cout << "---------------DETALLE DE VENTA--------------------" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "TOTAL DE VENTA: " << getImporteTotal()<<endl;
    cout << "---------------------------------------------------" << endl;

}


