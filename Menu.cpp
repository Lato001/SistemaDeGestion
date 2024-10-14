#include <iostream>
#include <cstdio>

#include "Menu.h"
#include "Persona.h"
using namespace std;

void Menu::getMainMenu()
{
    int op=0;
    bool opcionValida=false;
    bool boolExit=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear nuevo usuario"<<endl;
        cout<<"2. Listar empleados"<<endl;
        cout<<"3. Listar Usuarios"<<endl;
        cout<<"0. Salir"<<endl;
        //cout<<"3. Crear Nuevo Usuario"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        if(op> (-1) && op<3)
        {
            opcionValida=true;
        }

            switch (op)
            {
            case 1:
                InterfazCrearUsuario();
                break;
            case 2:
                listarEmpleados();
                break;
            case 3:
                listarUsuarios();
                break;
            case 0:
                boolExit= true;
                break;
            default:
                cout<<"Opcion invalida!, vuelva a intentarlo" << endl;
            }
            system("pause");
            system("cls");


    }
    while(boolExit==false || !opcionValida);
}




void Menu::InterfazCrearUsuario()
{
    Persona usuario;
    int ingresoNumeros;
    char ingresoDatos[30];
    string inputDatos;
    cout<<"========= Crea tu usuario ========="<<endl;

    cout<<"Ingrese el DNI de su usuario <Unicamente numeros>"<<endl;
    cin >> ingresoNumeros;
    usuario.setDNI(ingresoNumeros);

    cout<<"Ingrese el nombre de su usuario"<<endl;
    cin.ignore(); // Para limpiar el buffer del cin
    cin.getline(ingresoDatos, 30);
    usuario.setNombre(ingresoDatos);

    cout<< "Ingrese el apellido de su usuario"<<endl;
    cin.ignore(); // Para limpiar el buffer del cin
    cin.getline(ingresoDatos, 30);
    usuario.setApellido(ingresoDatos);

    cout<< "Ingrese el email de su usuario"<<endl;
    cin >> inputDatos;
    usuario.setEmail(inputDatos);

    cout<< "Ingrese la localidad de su usuario"<<endl;
    cin.ignore(); // Para limpiar el buffer del cin
    cin.getline(ingresoDatos, 30);
    usuario.setLocalidad(ingresoDatos);

    usuario.mostrarPersona();
}

void Menu::listarEmpleados()
{
    cout<<"Empleado: " << "ID empleado: " << "Ventas concretadas: " <<endl;
}
void Menu::listarUsuarios(){
    cout<< "Usuario: " << "ID usuario: " << " Compras realizadas: " << endl;
}
void Menu::listarVentas()
{
    cout<<""<<endl;
}




