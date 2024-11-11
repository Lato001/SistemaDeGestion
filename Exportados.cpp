#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

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

#include "Menu.h"
#include "Listados.h"
#include "Eliminados.h"
#include "Exportados.h"

void Exportados::menuExportarCSV()
{
    Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
    menu.setColor(7);
    cout<<"----------------------------------"<<endl;
    cout<<"Elija la opcion que desee realizar"<<endl;
    cout<<"1. Productos"<<endl;
    cout<<"2. Ventas "<<endl;
    cout<<"3. Clientes "<<endl;
    cout<<"4. Empleado "<<endl;
    cout<<"5. Detalle de Ventas "<<endl;
    cout<<"0. Volver al menu principal"<<endl;
    cout<<"==================================="<<endl;
    menu.setColor(0);
           cin>>op;
        system("cls");
        if(op> (0) && op<6)
        {
            opcionValida=true;
        }

        switch (op)
        {

        case 1:
            ExportarProductos();
            break;
        case 2:
            ExportarVentas();
            break;
        case 3:
            ExportarClientes();
            break;
        case 4:
            ExportarEmpleados();
            break;
        case 5:
            ExportarDetalledeVentas();
            break;
        case 0:
            menu.getMainMenu();
            break;
        default:

            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

        }
        system("pause");
        system("cls");

        opcionValida = false;
    }
    while(!opcionValida);
}
void Exportados::ExportarProductos()
{
    Menu menu;
    ArchivoProductos Productos("ArchivoProductos.dat");

    string nombreCSV;
    menu.setColor(7);
    cout << "Ingrese el nombre que desea asignarle al archivo CSV de productos: "<<endl;
    cout << "0. Volver al menu principal "<<endl;
    menu.setColor(0);
    cin>>nombreCSV;
    if (nombreCSV != "0")
    {

        system("cls");
        menu.setColor(7);
        cout << "======================================================================" << endl;
        Productos.exportarProductosACSV(nombreCSV);
        cout << "======================================================================" << endl;
        system("pause");
        system("cls");

        menuExportarCSV();
    }
    else
    {
        system ("cls");
        menu.getMainMenu();
    }
}
void Exportados::ExportarVentas()
{
    Menu menu;
    ArchivoVentas Ventas("ArchivoVentas.dat");

    string nombreCSV;
    menu.setColor(7);
    cout << "0. Volver al menu principal "<<endl << endl;
    cout << "Ingrese el nombre que desea asignarle al archivo CSV de Ventas: ";
    menu.setColor(0);
    cin>>nombreCSV;
        if (nombreCSV != "0")
    {
    system("cls");
    menu.setColor(7);
    cout << "======================================================================" << endl;
    Ventas.exportarVentasACSV(nombreCSV);
    cout << "======================================================================" << endl;
    system("pause");
    system("cls");

    menuExportarCSV();
    }
    else
    {
        system ("cls");
    menu.getMainMenu();
    }
}
void Exportados::ExportarClientes()
{
    Menu menu;
    ArchivoClientes Clientes("ArchivoClientes.dat");

    string nombreCSV;
    menu.setColor(7);
    cout << "Ingrese el nombre que desea asignarle al archivo CSV de Clientes: "<<endl;
    cout << "0. Volver al menu principal "<<endl;
    menu.setColor(0);
    cin>>nombreCSV;
    if (nombreCSV != "0")
    {

    system("cls");
    menu.setColor(7);
    cout << "======================================================================" << endl;
    Clientes.exportarClientesACSV(nombreCSV);
    cout << "======================================================================" << endl;
    system("pause");
    system("cls");

    menuExportarCSV();
    }
    else
    {
        system ("cls");
        menu.getMainMenu();
    }
}
void Exportados::ExportarEmpleados()
{
    Menu menu;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");

    string nombreCSV;
    menu.setColor(7);
    cout << "0. Volver al menu principal "<<endl << endl;
    cout << "Ingrese el nombre que desea asignarle al archivo CSV de Empleados: ";
    menu.setColor(0);
    cin>>nombreCSV;
    if (nombreCSV != "0")
    {
        system("cls");
        menu.setColor(7);
        cout << "======================================================================" << endl;
        Empleados.exportarEmpleadosACSV(nombreCSV);
        cout << "======================================================================" << endl;
        system("pause");
        system("cls");

        menuExportarCSV();
    }
    else
    {
        system ("cls");
        menu.getMainMenu();
    }
}
void Exportados::ExportarDetalledeVentas()
{
    Menu menu;
    ArchivoDetalleVentas DetalleDeVentas("ArchivoDetalleVentas.dat");

    string nombreCSV;
    menu.setColor(7);
    cout << "Ingrese el nombre que desea asignarle al archivo CSV de Detalle De Ventas: "<<endl;
    cout << "0. Volver al menu principal "<<endl;
    menu.setColor(0);
    cin>>nombreCSV;
    if (nombreCSV != "0")
    {

    system("cls");
    menu.setColor(7);
    cout << "======================================================================" << endl;
    DetalleDeVentas.exportarDetalleVentasACSV(nombreCSV);
    cout << "======================================================================" << endl;
    system("pause");
    system("cls");

    menuExportarCSV();
    }
    else
    {
        system ("cls");
        menu.getMainMenu();
    }
}
