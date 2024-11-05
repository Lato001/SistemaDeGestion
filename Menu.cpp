#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <conio.h>

#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "ArchivoDetalleVentas.h"
#include "Menu.h"
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
            listarVentas();
            break;
        case 2:
            MenulistarProductos();
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
        cout<<"3. Modificar Cliente"<<endl;
        cout<<"4. Modificar Empleado"<<endl;
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
            modificarRegistroVenta();
            break;
        case 2:
            registrarProducto();
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
            menuEliminarPrudctos();
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

    setColor(7);
    string nombre, aux;
    int localid;
    ifstream salida;
    salida.open("ArchivoEmpleados.dat", ios::in);
    ofstream entrada;
    entrada.open("temp.dat", ios::out);

    if (salida.fail())
    {
        cout << "Hubo un error al abrir el archivo ArchivoEmpleados.dat" << endl;
        cin.get();
        exit(0);
    }
    else
    {
        cout << "Introduzca el nombre: ";
        cin >> aux;

        while (salida >> nombre >> localid)
        {
            if (aux == nombre)
            {
                cout << "El registro ha sido eliminado." << endl;
            }
            else
            {
                entrada << nombre << " " << localid << endl;
            }
        }

        salida.close();
        entrada.close();

        remove("ArchivoEmpleados.dat");  // Eliminar el archivo original
        rename("temp.dat", "ArchivoEmpleados.dat");  // Renombrar el archivo temporal a "ArchivoEmpleados.dat"
    }

}
void Menu::eliminarRegistro()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleado empleado;
    Empleados.eliminarRegistroEmpleado();
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
            eliminarRegistro();
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

}void Menu::menuEliminarVentas()
{

}void Menu::menuEliminarPrudctos()
{

}
void Menu::modificarRegistroVenta()
{

    int input;
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");
    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");
    Venta venta;
    bool opcionValida = false;
    listarVentas();
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
        listarEmpleadosAll();
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
void Menu::MenulistarClientes()
{
    Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
    setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Por Nombre"<<endl;
        cout<<"2. Por Orden Alfabetico"<<endl;
        cout<<"3. Por ID"<<endl;
        cout<<"4. Listar todos"<<endl;
        cout<<"5. Listar Por Nro de Compras Realizadas"<<endl;
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
            getMainMenu();
        default:

            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo");

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
   setColor(7);
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
   setColor(0);
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

    Empleados.FiltrarEmpleados();
    system("pause");
system("cls");
MenulistarEmpleados();
}

void Menu::listarEmpleadosxOrdenAlfabetico()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    Empleados.FiltrarPorOrdenAlfabetico();
        system("pause");
        system("cls");
        MenulistarEmpleados();
}

void Menu::listarEmpleadosxName()
{
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
    setColor(7);
    cout<<"Ingrese el nombre del empleado a filtrar: ";
    setColor(0);
    string nombre;
    cin >> nombre;
    Empleados.FiltrarPorNombre(nombre);
    setColor(7);
    system("pause");
    system("cls");
    MenulistarEmpleados();
}
void Menu::listarEmpleadosxID()
{
ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
     setColor(7);
    cout<<"Ingrese el ID del empleado a filtrar: ";
     setColor(0);
    int id;
    cin >> id;
    Empleados.FiltrarPorID(id);
     setColor(7);
}

