#include <iostream>
#include <cstdio>
#include <cstring>

#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "ArchivoDetalleVentas.h"
#include "Menu.h"
#include "Listados.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"
#include "Producto.h"
#include "rlutil.h"

using namespace std;

void Menu::getMainMenu()
{
    Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Listar"<<endl;
        cout<<"2. Crear (Empleado / Cliente)"<<endl;
        cout<<"3. Registrar (Ventas / Productos)"<<endl;
        cout<<"4. Modificar Registros"<<endl;
        cout<<"5. Eliminar Registros"<<endl;
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
            listar();
            break;
        case 2:
            crear();
            break;
        case 3:
            registrar();
            break;
        case 4:
            modificar();
            break;
        case 5:
            eliminar();
            break;
        case 0:
            exit(0);
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
void Menu::listar()
{
    Menu menu;
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
            menu.getMainMenu();
        default:
            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo");
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
    Menu menu;
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

           menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    crear();
}
void Menu::registrar()
{
    Menu menu;
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
        cin>>op;
            setColor(0);
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

            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo" );

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
        cout<<"5. Modificar Detalle de Venta"<<endl;
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
            {
            ArchivoVentas archivoVentas("ArchivoVentas.dat");
            int idVenta;
            setColor(7);
            cout << "Ingrese el ID de la venta que desea modificar: ";
            cin >> idVenta;
            archivoVentas.ModificarVenta(idVenta);
            break;
             }
            break;
        case 2:
            {
            ArchivoProductos archivoProductos("ArchivoProductos.dat");
            int productoID;
            setColor(7);
            cout << "Ingrese el ID del producto que desea modificar: ";
            cin >> productoID;
            archivoProductos.ModificarProducto(productoID);
            break;
             }
            break;
        case 3:
             {
           ArchivoEmpleados archivoEmpleados("ArchivoEmpleados.dat");
            int empleadoID;
            setColor(7);
            cout << "Ingrese el ID del empleado que desea modificar: ";
            cin >> empleadoID;
            archivoEmpleados.ModificarEmpleado(empleadoID);
            break;
             }
        case 4:
             {
            ArchivoClientes archivoClientes("ArchivoClientes.dat");
            int clienteID;
            setColor(7);
            cout << "Ingrese el ID del cliente que desea modificar: ";
            cin >> clienteID;
            archivoClientes.ModificarCliente(clienteID);
            break;
             }
        case 5:
            {
            ArchivoDetalleVentas archivoDetalleVentas("ArchivoDetalleVentas.dat");
            int idVenta;
            setColor(7);
            cout << "Ingrese el ID de la venta que desea modificar: ";
            cin >> idVenta;
            archivoDetalleVentas.ModificarDetalleVenta(idVenta);
            break;
             }
        case 0:
            getMainMenu();
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
    Menu menu;
    int op=0;
    bool opcionValida=false;

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
            menuEliminarEmpleados();
            break;
        case 2:
            menuEliminarClientes();
            break;
        case 3:
            menuEliminarVentas();
            break;
        case 4:
            menuEliminarProductos();
            break;
        case 0:
            getMainMenu();
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
void Menu::eliminarArchivoEmpleados()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleado empleado;

    Empleados.eliminarArchivoEmpleados();
    system("pause");
    system("cls");
    menuEliminarEmpleados();
}
void Menu::eliminarRegistroEmpleado()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleado empleado;

    int empleadoID;
    cout << "Ingrese el ID del empleado que desea eliminar: ";
    cin>>empleadoID;

    Empleados.eliminarRegistroEmpleado(empleadoID);
    system("pause");
    system("cls");
    menuEliminarEmpleados();
}

