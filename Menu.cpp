#include <iostream>
#include <cstdio>

#include "Menu.h"
#include "Persona.h"
#include "ArchivoPersonas.h"
#include "Comprador.h"
#include "ArchivoCompradores.h"
#include "Empleado.h"
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
    ArchivoPersonas archivo("Personas.dat");
    Persona usuario;

    int ingresoNumeros;
    char ingresoDatos[50];
    cout<<"========= Crea tu usuario ========="<<endl;

    cout<<"Ingrese el DNI de su usuario <Unicamente numeros>"<<endl;
    cin >> ingresoNumeros;
    usuario.setDNI(ingresoNumeros);

    cout<<"Ingrese el nombre de su usuario"<<endl;
    cin.ignore(); // Para limpiar el buffer del cin
    cin.getline(ingresoDatos, 50);
    usuario.setNombre(ingresoDatos);

    cout<< "Ingrese el apellido de su usuario"<<endl;
    cin.getline(ingresoDatos, 50);
    usuario.setApellido(ingresoDatos);

    cout<< "Ingrese el email de su usuario"<<endl;
    cin.getline(ingresoDatos, 50);
    usuario.setEmail(ingresoDatos);

    cout<< "Ingrese la localidad de su usuario"<<endl;
    cin.getline(ingresoDatos, 50);
    usuario.setLocalidad(ingresoDatos);

    ///UTILIZO -1 PARA QUE SE GUARDE SIEMPRE EN EL ULTIMO REGISTRO Y NO SE CREEN NUEVOS
    archivo.Guardar(usuario,archivo.CantidadRegistros()-1);
}

void Menu::listarEmpleados()
{
    ArchivoPersonas Personas("Personas.dat");
    Persona registro;
    int cantRegistros = Personas.CantidadRegistros();
    cout<< "cantidad de registros: " << cantRegistros << endl;

    for (int i = 0; i < cantRegistros ;i++ ){
    registro = Personas.Leer(i);
    registro.mostrarPersona();

    }
}
void Menu::listarUsuarios(){
///    crearUsuarioComprador();
    ArchivoCompradores Compradores("Personas.dat");
    Comprador registro;
    int cantRegistros = Compradores.CantidadRegistros();
    cout<< "Cantidad de registros: " << cantRegistros << endl;

    for (int i = 0;i < cantRegistros;i++ ){
    registro = Compradores.Leer(i);
    registro.mostrarComprador();
}

    ///cout<< "Usuario: " << "ID usuario: " << " Compras realizadas: " << endl; /// ¿ Usuario o Comprador ? ¿ Lisar todos o mostrar 1 ?
    ///Comprador usuario;
    ///usuario.mostrarComprador();
}
void Menu::listarVentas()
{
    cout<<""<<endl;
}
/*
void Menu::crearUsuarioComprador()
{
    ArchivoCompradores archivo("Compradores.dat");
    Comprador usuario;

    int ingresoNumeros;

    cout<<"¿Cual es su ID de comprador? <Unicamente numeros>"<<endl;
    cin >> ingresoNumeros;
    usuario.setcompradorID(ingresoNumeros);

    ///UTILIZO -1 PARA QUE SE GUARDE SIEMPRE EN EL ULTIMO REGISTRO Y NO SE CREEN NUEVOS
    archivo.Guardar(usuario,archivo.CantidadRegistros()-1);
}
*/