void Menu::listarEmpleadosxAsistencias(){
ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
Empleados.FiltrarPorAsistencias();
system("pause");
system("cls");
MenulistarEmpleados();


}
void Menu::listarEmpleadosxVacaciones()
{
    Menu menu;
ArchivoEmpleados Empleados("ArchivoEmpleados.dat");
int op = -1;
int m = -1;
bool opcionValida=false;

while (op!=0 || op !=1)
    {
            setColor(7);
    cout << "0.Filtrar Empleados de Vacaciones "<<endl;
    cout << "1.Filtrar Empleados Trabajando "<<endl;
    cout << "2.Volver al menu principal "<<endl;
     setColor(0);
    cin >> op;
    system ("cls");
    if(op!=0 || op !=1)
    {
        if (op==2)
        {
            system ("cls");
            setColor(7);
            getMainMenu();
        }
        else{
        Empleados.FiltrarPorVacacionesActivas(op);
        setColor(0);
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
    setColor(7);
    }
    MenulistarEmpleados();
}
void Menu::listarEmpleadosxFecha()
{
    ArchivoEmpleados Empleados ("ArchivoEmpleados.dat");
    Empleado registro;
    Empleados.FiltrarPorFecha();
    system ("pause");
    system ("cls");

    MenulistarEmpleados();
}
void Menu::listarClientesAll()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente registro;
    Clientes.FiltrarClientes();
    system("pause");
    system("cls");
    MenulistarClientes();

}
void Menu::listarClientesxName()
{

    ArchivoClientes Clientes ("ArchivoClientes.dat");
    setColor(7);
    cout<<"Ingrese el nombre del cliente a filtrar: ";
    setColor(0);
    string nombre;
    cin >> nombre;
    Clientes.FiltrarPorNombre(nombre);
    setColor(7);
    system("pause");
    system("cls");
    MenulistarClientes();
}

void Menu::listarClientesxOrdenAlfabetico()
{
Menu menu;
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Clientes.FiltrarPorOrdenAlfabetico();
        system("pause");
        system("cls");
        MenulistarClientes();
}
    void Menu::listarClientesxID()
{
    ArchivoClientes Clientes("ArchivoClientes.dat");
    setColor(7);
    cout<<"Ingrese el ID del Cliente a filtrar: ";
    setColor(0);
    int id;
    cin >> id;
    Clientes.FiltrarPorID(id);
    setColor(7);
}
void Menu::listarClientesxComprasRealizadas(){
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Clientes.FiltrarPorNComprasRealizadas();
    system("pause");
    system("cls");
}

void Menu::listarVentas()
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
void Menu::MenulistarProductos()
{
 Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Listar por Nombre"<<endl;
        cout<<"2. Listar por ID"<<endl;
        cout<<"3. Listar por Categoria"<<endl;
        cout<<"4. Listar Todos"<<endl;
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
            listarProductosxName();
            break;
        case 2:
            listarProductosxID();
            break;
        case 3:
            listarProductosxCategoria();
            break;
        case 4:
            listarProductosAll();
            break;
        case 0:
            getMainMenu();
        default:
            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo");
              setColor(7);
        }
        system("pause");
        system("cls");



    }
    while(!opcionValida);
    MenulistarProductos();
}

void Menu::listarProductosAll()
{
    Menu menu;
    ArchivoProductos Productos("ArchivoProductos.dat");
    Productos.FiltrarProductos();
    system("pause");
    system("cls");
}
void Menu::listarProductosxName()
{
    ArchivoProductos Productos ("ArchivoProductos.dat");
    setColor(7);
    cout<<"Ingrese el nombre del producto a filtrar: ";
    setColor(0);
    string nombre;
    cin >> nombre;
    Productos.FiltrarPorNombre(nombre);
    setColor(7);
    system("pause");
    system("cls");

}
void Menu::listarProductosxID()
{
    ArchivoProductos Productos("ArchivoProductos.dat");
    setColor(7);
    cout<<"Ingrese el ID del Producto a filtrar: ";
    setColor(0);
    int id;
    cin >> id;
    Productos.FiltrarPorID(id);
    setColor(7);
}
void Menu::listarProductosxCategoria()
{
    ArchivoProductos Productos("ArchivoProductos.dat");
    setColor(7);
    cout<<"Ingrese la categoria del Producto a filtrar: ";
    setColor(0);
    string categoria;
    cin >> categoria;
    Productos.FiltrarPorCategoria(categoria);
    setColor(7);
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