void Menu::menuEliminarEmpleados()
{
   Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Eliminar un registro"<<endl;
        cout<<"2. Eliminar archivo"<<endl;
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
            eliminarRegistroEmpleado();
            break;
        case 2:
            eliminarArchivoEmpleados();
            break;
        case 0:
            getMainMenu();
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

void Menu::menuEliminarClientes()
{
   Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Eliminar un registro"<<endl;
        cout<<"2. Eliminar archivo"<<endl;
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
            eliminarRegistroCliente();
            break;
        case 2:
            eliminarArchivoClientes();
            break;
        case 0:
            getMainMenu();
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
void Menu::eliminarArchivoClientes()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente cliente;

    Clientes.eliminarArchivoClientes();
    system("pause");
    system("cls");
    menuEliminarClientes();
}
void Menu::eliminarRegistroCliente()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente cliente;

    int clienteID;
    cout << "Ingrese el ID del cliente que desea eliminar: ";
    cin>>clienteID;

    Clientes.eliminarRegistroCliente(clienteID);
    system("pause");
    system("cls");
    menuEliminarClientes();
}
void Menu::menuEliminarVentas()
{

}
void Menu::menuEliminarProductos()
{
    Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Eliminar un registro"<<endl;
        cout<<"2. Eliminar archivo"<<endl;
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
            eliminarRegistroProducto();
            break;
        case 2:
            eliminarArchivoProductos();
            break;
        case 0:
            getMainMenu();
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

void Menu::eliminarRegistroProducto()
{
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto producto;

    int productoID;
    cout << "Ingrese el ID del producto que desea eliminar: ";
    cin>>productoID;

    Productos.eliminarRegistroProducto(productoID);
    system("pause");
    system("cls");

}

void Menu::eliminarArchivoProductos()
{
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto producto;

    Productos.eliminarArchivoProductos();
    system("pause");
    system("cls");
    menuEliminarProductos();
}

void Menu::modificarRegistroVenta()
{
    Menu menu;
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
    cout<< "Seleccione el ID de la venta a modificar: ";
    setColor(0);    cin >> input;

    if( Ventas.Buscar(input).getIdVenta() !=  -1)
    {
        while(!opcionValida)
        {
            venta = Ventas.Buscar(input);
    setColor(7);
            cout<<"Elija el atributo a modificar" << endl;
            cout<<"1. Fecha: ";
            venta.getFecha().mostrarFecha();
            cout<<"2. Empleado: " <<Empleados.Buscar(venta.getIdVenta()).getNombre()<< " " <<Empleados.Buscar(venta.getIdVenta()).getApellido() <<endl;
            cout<<"3. Cliente: " << Clientes.Buscar(venta.getIdVenta()).getNombre()<< " " <<Clientes.Buscar(venta.getIdVenta()).getApellido() <<endl;
            cout<< "4. Detalle de venta"<<endl;
            cout<< "0. Volver al menu principal"<<endl;
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

    switch (input)
    {
    case 1:{
        setColor(2);
        Fecha nuevaFecha;
        cout<<"Nueva fecha a cargar"<<endl;
        nuevaFecha.cargarFecha();
        nuevaFecha.mostrarFecha();
        system("pause");
        Ventas.Buscar(venta.getIdVenta()).setFecha(nuevaFecha);
        cout<< "Nueva fecha cargada: ";
        ///NUEVA FECHA CARGADA
        Ventas.Buscar(venta.getIdVenta()).getFecha().mostrarFecha();
        system("pause");
        system("cls");


    }
        break;
    case 2:
        {
            setColor(7);
        cout<<"Empleado que efectuo la venta"<<endl;
        listados.listarEmpleadosAll();
        cout<< "Seleccione el ID del empleado que efectuo la venta:";
            setColor(0);
        cin >> input;
        if(Empleados.Buscar(input).getID() != -1)
        {
            Ventas.Buscar(venta.getIdVenta()).setidEmpleado(input);
            setColor(7);
            cout<< "Nuevo Empleado : " <<Ventas.Buscar(venta.getIdVenta()).getIdEmpleado();
        }

        }
        break;
    default:
        break;
    }



}

void Menu::crearEmpleado()
{

    ArchivoEmpleados archivoEmpleados("ArchivoEmpleados.dat");


    Empleado empleado;
    Menu menu;
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

        menu.mensajeDeError("Error al registrar el Empleado." );

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
