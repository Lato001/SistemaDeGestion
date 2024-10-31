#include <iostream>
#include <cstdio>


#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "Menu.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"
#include "Producto.h"
#include "rlutil.h"

using namespace std;

void Menu::getMainMenu()
{
    ArchivoClientes clientes("ArchivoClientes.dat");
    int op=0;
    bool opcionValida=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear Nuevo Empleado"<<endl;
        cout<<"2. Crear Nuevo Cliente"<<endl;
        cout<<"3. Listar Empleados"<<endl;
        cout<<"4. Listar Clientes"<<endl;
        cout<<"5. Registrar Venta"<<endl;
        cout<<"6. Listar Ventas"<<endl;
        cout<<"7. Registrar Producto"<<endl;
        cout<<"8. Listar Productos"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op> (0) && op<8)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            crearEmpleado();
            break;
        case 2:
            crearCliente();
            break;
        case 3:
            listarEmpleados();
            break;
        case 4:
            listarClientes();
            break;
        case 5:
            registrarVenta();
            break;
        case 6:
            listarVentas();
            break;
        case 7:
            registrarProducto();
            break;
        case 8:
            listarProductos();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
        }
        system("pause");
        system("cls");

        opcionValida = false;
    }
    while(!opcionValida);
}


void Menu::crearCliente()
{
    ArchivoClientes archivoClientes("ArchivoClientes.dat");


    Cliente cliente;
    cliente.cargarCliente();
    cliente.mostrarCliente();

    /*GUARDA Y VERIFICA DE QUE EL CLIENTE HAYA SIDO REGISTRADO
    EN LA ULTIMA POSICION DEL ARCHIVO DE CLIENTES
    */

    if ( archivoClientes.Guardar(cliente) )
    {
        cout<<endl;
        cout << "Cliente guardado correctamente." << endl;
    }
    else
    {
        cout << "Error al guardar el cliente." << endl;
    }
}


void Menu::crearEmpleado()
{
    ArchivoEmpleados archivoEmpleados("ArchivoEmpleados.dat");


    Empleado empleado;
    empleado.cargarEmpleado();
    empleado.mostrarEmpleado();
    if ( archivoEmpleados.Guardar(empleado) )
    {
        cout<<endl;
        cout << "Empleado guardado correctamente." << endl;
    }
    else
    {
        cout << "Error al registrar el Empleado." << endl;
    }
}


void Menu::listarEmpleados()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleado registro;
    int cantRegistros = Empleados.CantidadRegistros();
    cout<< "TOTAL DE EMPLEADOS: " << cantRegistros << endl;

    for (int i = 0; i < cantRegistros ; i++ )
    {
        registro = Empleados.Leer(i);
        registro.mostrarEmpleado();

    }
}
void Menu::listarClientes()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente registro;
    int cantRegistros = Clientes.CantidadRegistros();
    if(cantRegistros == 0)
    {
        cout<< "No se han encontrado clientes registrados" << endl;
    }
    else
    {

        cout<< "TOTAL DE CLIENTES: " << cantRegistros << endl;
        for (int i = 0; i < cantRegistros; i++ )
        {
            registro = Clientes.Leer(i);
            registro.mostrarCliente();
            cout<<endl;
        }
    }

}

void Menu::listarVentas()
{
    ArchivoVentas Ventas("ArchivoVentas.dat");
    Venta registro;
    int cantRegistros = Ventas.CantidadRegistros();

    if(cantRegistros == 0)
    {
        cout<< "No se han encontrado ventas registradas" << endl;
    }
    else
    {

        cout<< "TOTAL DE VENTAS: " << cantRegistros << endl<<endl;
        for (int i = 0; i < cantRegistros; i++ )
        {
            registro = Ventas.Leer(i);
            registro.mostrarVenta();
            cout<<endl;
        }
    }

}

void Menu::registrarVenta()
{
    ArchivoVentas Ventas("ArchivoVentas.dat");
    Venta venta;
    venta.cargarVenta();
    if ( Ventas.Guardar(venta) )
    {
        cout<<endl;
        cout << "La venta se ha registrado correctamente." << endl;
    }
    else
    {
        cout << "Error al registrar la venta." << endl;
    }

}
void Menu::registrarProducto(){
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto producto;
    producto.cargarProducto();
     if ( Productos.Guardar(producto) )
    {
        cout<<endl;
        cout << "El producto se ha registrado correctamente." << endl;
    }
    else
    {
        cout << "Error al registrar el producto." << endl;
    }

}
void Menu::listarProductos()
{
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto registro;
    int cantRegistros = Productos.CantidadRegistros();

    if(cantRegistros == 0)
    {
        cout<< "No se han encontrado productos registrados" << endl;
    }
    else
    {

        cout<< "TOTAL DE PRODUCTOS: " << cantRegistros << endl<<endl;
        for (int i = 0; i < cantRegistros; i++ )
        {
            registro = Productos.Leer(i);
            registro.mostrarProducto();
            cout<<endl;
        }
    }

}
