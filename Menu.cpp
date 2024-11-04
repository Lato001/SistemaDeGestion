#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

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
             setColor(4);
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
             setColor(7);
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
            MenulistarClientes();
            break;
        case 0:
            getMainMenu();
        default:
             setColor(4);
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
              setColor(7);
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
         setColor(7);
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
                setColor(4);
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
               setColor(7);
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
    rlutil::setColor(rlutil::BLACK);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Registrar Venta"<<endl;
        cout<<"2. Registrar Producto"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
            setColor(7);
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
                setColor(4);
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
                setColor(7);
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    registrar();
}
void Menu::MenulistarClientes()
{
    int op=0;
    bool opcionValida=false;

    do
    {
    setColor(0);
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
            setColor(7);
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
            listarClientesxFecha();
            break;
        case 5:
            listarClientesAll();
            break;
        case 0:
            getMainMenu();
        default:
                setColor(4);
            cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
                setColor(7);
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    MenulistarClientes();
}
void Menu::MenulistarEmpleados()
{
    int op=0;
    bool opcionValida=false;

    do
    {
    rlutil::setColor(rlutil::BLACK);
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
            setColor(7);
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
            mensajeDeError("Opcion invalida!, vuelva a intentarlo");
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
        mensajeDeError("No se han encontrado empleados registrados" );
    }
    else
    {
    setColor(2);
        cout<< "TOTAL DE EMPLEADOS: " << cantRegistros << endl;
            setColor(7);
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
            setColor(4);
        cout<< "No se han encontrado empleados registrados" << endl;
            setColor(7);
    }
    else
    {

        for (int i = 0; i < cantRegistros; i++ )
        {
            registro[i] = Empleados.Leer(i);
        }
        for (int i = 0; i <= cantRegistros ; i++)
        {
            for (int j = 0; j <= cantRegistros ; j++)
            {
                if (strcmp (registro[j].getNombre(),registro[i].getNombre()) > 0)
                {
                    Empleado temp = registro[i];
                    registro[i] = registro[j];
                    registro[j] = temp;
                }
            }
        }
        for ( int i = 0 ; i <=cantRegistros ; i++ )
        {
        registro[i].mostrarEmpleado();
        }
    }
    delete[] registro;
        system("pause");
        system("cls");
        MenulistarEmpleados();
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
            setColor(4);
        cout << "No se han encontrado empleados registrados" << endl;
           setColor(7);
        return;
    }
    setColor(0);
    cout << "Ingrese el nombre del empleado a buscar: ";
    setColor(7);
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
                setColor(4);
            cout << "No se encontraron empleados con el nombre: " << nombreBuscado << endl;
                setColor(7);
        }
}
void Menu::listarEmpleadosxID()
{}
void Menu::listarEmpleadosxFecha()
{}


void Menu::listarClientesAll()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente registro;
    int cantRegistros = Clientes.CantidadRegistros();
    if(cantRegistros == 0)
    {
        mensajeDeError("No se han encontrado clientes registrados");
    }
    else
    {

        setColor(2);
        cout<< "TOTAL DE CLIENTES: " << cantRegistros << endl;
            setColor(7);
        for (int i = 0; i < cantRegistros; i++ )
        {
            registro = Clientes.Leer(i);
            registro.mostrarCliente();
            cout<<endl;
        }
    }

}
void Menu::listarClientesxName()
{

    ArchivoClientes Clientes ("ArchivoClientes.dat");
    Cliente registro;
    bool encontrado = false;
    string nombreBuscado;
    int cantRegistros = Clientes.CantidadRegistros();

    if (cantRegistros == 0)
    {
           mensajeDeError("No se han encontrado clientes registrados");
        return;
    }
    mensajeDeError("Ingrese el nombre del cliente a buscar: ");
    cin >> nombreBuscado;

    for (int i = 0; i < cantRegistros; i++)
    {
        registro = Clientes.Leer(i);
        if (registro.getNombre() == nombreBuscado)
        {
            registro.mostrarCliente();
            encontrado = true;
        }

    }
    if (!encontrado)
    {
            mensajeDeError("No se encontraron clientes con el nombre ingresado: ");
    }

}



void Menu::listarClientesxOrdenAlfabetico()
{
    ArchivoClientes Clientes ("ArchivoClientes.dat");
    int cantRegistros = Clientes.CantidadRegistros();
    Cliente* registro = new Cliente[cantRegistros];

    if(cantRegistros == 0)
    {
            setColor(4);
        cout<< "No se han encontrado empleados registrados" << endl;
            setColor(7);
    }
    else
    {

        for (int i = 0; i < cantRegistros; i++ )
        {
            registro[i] = Clientes.Leer(i);
        }
        for (int i = 0; i <= cantRegistros ; i++)
        {
            for (int j = 0; j <= cantRegistros ; j++)
            {
                if (strcmp (registro[j].getNombre(),registro[i].getNombre()) > 0)
                {
                    Cliente temp = registro[i];
                    registro[i] = registro[j];
                    registro[j] = temp;
                }
            }
        }
        for ( int i = 0 ; i <=cantRegistros ; i++ )
        {
            registro[i].mostrarCliente();
        }
    }
    delete[] registro;
    system("pause");
    system("cls");
    MenulistarClientes();
}
    void Menu::listarClientesxID()
    {

    }
    void Menu::listarClientesxFecha()
    {

    }

void Menu::listarVentas()
{
    ArchivoVentas Ventas("ArchivoVentas.dat");
    Venta registro;
    int cantRegistros = Ventas.CantidadRegistros();

    if(cantRegistros == 0)
    {
            setColor(4);
        cout<< "No se han encontrado ventas registradas" << endl;
            setColor(7);
    }
    else
    {
    setColor(2);
        cout<< "TOTAL DE VENTAS: " << cantRegistros << endl<<endl;
            setColor(7);
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
            setColor(4);
        cout<< "No se han encontrado productos registrados" << endl;
            setColor(7);
    }
    else
    {
    setColor(2);
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
            setColor(2);
        cout << "Empleado guardado correctamente." << endl;
            setColor(7);
    }
    else
    {
            setColor(4);
        cout << "Error al registrar el Empleado." << endl;
            setColor(7);
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
    ArchivoVentas Ventas("ArchivoVentas.dat");
    Venta venta;
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




