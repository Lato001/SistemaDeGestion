#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

#include "ArchivoVentas.h"
#include "ArchivoDetalleVentas.h"
#include "ArchivoProductos.h"
#include "ArchivoEmpleados.h"
#include "ArchivoClientes.h"

#include "Menu.h"
#include "Listados.h"
#include "Eliminados.h"
#include "Exportados.h"
#include "Informes.h"

#include "Venta.h"
#include "Producto.h"
#include "Empleado.h"
#include "Cliente.h"

#include "rlutil.h"
#include "Modificaciones.h"

using namespace std;

void Menu::getMainMenu()
{
    Exportados exportar;
    Informes infor;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"---------------MENU PRINCIPAL-------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Ventas"<<endl;
        cout<<"2. Empleados"<<endl;
        cout<<"3. Clientes"<<endl;
        cout<<"4. Productos"<<endl;
        cout<<"5. Informes"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);
        cin>>op;
        system("cls");
        if(op> (0) && op<6)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            mVentas();
            break;
        case 2:
            mEmpleados();
            break;
        case 3:
            mClientes();
            break;
        case 4:
            mProductos();
            break;
        case 5:
            infor.menuInformes();
            break;
        case 0:
            exit(0);
            break;
        default:

            mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

        }
        system("pause");
        system("cls");

        opcionValida = false;
    }
    while(!opcionValida);
}

void Menu::mEmpleados()
{
    Modificaciones modifica;
    Exportados exportar;
    Listados listar;
    Eliminados eliminar;
    int op=0;
    bool opcionValida=false;

    do
    {


        setColor(7);
        cout<<"-----------EMPLEADOS-----------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear"<<endl;
        cout<<"2. Listar"<<endl;
        cout<<"3. Modificar"<<endl;
        cout<<"4. Eliminar"<<endl;
        cout<<"5. Exportar"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);
        cin>>op;
        system("cls");
        if (op> (0) && op<6)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            crearEmpleado();
            break;
        case 2:
            listar.MenulistarEmpleados();
            break;
        case 3:
            modifica.modificarEmpleado();
            break;
        case 4:
            eliminar.menuEliminarEmpleados();
            break;
        case 5:
            exportar.ExportarEmpleados();
            break;
        case 0:
            getMainMenu();
            break;
        default:
            mensajeDeError("Opcion invalida!, vuelva a intentarlo" );
        }
        system("cls");
        opcionValida = false;
    }
    while(!opcionValida);
}

void Menu::mVentas()
{
    Exportados exportar;
    Listados listar;
    Eliminados eliminar;
    Modificaciones modifica;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"-----------MENU VENTAS------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear"<<endl;
        cout<<"2. Listar"<<endl;
        cout<<"3. Modificar"<<endl;
        cout<<"4. Eliminar"<<endl;
        cout<<"5. Exportar"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);
        cin>>op;
        system("cls");
        if(op> (0) && op<6)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            registrarVenta();
            break;
        case 2:
            listar.listarVentas();
            break;
        case 3:
            modifica.modificarRegistroVenta();
            break;
        case 4:
            eliminar.menuEliminarVentas();
            break;
        case 5:
            exportar.ExportarVentas();
            break;
        case 0:
            getMainMenu();
            break;
        default:

            mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

        }
        system("pause");
        system("cls");

        opcionValida = false;
    }
    while(!opcionValida);
}




