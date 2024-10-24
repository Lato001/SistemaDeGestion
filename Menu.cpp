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
    int op=0;
    bool opcionValida=false;
    bool boolExit=false;

    do
    {

        cout<<"----------------------------------"<<endl;
        cout<<"Elija la opcion que desee realizar"<<endl;
        cout<<"1. Crear nuevo empleado"<<endl;
        cout<<"2. Crear nuevo usuario"<<endl;
        cout<<"3. Listar empleados"<<endl;
        cout<<"4. Listar Usuarios"<<endl;
        cout<<"5. Listar Ventas"<<endl;
        cout<<"0. Salir"<<endl;
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
                crearCliente();
                break;
            case 3:
                listarEmpleados();
                break;
            case 4:
                listarUsuarios();
                break;
            case 5:
                listarVentas();
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

    cout<<"Ingrese su numero de telefono <Unicamente numeros>"<<endl;
    cin >> ingresoNumeros;
    usuario.setnTelefono(ingresoNumeros);

    cout<< "Ingrese la localidad de su usuario"<<endl;
    cin.ignore();
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
    ArchivoClientes Clientes("Personas.dat");
    Cliente registro;
    int cantRegistros = Clientes.CantidadRegistros();
    cout<< "Cantidad de registros: " << cantRegistros << endl;

    for (int i = 0;i < cantRegistros;i++ ){
    registro = Clientes.Leer(i);
    registro.mostrarCliente();
    }
}

void Menu::listarVentas()
{
    Venta nueva;
    nueva.mostrarVenta();
    cout << endl;
}

void Menu::crearCliente()
{
    ArchivoClientes archivo("Clientes.dat");
    int inputnumber;
    char ingresoDatos[50];
    Cliente homo1;

    cout<< " Nombre de Usario: "<<endl;
    cin.ignore(); // Para limpiar el buffer del cin
    cin.getline(ingresoDatos, 50);
    homo1.setNombre(ingresoDatos);

    cout<< " ID Usuario : "<<endl;
    cin>> inputnumber;
    homo1.setClienteID(inputnumber);

    ///UTILIZO -1 PARA QUE SE GUARDE SIEMPRE EN EL ULTIMO REGISTRO Y NO SE CREEN NUEVOS
    archivo.Guardar(homo1, archivo.CantidadRegistros()-1);

    if (!archivo.Guardar(homo1, archivo.CantidadRegistros() - 1))
    {
        cout << "Error al guardar el cliente." << endl;
    }
}

