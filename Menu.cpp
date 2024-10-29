#include <iostream>
#include <cstdio>

#include "Menu.h"
#include "Persona.h"
#include "ArchivoPersonas.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "Empleado.h"
#include "Venta.h"

using namespace std;

void Menu::getMainMenu()
{
    ArchivoClientes clientes("ArchivoClientes.dat");
    int op=0;
    bool opcionValida=false;
    bool boolExit=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear Nuevo Empleado"<<endl;
        cout<<"2. Crear Nuevo Cliente"<<endl;
        cout<<"3. Listar Empleados"<<endl;
        cout<<"4. Listar Clientes"<<endl;
        cout<<"5. Registrar Venta"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op> (-1) && op<6)
        {
            opcionValida=true;
        }

            switch (op)
            {
            case 2:
                crearCliente();
                break;
            case 3:
                listarEmpleados();
                break;
            case 4:
                listarClientes();
                break;
            case 5:
                registrarVenta();
                break;
            case 0:
                boolExit= true;
                break;
            default:
                cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
            }
            system("pause");
            system("cls");

        opcionValida = false;
    }while(boolExit==false || !opcionValida);
}

void Menu::listarEmpleados()
{
    ArchivoPersonas Personas("ArchivoEmpleados.dat");
    Persona registro;
    int cantRegistros = Personas.CantidadRegistros();
    cout<< "cantidad de registros: " << cantRegistros << endl;

    for (int i = 0; i < cantRegistros ;i++ ){
    registro = Personas.Leer(i);
    registro.mostrarPersona();

    }
}
void Menu::listarClientes(){
    ArchivoClientes Clientes("ArchivoClientes.dat");
    Cliente registro;
    int cantRegistros = Clientes.CantidadRegistros();
    if(cantRegistros == 0){
    cout<< "No se han encontrado clientes registrados" << endl;
    }else{

    cout<< "TOTAL DE CLIENTES: " << cantRegistros << endl;
    for (int i = 0;i < cantRegistros;i++ ){
    registro = Clientes.Leer(i);
    registro.mostrarCliente();
    cout<<endl;
    }
    }

}

void Menu::registrarVenta()
{
    Venta venta;
    venta.mostrarVenta();
}

void Menu::crearCliente()
{
    ArchivoClientes archivoClientes("ArchivoClientes.dat");

    int inputnumber;
    char ingresoDatos[50];

    Cliente cliente;
    cliente.cargarCliente();
    cliente.mostrarCliente();

/*GUARDA Y VERIFICA DE QUE EL CLIENTE HAYA SIDO REGISTRADO
EN LA ULTIMA POSICION DEL ARCHIVO DE CLIENTES
*/

    if ( archivoClientes.Guardar(cliente) )  {
        cout<<endl;
        cout << "Cliente guardado correctamente." << endl;
    }
    else {
        cout << "Error al guardar el cliente." << endl;
    }
}
