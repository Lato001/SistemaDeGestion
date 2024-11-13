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

using namespace std;


void Informes::menuInformes()
{
    Menu menu;
    int op=0;
    bool opcionValida=false;

    do
    {
        menu.setColor(7);
        cout<<"--------------INFORMES--------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Clientes MAS+ activos"<<endl;
        cout<<"2. Clientes MENOS- activos"<<endl;
        cout<<"3. Empleados con MAS+ ventas"<<endl;
        cout<<"4. Formas de pago MAS+ utilizadas"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"==================================="<<endl;
        menu.setColor(0);

        cin>>op;
        system("cls");
        if(op>0 && op<5)
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
            fdpMasUtilizadas();
            break;
        case 0:
            menu.getMainMenu();
            break;
        default:
            menu.mensajeDeError("Opcion invalida!, vuelva a intentarlo");
            menu.setColor(7);
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
    while(!opcionValida);
    menuInformes();
}
void Informes::clientesMasActivos()
{
    Menu menu;
    menu.setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");

    int numClientes = Clientes.CantidadRegistros();
    std::vector<int> comprasClientesArr(numClientes, 0);

    // Contar las compras por cliente
    for (int i = 0; i < Ventas.CantidadRegistros(); i++)
    {
        int idCliente = Ventas.Leer(i).getIdCliente();
        comprasClientesArr[Clientes.BuscarPosRegistro(idCliente)]++;
    }
    int topClientes[3] = {-1, -1, -1};
    int topCompras[3] = {0, 0, 0};

    for (int i = 0; i < numClientes; i++)
    {
        int cantidadCompras = comprasClientesArr[i];
        if (cantidadCompras > topCompras[0])
        {

            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];

            topClientes[1] = topClientes[0];
            topCompras[1] = topCompras[0];

            topClientes[0] = Clientes.Leer(i).getID();
            topCompras[0] = cantidadCompras;
        }
        else if (cantidadCompras > topCompras[1])
        {
            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];

            topClientes[1] = Clientes.Leer(i).getID();
            topCompras[1] = cantidadCompras;
        }
        else if (cantidadCompras > topCompras[2])
        {
            topClientes[2] = Clientes.Leer(i).getID();
            topCompras[2] = cantidadCompras;
        }
    }



    for (int i = 0; i < 3; i++)
    {
        if (topClientes[i] != -1)
        {
            Cliente cliente = Clientes.Buscar(topClientes[i]);
            cout << "\nEl";
            if(i == 0)
            {
                cout << " Primero";
            }
            else if(i == 1)
            {
                cout<< " Segundo:";
            }
            else
            {
                cout<< " Tercer";
            }
            cout<<" cliente con mas compras: " ;
            menu.setColor(0);
            cout << cliente.getNombre()<<" ";
            cout << cliente.getApellido();
            menu.setColor(7);
            cout << ", ID: " ;
            menu.setColor(0);
            cout << topClientes[i];
            menu.setColor(7);
            cout << ", con " ;
            menu.setColor(0);
            cout << topCompras[i] ;
            menu.setColor(7);
            cout << " compras." <<endl;
        }
    }

    if (topClientes[0] == -1)
    {
        cout << "No se encontraron registros de compradores." << std::endl;
    }
}

void Informes::clientesMenosActivos()
{
    Menu menu;
    menu.setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoClientes Clientes("ArchivoClientes.dat");

    int numClientes = Clientes.CantidadRegistros();
    std::vector<int> comprasClientesArr(numClientes, 0);


    for (int i = 0; i < Ventas.CantidadRegistros(); i++)
    {
        int idCliente = Ventas.Leer(i).getIdCliente();
        comprasClientesArr[Clientes.BuscarPosRegistro(idCliente)]++;
    }


    int topClientes[3] = {-1, -1, -1};
    // Cantidad de compras de esos tres clientes (inicializado al valor más alto)
    int topCompras[3] = {INT_MAX, INT_MAX, INT_MAX};


    for (int i = 0; i < numClientes; i++)
    {
        int cantidadCompras = comprasClientesArr[i];

        // Si el cliente tiene menos compras que el primero (el que tiene menos compras)
        if (cantidadCompras < topCompras[0])
        {

            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];

            topClientes[1] = topClientes[0];
            topCompras[1] = topCompras[0];


            topClientes[0] = Clientes.Leer(i).getID();
            topCompras[0] = cantidadCompras;
        }

        else if (cantidadCompras < topCompras[1])
        {

            topClientes[2] = topClientes[1];
            topCompras[2] = topCompras[1];


            topClientes[1] = Clientes.Leer(i).getID();
            topCompras[1] = cantidadCompras;
        }

        else if (cantidadCompras < topCompras[2])
        {
            topClientes[2] = Clientes.Leer(i).getID();
            topCompras[2] = cantidadCompras;
        }
    }


    for (int i = 0; i < 3; i++)
    {
        if (topClientes[i] != -1)
        {
            Cliente cliente = Clientes.Buscar(topClientes[i]);
            cout << "\nEl";
            if (i == 0)
            {
                cout << " Primer";
            }
            else if (i == 1)
            {
                cout << " Segundo";
            }
            else
            {
                cout << " Tercer";
            }
            cout << " cliente con menos compras: " ;
            menu.setColor(0);
            cout << cliente.getNombre() << " ";
            cout  << cliente.getApellido() ;
            menu.setColor(7);
            cout << ", ID: " ;
            menu.setColor(0);
            cout << topClientes[i];
            menu.setColor(7);
            cout  << ", con " ;
            menu.setColor(0);
            cout << topCompras[i] ;
            menu.setColor(7);
            cout << " compras." << endl;
        }
    }


    if (topClientes[0] == -1)
    {
        cout << "No se encontraron registros de compradores." << std::endl;
    }
}

