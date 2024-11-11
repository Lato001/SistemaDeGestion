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
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Venta"<<endl;
        cout<<"2. Empleado"<<endl;
        cout<<"3. Cliente"<<endl;
        cout<<"4. Productos"<<endl;
        cout<<"5. Detalle de Venta"<<endl;
        cout<<"6. Informes"<<endl;
        cout<<"7. Exportar Archivos CSV "<<endl;
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
            mVentas();
            break;
        case 2:
            mEmpleados();
            break;
        case 3:
            registrar();
            break;
        case 4:
            modificarRegistroVenta();
            break;
        case 5:
            eliminar();
            break;
        case 6:
            infor.menuInformes();
            break;
        case 7:
            exportar.menuExportarCSV();
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
    Exportados exportar;
    Listados listar;
    Eliminados eliminar;
    int op=0;
    bool opcionValida=false;

    do
    {


        setColor(7);
        cout<<"-----------MENU EMPLEADO-----------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear"<<endl;
        cout<<"2. Listar"<<endl;
        cout<<"3. Modificar"<<endl;
        cout<<"4. Eliminar"<<endl;
        cout<<"5. Exportar"<<endl;
        cout<<"0. Salir"<<endl;
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
            listar.listarEmpleadosAll();
            break;
        case 3:
            {
            ArchivoEmpleados archivoEmpleados("ArchivoEmpleados.dat");
            Listados listados;
            int empleadoID;
            setColor(7);
            listados.listarEmpleadosAll();
            cout << "Ingrese el ID del empleado que desea modificar: ";
            setColor(0);
            cin >> empleadoID;
            archivoEmpleados.ModificarEmpleado(empleadoID);
            break;
            }
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
        system("pause");
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
            registrarVenta();
            break;
        case 2:
            listar.listarVentas();
            break;
        case 3:
            modificarRegistroVenta();
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

void Menu::listar()
{
    Listados listados;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Listar Ventas"<<endl;
        cout<<"2. Listar Productos"<<endl;
        cout<<"3. Listar Empleados"<<endl;
        cout<<"4. Listar Clientes"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);
        cin>>op;
        system("cls");
        if(op>0 && op<5)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:
            listados.listarVentas();
            break;
        case 2:
            listados.MenulistarProductos();
            break;
        case 3:
            listados.MenulistarEmpleados();
            break;
        case 4:
            listados.MenulistarClientes();
            break;
        case 0:
            getMainMenu();
        default:
            mensajeDeError("Opcion invalida!, vuelva a intentarlo");
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

              setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear Empleado"<<endl;
        cout<<"2. Crear Cliente"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
         setColor(0);
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

           mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

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
    setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Registrar Venta"<<endl;
        cout<<"2. Registrar Producto"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
            setColor(0);
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

            mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    registrar();
}
void Menu::modificar()
{
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Modificar Venta"<<endl;
        cout<<"2. Modificar Producto"<<endl;
        cout<<"3. Modificar Empleado"<<endl;
        cout<<"4. Modificar Cliente"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);

        cin>>op;
        system("cls");
        if(op>0 && op<6)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:

            modificarRegistroVenta();
            break;
        case 2:
         {
            ArchivoProductos archivoProductos("ArchivoProductos.dat");
            int productoID;
            setColor(7);
            Listados listados;
            listados.listarProductosAll();
            cout << "Ingrese el ID del producto que desea modificar: ";
            cin >> productoID;
            archivoProductos.ModificarProducto(productoID);
            break;
        }
        case 3:
        {
           ArchivoEmpleados archivoEmpleados("ArchivoEmpleados.dat");
            Listados listados;
            int empleadoID;
            setColor(7);
            listados.listarEmpleadosAll();
            cout << "Ingrese el ID del empleado que desea modificar: ";
            setColor(0);
            cin >> empleadoID;
            archivoEmpleados.ModificarEmpleado(empleadoID);
            break;
        }
        case 4:
        {

            ArchivoClientes archivoClientes("ArchivoClientes.dat");
            Listados listados;
            int clienteID;
            setColor(7);
            listados.listarClientesAll();
            cout << "Ingrese el ID del cliente que desea modificar: ";
            setColor(0);
            cin >> clienteID;
            archivoClientes.ModificarCliente(clienteID);
            break;
        }
        case 5:
         {
            ArchivoDetalleVentas archivoDetalleVentas("ArchivoDetalleVentas.dat");
            Listados listados;
            int idVenta;
            setColor(7);
            listados.listarVentas();
            cout << "Ingrese el ID de la venta que desea modificar: ";
            setColor(0);
            cin >> idVenta;
            archivoDetalleVentas.ModificarDetalleVenta(idVenta);
            break;
        }
        case 0:
            getMainMenu();
            break;
        default:
            setColor(4);
            mensajeDeError("Opcion invalida!, vuelva a intentarlo");
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    modificar();
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

void Menu::modificarRegistroVenta()
{
    Listados listados;
    int input;
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");
    Venta venta;
    bool opcionValida = false;
    listados.listarVentas();
    setColor(7);
    cout<< "Seleccione el ID de la venta a modificar: "<<endl;
    cout<<"0. Volver al menu principal"<<endl;
    setColor(0);
    cin >> input;
    system("cls");
    if (input !=0 )
    {
        if( Ventas.Buscar(input).getIdVenta() !=  -1)
        {
            while(!opcionValida)
            {
                venta = Ventas.Buscar(input);
                setColor(7);
                cout<<"Elija el atributo a modificar" << endl;
                cout<<"1. Fecha: ";
                venta.getFecha().mostrarFecha();
                cout<<"2. Empleado: " ;
                setColor(0);
                cout <<Empleados.Buscar(venta.getIdVenta()).getNombre()<< " " <<Empleados.Buscar(venta.getIdVenta()).getApellido() <<endl;
                setColor(7);
                cout<<"3. Cliente: " ;
                setColor(0);
                cout << Clientes.Buscar(venta.getIdVenta()).getNombre()<< " " <<Clientes.Buscar(venta.getIdVenta()).getApellido() <<endl;
                setColor(7);
                cout<< "4. Forma de Pago: ";
                setColor(0);
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
                setColor(7);
                cout<< "0. Volver al menu principal"<<endl<<endl;
                cout<< "Seleccione una opcion: ";
                setColor(0);
                cin >> input;
                opcionValida = (input> 0 && input< 5);
                if(!opcionValida)
                {
                    if(input != 0)
                    {

                        mensajeDeError("Opcion invalida");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        getMainMenu();
                    }
                }
            }
        }
        else
        {
            mensajeDeError("No existe venta con este ID, vuelva a intentarlo");
            modificar();
        }
        system("cls");
        setColor(7);
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
        getMainMenu();
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
