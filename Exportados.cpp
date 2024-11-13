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

        return;
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

    return;
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

    return;
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

        return;
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

    return;
    }
    else
    {
        system ("cls");
        menu.getMainMenu();
    }
}