void Informes::empleadosMayoresVentas()
{
    Menu menu;
    menu.setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");

    int numEmpleados = Empleados.CantidadRegistros();
    std::vector<int> ventasEmpleadosArr(numEmpleados, 0);

    // Contar las ventas por Empleado
    for (int i = 0; i < Ventas.CantidadRegistros(); i++)
    {
        int idEmpleado = Ventas.Leer(i).getIdEmpleado();
        ventasEmpleadosArr[Empleados.BuscarPosRegistro(idEmpleado)]++;
    }

    int topEmpleados[3] = {-1, -1, -1};
    int topVentas[3] = {0, 0, 0};


    for (int i = 0; i < numEmpleados; i++)
    {
        int cantidadVentas = ventasEmpleadosArr[i];
        if (cantidadVentas > topVentas[0])
        {

            topEmpleados[2] = topEmpleados[1];
            topVentas[2] = topVentas[1];

            topEmpleados[1] = topEmpleados[0];
            topVentas[1] = topVentas[0];

            topEmpleados[0] = Empleados.Leer(i).getID();
            topVentas[0] = cantidadVentas;
        }
        else if (cantidadVentas > topVentas[1])
        {

            topEmpleados[2] = topEmpleados[1];
            topVentas[2] = topVentas[1];


            topEmpleados[1] = Empleados.Leer(i).getID();
            topVentas[1] = cantidadVentas;
        }
        else if (cantidadVentas > topVentas[2])
        {

            topEmpleados[2] = Empleados.Leer(i).getID();
            topVentas[2] = cantidadVentas;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (topEmpleados[i] != -1)
        {
            Empleado empleado = Empleados.Buscar(topEmpleados[i]);
            cout << "\nEl";
            if (i == 0)
            {
                cout << " Primer";
            }
            else if (i == 1)
            {
                cout << " Segundo";
            }
            else
            {
                cout << " Tercer";
            }
            cout << " empleado con mas ventas: ";
            menu.setColor(0);
            cout  << empleado.getNombre() << " ";
            cout << empleado.getApellido() ;
            menu.setColor(7);
            cout << ", ID: " ;
            menu.setColor(0);
            cout << topEmpleados[i];
            menu.setColor(7);
            cout << ", con " ;
            menu.setColor(0);
            cout << topVentas[i];
            menu.setColor(7);
            cout  << " ventas." << endl;
        }
    }
    if (topEmpleados[0] == -1)
    {
        menu.mensajeDeError ( "No se encontraron registros de ventas." );
        cout << endl;
    }
}

void Informes::fdpMasUtilizadas()
{
    Menu menu;
    menu.setColor(7);
    ArchivoVentas Ventas("ArchivoVentas.dat");

    int numVentas = Ventas.CantidadRegistros();
    string topFormasDePago[3] = {"","",""};
    int fdpContadores[3] = {}; // Contadores de "Efectivo", "Debito", "Credito"
    int topContadores[3] = {};

    for (int i = 0; i < numVentas; i++)
    {
        int fdp = Ventas.Leer(i).getFormaDePago();
        if (fdp == 1)
        {
            fdpContadores[0]++;
        }
        else if (fdp == 2)
        {
            fdpContadores[1]++;
        }
        else if (fdp == 3)
        {
            fdpContadores[2]++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (fdpContadores[i] > topContadores[0])
        {

            topContadores[2] = topContadores[1];
            topFormasDePago[2] = topFormasDePago[1];

            topContadores[1] = topContadores[0];
            topFormasDePago[1] = topFormasDePago[0];

            topContadores[0] = fdpContadores[i];

            if (i == 0) topFormasDePago[0] = "Efectivo";
            else if (i == 1) topFormasDePago[0] = "Debito";
            else topFormasDePago[0] = "Credito";
        }
        else if (fdpContadores[i] > topContadores[1])
        {
            topContadores[2] = topContadores[1];
            topFormasDePago[2] = topFormasDePago[1];

            topContadores[1] = fdpContadores[i];
            if (i == 0) topFormasDePago[1] = "Efectivo";
            else if (i == 1) topFormasDePago[1] = "Debito";
            else topFormasDePago[1] = "Credito";
        }
        else if (fdpContadores[i] > topContadores[2])
        {
            topContadores[2] = fdpContadores[i];
            if (i == 0) topFormasDePago[2] = "Efectivo";
            else if (i == 1) topFormasDePago[2] = "Debito";
            else topFormasDePago[2] = "Credito";
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (topFormasDePago[i] != "")
        {
            cout << "\nLa";
            if (i == 0)
            {
                cout << " Primera";
            }
            else if (i == 1)
            {
                cout << " Segunda";
            }
            else
            {
                cout << " Tercera";
            }
            cout << " forma de pago mas utilizada es: " ;
            menu.setColor(0);
            cout << topFormasDePago[i];
            menu.setColor(7);
            cout    << ", fue utilizada (" ;
            menu.setColor(0);
            cout << topContadores[i] ;
            menu.setColor(7);
            cout << ") veces." << endl;
        }
    }

    if (topFormasDePago[0] == "")
    {
        menu.mensajeDeError( "No se encontraron registros de ventas.");
        cout << endl;
    }
}
