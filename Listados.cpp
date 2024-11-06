#include <iostream>

#include "Menu.h"


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
#include "Listados.h"

using namespace std;

void Listados::MenulistarClientes()
{
    Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
    menu.setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Por Nombre"<<endl;
        cout<<"2. Por Orden Alfabetico"<<endl;
        cout<<"3. Por ID"<<endl;
        cout<<"4. Listar todos"<<endl;
        cout<<"5. Listar Por Nro de Compras Realizadas"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
    menu.setColor(0);
        cin>>op;

        system("cls");
        if(op>0 && op<6)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:
            listarClientesxName();
            break;
        case 2:
            listarClientesxOrdenAlfabetico();
            break;
        case 3:
            listarClientesxID();
            break;
        case 4:
            listarClientesAll();
            break;
        case 5:
            listarClientesxComprasRealizadas();
        case 0:
            menu.getMainMenu();
        default:

            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo");

        }
        system("pause");
        system("cls");
    }
    while(!opcionValida);
    MenulistarClientes();
}
void Listados::MenulistarEmpleados()
{
    Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
   menu.setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Por Nombre"<<endl;
        cout<<"2. Por Orden Alfabetico"<<endl;
        cout<<"3. Por ID"<<endl;
        cout<<"4. Por Fecha de Ingreso"<<endl;
        cout<<"5. Listar todos"<<endl;
        cout<<"6. Listar por asistencias"<<endl;
        cout<<"7. Listar por Vacaciones Activas SI/NO"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
   menu.setColor(0);
        cin>>op;

        system("cls");
        if(op>0 && op<8)
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
        case 6:
            listarEmpleadosxAsistencias();
            break;
        case 7:
            listarEmpleadosxVacaciones();
            break;
        case 0:
            menu.getMainMenu();
        default:
            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo");
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    MenulistarEmpleados();
}
void Listados::listarEmpleadosAll()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleado registro;

    Empleados.FiltrarEmpleados();
    system("pause");
    system("cls");
    MenulistarEmpleados();
}

void Listados::listarEmpleadosxOrdenAlfabetico()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleados.FiltrarPorOrdenAlfabetico();
        system("pause");
        system("cls");
        MenulistarEmpleados();
}

void Listados::listarEmpleadosxName()
{
    Menu menu;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    menu.setColor(7);
    cout<<"Ingrese el nombre del empleado a filtrar: ";
    menu.setColor(0);
    string nombre;
    cin >> nombre;
    Empleados.FiltrarPorNombre(nombre);
    menu.setColor(7);
    system("pause");
    system("cls");
    MenulistarEmpleados();
}
void Listados::listarEmpleadosxID()
{
    Menu menu;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
     menu.setColor(7);
    cout<<"Ingrese el ID del empleado a filtrar: ";
     menu.setColor(0);
    int id;
    cin >> id;
    Empleados.FiltrarPorID(id);
     menu.setColor(7);
}

void Listados::listarEmpleadosxAsistencias()
{
ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
Empleados.FiltrarPorAsistencias();
system("pause");
system("cls");
MenulistarEmpleados();

}
void Listados::listarEmpleadosxVacaciones()
{
    Menu menu;
ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
int op = -1;
int m = -1;
bool opcionValida=false;

while (op!=0 || op !=1)
    {
            menu.setColor(7);
    cout << "0.Filtrar Empleados de Vacaciones "<<endl;
    cout << "1.Filtrar Empleados Trabajando "<<endl;
    cout << "2.Volver al menu principal "<<endl;
     menu.setColor(0);
    cin >> op;
    system ("cls");
    if(op!=0 || op !=1)
    {
        if (op==2)
        {
            system ("cls");
            menu.setColor(7);
            menu.getMainMenu();
        }
        else{
        Empleados.FiltrarPorVacacionesActivas(op);
        menu.setColor(0);
        if(op==0 || op==1)
        {
            opcionValida=true;
        }
        if (opcionValida==false)
        {


            menu.mensajeDeError("Opcion invalida! vuelva a intentarlo");

        }
        }
    }
    system("pause");
    system("cls");
    menu.setColor(7);
    }
    MenulistarEmpleados();
}
void Listados::listarEmpleadosxFecha()
{
    ArchivoEmpleados Empleados ("ArchivoEmpleados.dat");
    Empleado registro;
    Empleados.FiltrarPorFecha();
    system ("pause");
    system ("cls");

    MenulistarEmpleados();
}
void Listados::listarClientesAll()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente registro;
    Clientes.FiltrarClientes();
    system("pause");
    system("cls");
    MenulistarClientes();

}
void Listados::listarClientesxName()
{
    Menu menu;
    ArchivoClientes Clientes ("ArchivoClientes.dat");
    menu.setColor(7);
    cout<<"Ingrese el nombre del cliente a filtrar: ";
    menu.setColor(0);
    string nombre;
    cin >> nombre;
    Clientes.FiltrarPorNombre(nombre);
    menu.setColor(7);
    system("pause");
    system("cls");
    MenulistarClientes();
}

