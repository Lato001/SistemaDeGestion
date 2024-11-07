#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "ArchivoDetalleVentas.h"

#include "Menu.h"
#include "Listados.h"
#include "Eliminados.h"

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
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Listar"<<endl;
        cout<<"2. Crear (Empleado / Cliente)"<<endl;
        cout<<"3. Registrar (Ventas / Productos)"<<endl;
        cout<<"4. Modificar Registros"<<endl;
        cout<<"5. Eliminar Registros"<<endl;
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
        case 6:
            menuInformes();
            break;
        case 7:
            menuExportarCSV();
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
void Menu::menuExportarCSV()
{
    int op=0;
    bool opcionValida=false;

    do
    {
    setColor(7);
    cout<<"----------------------------------"<<endl;
    cout<<"Elija la opcion que desee realizar"<<endl;
    cout<<"1. Exportar"<<endl;
    cout<<"2. Algo mas? @Marcos "<<endl;
    cout<<"0. Volver al menu principal"<<endl;
    cout<<"==================================="<<endl;
    setColor(0);
           cin>>op;
        system("cls");
        if(op> (0) && op<3)
        {
            opcionValida=true;
        }

        switch (op)
        {
        case 1:
            Exportar();
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
void Menu::Exportar()
{

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
            modificarRegistroVenta();
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
            setColor(0);
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
            setColor(0);
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
            setColor(0);
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
    Eliminados eliminados;
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
    cout<< "Seleccione el ID de la venta a modificar: ";
    setColor(0);
    cin >> input;

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
    case 1:
    {
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

// INFORMES

void Menu::menuInformes(){

Listados listados;
    int op=0;
    bool opcionValida=false;

    do
    {
        setColor(7);
        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Clientes MAS+ activos"<<endl;
        cout<<"2. Clientes MENOS- activos"<<endl;
        cout<<"3. Empleados con MAS+ ventas"<<endl;
        cout<<"4. Empleados con Mejores Asistencias (FALTA TERMINAR)"<<endl;
        cout<<"5. Formas de pago MAS+ utilizadas"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        setColor(0);

        cin>>op;
        system("cls");
        if(op>0 && op<2)
        {
            opcionValida=true;
        }
        switch (op)
        {
        case 1:
            clientesMasActivos();
            break;
        case 2:
            clientesMenosActivos();
            break;
        case 3:
            empleadosMayoresVentas();
            break;
        case 4:
            break;
        case 5:
            fdpMasUtilizadas();
            break;
        case 0:
            getMainMenu();
            break;
        default:
            mensajeDeError("Opcion invalida!, vuelva a intentarlo");
            setColor(7);
        }

    cout<<endl;
    system("pause");
    system("cls");
    }while(!opcionValida);
    menuInformes();
}
void Menu::clientesMasActivos() {
    setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");

    int numClientes = Clientes.CantidadRegistros();
    std::vector<int> comprasClientesArr(numClientes, 0);

    // Contar las compras por cliente
    for (int i = 0; i < Ventas.CantidadRegistros(); i++) {
        int idCliente = Ventas.Leer(i).getIdCliente();
        comprasClientesArr[Clientes.BuscarPosRegistro(idCliente)]++;
    }
    int topClientes[3] = {-1, -1, -1};
    int topCompras[3] = {0, 0, 0};

    for (int i = 0; i < numClientes; i++) {
        int cantidadCompras = comprasClientesArr[i];
        if (cantidadCompras > topCompras[0]) {

            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];

            topClientes[1] = topClientes[0];
            topCompras[1] = topCompras[0];

            topClientes[0] = Clientes.Leer(i).getID();
            topCompras[0] = cantidadCompras;
        }else if (cantidadCompras > topCompras[1]) {
            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];

            topClientes[1] = Clientes.Leer(i).getID();
            topCompras[1] = cantidadCompras;
        }else if (cantidadCompras > topCompras[2]) {
            topClientes[2] = Clientes.Leer(i).getID();
            topCompras[2] = cantidadCompras;
        }
    }



    for (int i = 0; i < 3; i++) {
        if (topClientes[i] != -1) {
            Cliente cliente = Clientes.Buscar(topClientes[i]);
            cout << "\nEl";
            if(i == 0){
                cout << " Primero";
            }else if(i == 1){
                cout<< " Segundo:";
            }else{
                cout<< " Tercer";
            }
            cout<<" cliente con mas compras: " << cliente.getNombre()<<" "<<
            cliente.getApellido()<< ", ID: " << topClientes[i]
                      << ", con " << topCompras[i] << " compras." <<endl;
        }
    }

    if (topClientes[0] == -1) {
        cout << "No se encontraron registros de compradores." << std::endl;
    }
}

void Menu::clientesMenosActivos() {
    setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");

    int numClientes = Clientes.CantidadRegistros();
    std::vector<int> comprasClientesArr(numClientes, 0);


    for (int i = 0; i < Ventas.CantidadRegistros(); i++) {
        int idCliente = Ventas.Leer(i).getIdCliente();
        comprasClientesArr[Clientes.BuscarPosRegistro(idCliente)]++;
    }


    int topClientes[3] = {-1, -1, -1};
    // Cantidad de compras de esos tres clientes (inicializado al valor m�s alto)
    int topCompras[3] = {INT_MAX, INT_MAX, INT_MAX};


    for (int i = 0; i < numClientes; i++) {
        int cantidadCompras = comprasClientesArr[i];

    // Si el cliente tiene menos compras que el primero (el que tiene menos compras)
        if (cantidadCompras < topCompras[0]) {

            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];

            topClientes[1] = topClientes[0];
            topCompras[1] = topCompras[0];


            topClientes[0] = Clientes.Leer(i).getID();
            topCompras[0] = cantidadCompras;
        }

        else if (cantidadCompras < topCompras[1]) {

            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];


            topClientes[1] = Clientes.Leer(i).getID();
            topCompras[1] = cantidadCompras;
        }

        else if (cantidadCompras < topCompras[2]) {
            topClientes[2] = Clientes.Leer(i).getID();
            topCompras[2] = cantidadCompras;
        }
    }


    for (int i = 0; i < 3; i++) {
        if (topClientes[i] != -1) {
            Cliente cliente = Clientes.Buscar(topClientes[i]);
            cout << "\nEl";
            if (i == 0) {
                cout << " Primero";
            } else if (i == 1) {
                cout << " Segundo";
            } else {
                cout << " Tercer";
            }
            cout << " cliente con menos compras: " << cliente.getNombre() << " "
                 << cliente.getApellido() << ", ID: " << topClientes[i]
                 << ", con " << topCompras[i] << " compras." << endl;
        }
    }


    if (topClientes[0] == -1) {
        cout << "No se encontraron registros de compradores." << std::endl;
    }
}

void Menu::empleadosMayoresVentas() {
    setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");

    int numEmpleados = Empleados.CantidadRegistros();
    std::vector<int> ventasEmpleadosArr(numEmpleados, 0);

    // Contar las ventas por Empleado
    for (int i = 0; i < Ventas.CantidadRegistros(); i++) {
        int idEmpleado = Ventas.Leer(i).getIdEmpleado();
        ventasEmpleadosArr[Empleados.BuscarPosRegistro(idEmpleado)]++;
    }

    int topEmpleados[3] = {-1, -1, -1};
    int topVentas[3] = {0, 0, 0};


    for (int i = 0; i < numEmpleados; i++) {
        int cantidadVentas = ventasEmpleadosArr[i];
        if (cantidadVentas > topVentas[0]) {

            topEmpleados[2] = topEmpleados[1];
            topVentas[2] = topVentas[1];

            topEmpleados[1] = topEmpleados[0];
            topVentas[1] = topVentas[0];

            topEmpleados[0] = Empleados.Leer(i).getID();
            topVentas[0] = cantidadVentas;
        }
        else if (cantidadVentas > topVentas[1]) {

            topEmpleados[2] = topEmpleados[1];
            topVentas[2] = topVentas[1];


            topEmpleados[1] = Empleados.Leer(i).getID();
            topVentas[1] = cantidadVentas;
        }
        else if (cantidadVentas > topVentas[2]) {

            topEmpleados[2] = Empleados.Leer(i).getID();
            topVentas[2] = cantidadVentas;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (topEmpleados[i] != -1) {
            Empleado empleado = Empleados.Buscar(topEmpleados[i]);
            cout << "\nEl";
            if (i == 0) {
                cout << " Primer";
            } else if (i == 1) {
                cout << " Segundo";
            } else {
                cout << " Tercer";
            }
            cout << " empleado con mas ventas: " << empleado.getNombre() << " "
                 << empleado.getApellido() << ", ID: " << topEmpleados[i]
                 << ", con " << topVentas[i] << " ventas." << endl;
        }
    }
    if (topEmpleados[0] == -1) {
        cout << "No se encontraron registros de ventas." << std::endl;
    }
}

void Menu::empleadosMayoresAsistencias(){


}

void Menu::fdpMasUtilizadas() {
    setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");

    int numVentas = Ventas.CantidadRegistros();
    string topFormasDePago[3] = {"","",""};
    int fdpContadores[3] = {}; // Contadores de "Efectivo", "Debito", "Credito"
    int topContadores[3] = {};

    for (int i = 0; i < numVentas; i++) {
        int fdp = Ventas.Leer(i).getFormaDePago();
        if (fdp == 1) {
            fdpContadores[0]++;
        } else if (fdp == 2) {
            fdpContadores[1]++;
        } else if (fdp == 3) {
            fdpContadores[2]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (fdpContadores[i] > topContadores[0]){

            topContadores[2] = topContadores[1];
            topFormasDePago[2] = topFormasDePago[1];

            topContadores[1] = topContadores[0];
            topFormasDePago[1] = topFormasDePago[0];

            topContadores[0] = fdpContadores[i];

            if (i == 0) topFormasDePago[0] = "Efectivo";
            else if (i == 1) topFormasDePago[0] = "Debito";
            else topFormasDePago[0] = "Credito";
        }
        else if (fdpContadores[i] > topContadores[1]) {
            topContadores[2] = topContadores[1];
            topFormasDePago[2] = topFormasDePago[1];

            topContadores[1] = fdpContadores[i];
            if (i == 0) topFormasDePago[1] = "Efectivo";
            else if (i == 1) topFormasDePago[1] = "Debito";
            else topFormasDePago[1] = "Credito";
        }
        else if (fdpContadores[i] > topContadores[2]) {
            topContadores[2] = fdpContadores[i];
            if (i == 0) topFormasDePago[2] = "Efectivo";
            else if (i == 1) topFormasDePago[2] = "Debito";
            else topFormasDePago[2] = "Credito";
        }
    }

    for (int i = 0; i < 3; i++) {
        if (topFormasDePago[i] != "") {
            cout << "\nLa";
            if (i == 0) {
                cout << " Primera";
            } else if (i == 1) {
                cout << " Segunda";
            } else {
                cout << " Tercera";
            }
            cout << " forma de pago mas utilizada es: " << topFormasDePago[i]
                 << ", fue utilizada (" << topContadores[i] << ") veces." << endl;
        }
    }

    if (topFormasDePago[0] == "") {
        cout << "No se encontraron registros de ventas." << std::endl;
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
