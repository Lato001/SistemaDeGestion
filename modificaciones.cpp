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
    cout<<"0. Volver al Menu de Empleados"<<endl << endl;
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
                menu.setColor(0);
                cout<< empleado.getDNI();
                menu.setColor(7);
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
                        menu.mEmpleados();
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
        menu.mEmpleados();
    }
}

void Modificaciones::modificarRegistroVenta()
{
    Listados listados;
    Menu menu;
    int input, idVenta;
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");
    Venta venta;
    bool opcionValida = false;
    listados.listarVentas();
    menu.setColor(7);
    cout << endl;
    cout<<"0. Volver al Menu de Ventas"<<endl << endl;
    cout<< "Seleccione el ID de la venta a modificar: "<<endl;
    menu.setColor(0);
    cin >> idVenta;
    system("cls");
    if (idVenta !=0 )
    {
        if( Ventas.Buscar(idVenta).getIdVenta() !=  -1)
        {
            while(!opcionValida)
            {
                venta = Ventas.Buscar(idVenta);
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
                        menu.mVentas();
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
        menu.mVentas();
    }
}

void Modificaciones::modificarRegistroProductos()
{
    Menu menu;
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto producto;
    int input, idProducto;
    menu.setColor(7);
    bool opcionValida = false;
    Listados listados;
    listados.listarProductosAll();
    cout << endl;
    cout<<"0. Volver al Menu Productos"<<endl << endl;
    cout << "Ingrese el ID del producto que desea modificar: ";
    cin >> idProducto;
    system("cls");



     if (idProducto !=0 )
    {
        if( Productos.Buscar(idProducto).getID() !=  -1)
        {
            while(!opcionValida)
            {
                producto = Productos.Buscar(idProducto);
                menu.setColor(7);
                cout<<"Elija el atributo a modificar" << endl;
                cout<< "1. Nombre del Producto: " << producto.getNombre() << endl;
                cout<<"2. Categoria del Producto: "<< producto.getCategoriaProducto()<<endl;
                cout<<"3. Precio Unitario: "  << producto.getPrecioUnitario()<<endl;
                cout<< "4. Stock: " <<producto.getStock()<<endl;
                cout<<endl;
                menu.setColor(7);
                cout<< "0. Volver al menu principal"<<endl<<endl;
                cout<< "Seleccione una opcion: ";
                menu.setColor(0);

                cin >> input;
                system("cls");
                opcionValida = (input> 0 && input< 5);
                if(!opcionValida)
                {
                    if(input != 0)
                    {

                        menu.mensajeDeError("Opcion invalida");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        system("cls");
                        menu.mProductos();
                    }
                }
            }
        }
        else
        {
            menu.mensajeDeError("No existe Producto con este ID, vuelva a intentarlo");
            menu.mProductos();
        }
        system("cls");
        menu.setColor(7);
        switch (input)
        {
        case 1:
            Productos.ModificarProducto(producto.getID(),1);
            break;
        case 2:
            Productos.ModificarProducto(producto.getID(),2);
            break;
        case 3:
           Productos.ModificarProducto(producto.getID(),3);
            break;
        case 4:
            Productos.ModificarProducto(producto.getID(),4);
            break;
        default:
            break;
        }
    }
    else
    {
        menu.mProductos();
    }
}
void Modificaciones::modificarClientes()
{
    Menu menu;
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Listados listados;
    int idCliente, input;
    Cliente cliente;
    bool opcionValida;
    menu.setColor(7);
    listados.listarClientesAll();
    cout << endl;
    cout<<"0. Volver al Menu de Clientes"<<endl << endl;
    cout << "Ingrese el ID del cliente que desea modificar: ";
    menu.setColor(0);
    cin >> idCliente;
    system("cls");


    if (idCliente !=0 )
    {
        if( Clientes.Buscar(idCliente).getID() !=  -1)
        {
            while(!opcionValida)
            {
                cliente = Clientes.Buscar(idCliente);
                menu.setColor(7);
                cout<<"Elija el atributo a modificar" << endl;
                cout<<"1. DNI: ";
                menu.setColor(0);
                cout<< cliente.getDNI();
                cout<<endl;
                menu.setColor(7);
                cout<<"2. Nombre: " ;
                menu.setColor(0);
                cout <<cliente.getNombre()<<endl;
                menu.setColor(7);
                cout<<"3. Apellido: " ;
                menu.setColor(0);
                cout << cliente.getApellido()<<endl;
                menu.setColor(7);
                cout<<"4. Email: " ;
                menu.setColor(0);
                cout << cliente.getEmail()<<endl;
                menu.setColor(7);
                cout<<"5. Numero de telefono: " ;
                menu.setColor(0);
                cout << cliente.getnTelefono()<<endl;
                menu.setColor(7);
                cout<<"6. Localidad: " ;
                menu.setColor(0);
                cout << cliente.getLocalidad()<<endl;
                cout<<endl;
                menu.setColor(7);
                cout<< "0. Volver al menu principal"<<endl<<endl;
                cout<< "Seleccione una opcion: ";
                menu.setColor(0);

                cin >> input;
                system("cls");
                opcionValida = (input> 0 && input< 7);
                if(!opcionValida)
                {
                    if(input != 0)
                    {

                        menu.mensajeDeError("Opcion invalida");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        system("cls");
                        menu.mClientes();
                    }
                }
            }
        }
        else
        {
            menu.mensajeDeError("No existe Cliente con este ID, vuelva a intentarlo");
            menu.mClientes();
        }
        system("cls");
        menu.setColor(7);
        switch (input)
        {
        case 1:
            Clientes.ModificarCliente(cliente.getID(),1);
            break;
        case 2:
            Clientes.ModificarCliente(cliente.getID(),2);
            break;
        case 3:
            Clientes.ModificarCliente(cliente.getID(),3);
            break;
        case 4:
            Clientes.ModificarCliente(cliente.getID(),4);
            break;
        case 5:
            Clientes.ModificarCliente(cliente.getID(),5);
            break;
        case 6:
            Clientes.ModificarCliente(cliente.getID(),6);
            break;
        default:
            break;
        }
    }
    else
    {
        menu.mClientes();
    }


}