void Listados::listarClientesxOrdenAlfabetico()
{
    Menu menu;
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Clientes.FiltrarPorOrdenAlfabetico();
        system("pause");
        system("cls");
        MenulistarClientes();
}
void Listados::listarClientesxID()
{
    Menu menu;
    ArchivoClientes Clientes("ArchivoClientes.dat");
    menu.setColor(7);
    cout<<"Ingrese el ID del Cliente a filtrar: ";
    menu.setColor(0);
    int id;
    cin >> id;
    Clientes.FiltrarPorID(id);
    menu.setColor(7);
}
void Listados::listarClientesxComprasRealizadas(){
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Clientes.FiltrarPorNComprasRealizadas();
    system("pause");
    system("cls");
}

void Listados::listarVentas()
{
    Menu menu;
    ArchivoVentas Ventas("ArchivoVentas.dat");
    Venta registro;
    int cantRegistros = Ventas.CantidadRegistros();

    if(cantRegistros == 0)
    {

       menu.mensajeDeError("No se han encontrado ventas registradas" );

    }
    else
    {
        for (int i = 0; i < cantRegistros; i++ )
        {
            registro = Ventas.Leer(i);
            registro.mostrarVenta();
            cout<<endl;
        }
    }
}
void Listados::MenulistarProductos()
{
 Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
        menu.setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Listar por Nombre"<<endl;
        cout<<"2. Listar por ID"<<endl;
        cout<<"3. Listar por Categoria"<<endl;
        cout<<"4. Listar Disponibles"<<endl;
        cout<<"5. Listar Todos"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        menu.setColor(0);

        cin>>op;
        system("cls");
        if(op>0 && op<6)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:
            listarProductosxName();
            break;
        case 2:
            listarProductosxID();
            break;
        case 3:
            listarProductosxCategoria();
            break;
        case 4:
            listarProductosDisponibles();
            break;
        case 5:
            listarProductosAll();
            break;
        case 0:
            menu.getMainMenu();
        default:
            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo");
            menu.setColor(7);
        }



    }
    while(!opcionValida);
}
void Listados::MenuListarProductosDetalleVentas()
{
Menu menu;
int opcion;
    bool opcionValida = false;
    while (!opcionValida)
    {
        Menu::setColor(7);

        cout<<"----------------------------------"<<endl;
        cout<<"Como desea listar los productos"<<endl;
        cout<<"1. Listar por Nombre"<<endl;
        cout<<"2. Listar por Categoria"<<endl;
        cout<<"3. Listar Productos Disponibles"<<endl;
        cout<<"==================================="<<endl;
        Menu::setColor(0);
        cin>>opcion;
        if (opcion > 0 && opcion < 4 )
        {
            opcionValida = true;
            switch (opcion)
            {
            case 1:
                listarProductosxName();
            break;
            case 2:
                listarProductosxCategoria();
            break;
            case 3:
                listarProductosDisponibles();
            break;
            default:
                menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

            }

        }
    }

}

void Listados::listarProductosAll()
{
    Menu menu;
    ArchivoProductos Productos("ArchivoProductos.dat");
    Productos.FiltrarProductos();
}
void Listados::listarProductosxName()
{
    Menu menu;
    ArchivoProductos Productos ("ArchivoProductos.dat");
    menu.setColor(7);
    cout<<"Ingrese el nombre del producto a filtrar: ";
    menu.setColor(0);
    string nombre;
    cin >> nombre;
    Productos.FiltrarPorNombre(nombre);
    menu.setColor(7);
}
void Listados::listarProductosxID()
{
    Menu menu;
    ArchivoProductos Productos("ArchivoProductos.dat");
    menu.setColor(7);
    cout<<"Ingrese el ID del Producto a filtrar: ";
    menu.setColor(0);
    int id;
    cin >> id;
    Productos.FiltrarPorID(id);
    menu.setColor(7);
}
void Listados::listarProductosDisponibles(){
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto producto;
 for (int i = 0; i < Productos.CantidadRegistros(); i++)
                {
                    producto = Productos.Leer(i);
                    if(producto.getStock() > 0){

                    producto.mostrarProducto();
                    }
                    cout << endl;
                }

}
void Listados::listarProductosxCategoria()
{
    Menu menu;
    ArchivoProductos Productos("ArchivoProductos.dat");
    menu.setColor(7);
    cout<<"Ingrese la categoria del Producto a filtrar: ";
    menu.setColor(0);
    string categoria;
    cin >> categoria;
    Productos.FiltrarPorCategoria(categoria);
    menu.setColor(7);
}
