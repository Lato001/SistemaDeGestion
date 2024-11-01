#include <iostream>
#include <cstdio>
#include <algorithm>

#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "Menu.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"
#include "Producto.h"


using namespace std;

void Menu::getMainMenu()
{
    int op=0;
    bool opcionValida=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Listar"<<endl;
        cout<<"2. Crear (Empleado / Usuario)"<<endl;
        cout<<"3. Registrar (Ventas / Productos)"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op> (0) && op<4)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            listar();
            break;
        case 2:
            crear();
            break;
        case 3:
            registrar();
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
void Menu::listar()
{
    int op=0;
    bool opcionValida=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Listar Ventas"<<endl;
        cout<<"2. Listar Productos"<<endl;
        cout<<"3. Listar Empleados"<<endl;
        cout<<"4. Listar Clientes"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op>0 && op<5)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:
            listarVentas();
            break;
        case 2:
            listarProductos();
            break;
        case 3:
            MenulistarEmpleados();
            break;
        case 4:
            listarClientes();
            break;
        case 0:
            getMainMenu();
        default:
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    listar();
}
void Menu::crear()
{
    int op=0;
    bool opcionValida=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear Empleado"<<endl;
        cout<<"2. Crear Cliente"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op>0 && op<3)
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
        case 0:
            getMainMenu();
            break;
        default:
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    crear();
}
void Menu::registrar()
{
    int op=0;
    bool opcionValida=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Registrar Venta"<<endl;
        cout<<"2. Registrar Producto"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op>0 && op<3)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:
            registrarVenta();
            break;
        case 2:
            registrarProducto();
            break;
        case 0:
            getMainMenu();
        default:
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    registrar();
}

void Menu::MenulistarEmpleados()
{
    int op=0;
    bool opcionValida=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Por Nombre"<<endl;
        cout<<"2. Por Orden Alfabetico"<<endl;
        cout<<"3. Por ID"<<endl;
        cout<<"4. Por Fecha de Ingreso"<<endl;
        cout<<"5. Listar todos"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op>0 && op<6)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:
            listarEmpleadosxName();
            break;
        case 2:
            listarEmpleadosxOrdenAlfabetico();
            break;
        case 3:
            listarEmpleadosxID();
            break;
        case 4:
            listarEmpleadosxFecha();
            break;
        case 5:
            listarEmpleadosAll();
            break;
        case 0:
            getMainMenu();
        default:
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    MenulistarEmpleados();
}
void Menu::listarEmpleadosAll()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleado registro;
    int cantRegistros = Empleados.CantidadRegistros();
    if(cantRegistros == 0)
    {
        cout<< "No se han encontrado empleados registrados" << endl;
    }
    else
    {

        cout<< "TOTAL DE EMPLEADOS: " << cantRegistros << endl;
        for (int i = 0; i < cantRegistros; i++ )
        {
            registro = Empleados.Leer(i);
            registro.mostrarEmpleado();
            cout<<endl;
        }
    }
}

void Menu::listarEmpleadosxOrdenAlfabetico()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    int cantRegistros = Empleados.CantidadRegistros();
    Empleado* registro = new Empleado[cantRegistros];

    if(cantRegistros == 0)
    {
        cout<< "No se han encontrado empleados registrados" << endl;
    }
    else
    {

        for (int i = 0; i < cantRegistros; i++ )
        {
            registro[i] = Empleados.Leer(i);
        }
        for (int i = 0; i <= cantRegistros - 1; i++)
        {
            for (int j = 0; j <= cantRegistros - i - 1; j++)
            {
                if (registro[j].getNombre() > registro[j + 1].getNombre())
                {
                    Empleado temp = registro[j];
                    registro[j] = registro[j + 1];
                    registro[j + 1] = temp;
                }
                for (int i= 0; i <= cantRegistros ; i++ )
                {
                    registro[i].mostrarEmpleado();
                }
            }
        }
    }
    delete[] registro;
}

void Menu::listarEmpleadosxName()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleado registro;
    bool encontrado = false;
    string nombreBuscado;
    int cantRegistros = Empleados.CantidadRegistros();

    if (cantRegistros == 0)
    {
        cout << "No se han encontrado empleados registrados" << endl;
        return;
    }

    cout << "Ingrese el nombre del empleado a buscar: ";
    cin >> nombreBuscado;

    for (int i = 0; i < cantRegistros; i++)
    {
        registro = Empleados.Leer(i);
        if (registro.getNombre() == nombreBuscado)
        {
            registro.mostrarEmpleado();
            encontrado = true;
        }

    }
        if (!encontrado)
        {
            cout << "No se encontraron empleados con el nombre: " << nombreBuscado << endl;
        }
}
void Menu::listarEmpleadosxID()
{}
void Menu::listarEmpleadosxFecha()
{}
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
void Menu::registrarProducto()
{
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



