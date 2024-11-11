#include <iostream>

#include "Menu.h"
#include "Listados.h"

#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "ArchivoDetalleVentas.h"

#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"
#include "Producto.h"

#include "rlutil.h"
#include "Modificaciones.h"

using namespace std;

void Modificaciones::modificarEmpleado()
{
    Menu menu;

    ArchivoEmpleados archivoEmpleados("ArchivoEmpleados.dat");
    Listados listados;
    int empleadoID;
    menu.setColor(7);
    listados.listarEmpleadosAll();
    cout << "Ingrese el ID del empleado que desea modificar: ";
    menu.setColor(0);
    cin >> empleadoID;
    archivoEmpleados.ModificarEmpleado(empleadoID);
}

void Modificaciones::modificarRegistroVenta()
{
    Listados listados;
    Menu menu;
    int input;
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");
    Venta venta;
    bool opcionValida = false;
    listados.listarVentas();
    menu.setColor(7);
    cout<< "Seleccione el ID de la venta a modificar: "<<endl;
    cout<<"0. Volver al menu principal"<<endl;
    menu.setColor(0);
    cin >> input;
    system("cls");
    if (input !=0 )
    {
        if( Ventas.Buscar(input).getIdVenta() !=  -1)
        {
            while(!opcionValida)
            {
                venta = Ventas.Buscar(input);
                menu.setColor(7);
                cout<<"Elija el atributo a modificar" << endl;
                cout<<"1. Fecha: ";
                venta.getFecha().mostrarFecha();
                cout<<"2. Empleado: " ;
                menu.setColor(0);
                cout <<Empleados.Buscar(venta.getIdVenta()).getNombre()<< " " <<Empleados.Buscar(venta.getIdVenta()).getApellido() <<endl;
                menu.setColor(7);
                cout<<"3. Cliente: " ;
                menu.setColor(0);
                cout << Clientes.Buscar(venta.getIdVenta()).getNombre()<< " " <<Clientes.Buscar(venta.getIdVenta()).getApellido() <<endl;
                menu.setColor(7);
                cout<< "4. Forma de Pago: ";
                menu.setColor(0);
                switch (venta.getFormaDePago())
                {
                case 1:
                    cout<< "Efectivo";
                    break;
                case 2:
                    cout<< "Debito";
                    break;
                case 3:
                    cout<<"Credito";
                    break;
                }
                cout<<endl;
                menu.setColor(7);
                cout<< "0. Volver al menu principal"<<endl<<endl;
                cout<< "Seleccione una opcion: ";
                menu.setColor(0);
                cin >> input;
                opcionValida = (input> 0 && input< 5);
                if(!opcionValida)
                {
                    if(input != 0)
                    {

                        menu.mensajeDeError("Opcion invalida");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        menu.getMainMenu();
                    }
                }
            }
        }
        else
        {
            menu.mensajeDeError("No existe venta con este ID, vuelva a intentarlo");
            menu.mVentas();
        }
        system("cls");
        menu.setColor(7);
        switch (input)
        {
        case 1:
            Ventas.ModificarVenta(venta.getIdVenta(),1);
            break;
        case 2:
            Ventas.ModificarVenta(venta.getIdVenta(),2);
            break;
        case 3:
            Ventas.ModificarVenta(venta.getIdVenta(),3);
            break;
        case 4:
            Ventas.ModificarVenta(venta.getIdVenta(),4);
            break;
        default:
            break;
        }
    }
    else
    {
        menu.getMainMenu();
    }
}

void Modificaciones::modificarProductos()
{
    Menu menu;
    ArchivoProductos archivoProductos("ArchivoProductos.dat");
    int productoID;
    menu.setColor(7);
    Listados listados;
    listados.listarProductosAll();
    cout << "Ingrese el ID del producto que desea modificar: ";
    cin >> productoID;
    archivoProductos.ModificarProducto(productoID);
}
void Modificaciones::modificarClientes()
{
    Menu menu;
    ArchivoClientes archivoClientes("ArchivoClientes.dat");
    Listados listados;
    int clienteID;
    menu.setColor(7);
    listados.listarClientesAll();
    cout << "Ingrese el ID del cliente que desea modificar: ";
    menu.setColor(0);
    cin >> clienteID;
    archivoClientes.ModificarCliente(clienteID);
}
void Modificaciones::modificarDetalleVentas()
{
    Menu menu;
    ArchivoDetalleVentas archivoDetalleVentas("ArchivoDetalleVentas.dat");
    Listados listados;
    int idVenta;
    menu.setColor(7);
    listados.listarVentas();
    cout << "Ingrese el ID de la venta que desea modificar: ";
    menu.setColor(0);
    cin >> idVenta;
    archivoDetalleVentas.ModificarDetalleVenta(idVenta);
}
