#include <iostream>

#include "Menu.h"
#include "Persona.h"
using namespace std;


void Menu::getMainMenu(){
        int op=0;
        bool opcionValida, exit = false;

        do{

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear nuevo usuario"<<endl;
        cout<<"2. Listar Personas"<<endl;
        cout<<"0. Salir"<<endl;
        //cout<<"3. Crear Nuevo Usuario"<<endl;
        cout<<"==================================="<<endl;
        cin>>op;
        system("cls");
        opcionValida = (op == 1);
        if(!opcionValida){
            cout<<"Opcion invalida! Vuelva a intentarlo"<<endl;
            system("pause");
            system("cls");
        }else{
            EjecutarFuncion(op,exit);
        }
        }while(!exit);
}

void Menu::EjecutarFuncion(int opcionElegida, bool &boolExit){
    switch (opcionElegida)
    {
    case 1 :
        InterfazCrearUsuario();
        system("pause");
        system("cls");
        break;
    case 0:
        boolExit = true;
        break;
    default:
        break;
    }

}


void Menu::listarVentas(){cout<<""<<endl;}

void Menu::listarEmpleados(){cout<<""<<endl;}

void Menu::InterfazCrearUsuario(){
    Persona usuario;
    int ingresoNumeros;

    string inputDatos;
    cout<<"========= Crea tu usuario ========="<<endl;

    cout<<"Ingrese el DNI de su usuario <Unicamente numeros>"<<endl;
    cin >> ingresoNumeros;
    usuario.setDNI(ingresoNumeros);

    cout<<"Ingrese el nombre de su usuario"<<endl;
    cin >> inputDatos;
    usuario.setNombre(inputDatos);

    cout<< "Ingrese el apellido de su usuario"<<endl;
    cin >> inputDatos;
    usuario.setApellido(inputDatos);

    cout<< "Ingrese el email de su usuario"<<endl;
    cin >> inputDatos;
    usuario.setEmail(inputDatos);

    cout<< "Ingrese la localidad de su usuario"<<endl;
    cin >> inputDatos;
    usuario.setLocalidad(inputDatos);
    usuario.mostrarPersona();


}