void Menu::mProductos()
{
    Exportados exportar;
    Listados listar;
    Eliminados eliminar;
    Modificaciones modifica;
    int op = 0;
    bool opcionValida = false;

    do
    {
        setColor(7);
        cout << "-----------MENU PRODUCTOS------------" << endl;
        cout << "Elija la opcion que desee realizar" << endl;
        cout << "1. Crear" << endl;
        cout << "2. Listar" << endl;
        cout << "3. Modificar" << endl;
        cout << "4. Eliminar" << endl;
        cout << "5. Exportar" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "===================================" << endl;
        setColor(0);
        cin >> op;
        system("cls");

        if (op > 0 && op < 6)
        {
            opcionValida = true;
        }

        switch (op)
        {
        case 1:
            registrarProducto();
            break;
        case 2:
            listar.MenulistarProductos();
            break;
        case 3:
            modifica.modificarRegistroProductos();
            break;
        case 4:
            eliminar.menuEliminarProductos();
            break;
        case 5:
            exportar.ExportarProductos();
            break;
        case 0:
            getMainMenu();
            return;
        default:
            mensajeDeError("Opcion invalida!, vuelva a intentarlo");
        }
        system("pause");
        system("cls");
        opcionValida = false;
    }
    while (!opcionValida);
}

void Menu::mClientes(){
    Modificaciones modifica;
    Exportados exportar;
    Listados listar;
    Eliminados eliminar;
    int op=0;
    bool opcionValida=false;

    do
    {


        setColor(7);
        cout<<"-----------MENU CLIENTES-----------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear"<<endl;
        cout<<"2. Listar"<<endl;
        cout<<"3. Modificar"<<endl;
        cout<<"4. Eliminar"<<endl;
        cout<<"5. Exportar"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);
        cin>>op;
        system("cls");
        if (op> (0) && op<6)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            crearCliente();
            system ("pause");
            break;
        case 2:
            listar.MenulistarClientes();
            break;
        case 3:
            modifica.modificarClientes();
            system ("pause");
            break;
        case 4:
            eliminar.menuEliminarClientes();
            break;
        case 5:
            exportar.ExportarClientes();
            break;
        case 0:
            getMainMenu();
            break;
        default:
            mensajeDeError("Opcion invalida!, vuelva a intentarlo" );
        }
        system("cls");
        opcionValida = false;
    }
    while(!opcionValida);
}




void Menu::eliminar()
{
    int op=0;
    bool opcionValida=false;
    Eliminados eliminados;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Empleados"<<endl;
        cout<<"2. Clientes"<<endl;
        cout<<"3. Ventas"<<endl;
        cout<<"4. Productos"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);
        cin>>op;
        system("cls");
        if(op> (0) && op<4)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            eliminados.menuEliminarEmpleados();
            break;
        case 2:
            eliminados.menuEliminarClientes();
            break;
        case 3:
            eliminados.menuEliminarVentas();
            break;
        case 4:
            eliminados.menuEliminarProductos();
            break;
        case 0:
            getMainMenu();
            break;
        default:

            mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

        }
        system("pause");
        system("cls");

        opcionValida = false;
    }
    while(!opcionValida);
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
            setColor(2);
        cout << "Empleado guardado correctamente." << endl;
            setColor(7);
    }
    else
    {

        mensajeDeError("Error al registrar el Empleado." );

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
            setColor(2);
        cout << "Cliente guardado correctamente." << endl;
            setColor(7);
    }
    else
    {
            mensajeDeError("Error al guardar el cliente.");
    }
}

void Menu::registrarVenta()
{
    Menu menu;
    Venta venta;
    ArchivoVentas Ventas("ArchivoVentas.dat");
    venta.cargarVenta();
    if ( Ventas.Guardar(venta) )
    {
        cout<<endl;
            setColor(2);
        cout << "La venta se ha registrado correctamente." << endl;
           setColor(7);
    }
    else
    {
        mensajeDeError("Error al registrar la venta.");
    }
    system ("pause");
    system ("cls");
    menu.mVentas();

}
void Menu::registrarProducto()
{
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto producto;
    producto.cargarProducto();
    if ( Productos.Guardar(producto) )
    {
        cout<<endl;
            setColor(2);
        cout << "El producto se ha registrado correctamente." << endl;
            setColor(7);
    }
    else
    {
            mensajeDeError("Error al registrar el producto.");
    }

}

void Menu::setColor(int color) {
    rlutil::setColor(color);
}

void Menu::mensajeDeError(string mensaje){
setColor(4);
cout<<mensaje<<endl;
setColor(7);
}
