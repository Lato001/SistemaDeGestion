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
    Listados listados;
    Menu menu;
    int input;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");

    Empleado empleado;
    bool opcionValida = false;
    listados.listarEmpleadosAll();
    menu.setColor(7);
    cout << endl;
    cout<<"0. Volver al menu principal"<<endl << endl;
    cout<< "Seleccione el ID del empleado a modificar: "<<endl;
    menu.setColor(0);
    cin >> input;
    system("cls");
    if (input !=0 )
    {
        if( Empleados.Buscar(input).getID() !=  -1)
        {
            while(!opcionValida)
            {
                empleado = Empleados.Buscar(input);
                menu.setColor(7);
                cout<<"Elija el atributo a modificar" << endl;
                cout<<"1. DNI: ";
                empleado.getDNI();
                cout<<endl;
                cout<<"2. Nombre: " ;
                menu.setColor(0);
                cout <<empleado.getNombre()<<endl;
                menu.setColor(7);
                cout<<"3. Apellido: " ;
                menu.setColor(0);
                cout << empleado.getApellido()<<endl;
                menu.setColor(7);
                cout<<"4. Email: " ;
                menu.setColor(0);
                cout << empleado.getEmail()<<endl;
                menu.setColor(7);
                cout<<"5. Numero de telefono: " ;
                menu.setColor(0);
                cout << empleado.getnTelefono()<<endl;
                menu.setColor(7);
                cout<<"6. Localidad: " ;
                menu.setColor(0);
                cout << empleado.getLocalidad()<<endl;
                menu.setColor(7);
                cout<< "7. Fecha de Ingreso: ";
                menu.setColor(0);
                empleado.getFechaIngreso().mostrarFecha();
                menu.setColor(7);
                cout<< "8. Asistencias: ";
                menu.setColor(0);
                cout << Empleados.Buscar(empleado.getID()).getAsistencias()<<endl;
                menu.setColor(7);
                cout<< "9. Vacaciones: ";
                menu.setColor(0);
                cout << Empleados.Buscar(empleado.getID()).getIsVacaciones()<<endl;
                menu.setColor(7);
                cout<< "10. Sueldo: ";
                menu.setColor(0);
                cout << Empleados.Buscar(empleado.getID()).getSueldo()<<endl;
                menu.setColor(7);
                cout<<endl;
                cout<< "0. Volver al menu principal"<<endl<<endl;
                cout<< "Seleccione una opcion: ";
                menu.setColor(0);
                cin >> input;
                opcionValida = (input> 0 && input< 11);
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
            menu.mensajeDeError("No existe Empleado con este ID, vuelva a intentarlo");
            menu.mEmpleados();
        }
        system("cls");
        menu.setColor(7);
        switch (input)
        {
        case 1:
            Empleados.ModificarEmpleado(empleado.getID(),1);
            break;
        case 2:
            Empleados.ModificarEmpleado(empleado.getID(),2);
            break;
        case 3:
            Empleados.ModificarEmpleado(empleado.getID(),3);
            break;
        case 4:
            Empleados.ModificarEmpleado(empleado.getID(),4);
            break;
        case 5:
            Empleados.ModificarEmpleado(empleado.getID(),5);
            break;
        case 6:
            Empleados.ModificarEmpleado(empleado.getID(),6);
            break;
        case 7:
            Empleados.ModificarEmpleado(empleado.getID(),7);
            break;
        case 8:
            Empleados.ModificarEmpleado(empleado.getID(),8);
            break;
        case 9:
            Empleados.ModificarEmpleado(empleado.getID(),9);
            break;
        case 10:
            Empleados.ModificarEmpleado(empleado.getID(),10);
            break;

        default:
            break;
        }
    }
    else
    {
        system ("cls");
        menu.getMainMenu();
    }
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
    cout << endl;
    cout<<"0. Volver al menu principal"<<endl << endl;
    cout<< "Seleccione el ID de la venta a modificar: "<<endl;
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
