#include <iostream>
#include "rlutil.h"


using namespace std;

#include "Persona.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "Menu.h"

Cliente::Cliente() {
    clienteID = 0;
}

Cliente::Cliente(int _DNI, const char* _nombre, const char* _apellido, const char* _email, int _nTelefono, const char* _localidad, int _clienteID)
    : Persona(_DNI, _nombre, _apellido, _email, _nTelefono, _localidad) {
    clienteID = _clienteID;
}

int Cliente::getID() {
    return clienteID;
}

void Cliente::setClienteID(int _clienteID) {
    clienteID = _clienteID;
}

void Cliente::mostrarCliente() {
    cout << "      ID CLIENTE: " << getID()<< endl;
    Menu::setColor(7);
    mostrarPersona();
}

void Cliente::cargarCliente() {
    ArchivoClientes Clientes("ArchivoClientes.dat");

    Menu::setColor(7);
    cout << "Ingrese los datos del cliente:" << endl;

    cargarPersona();
    if(Clientes.CantidadRegistros() == 0){
        clienteID = 1;
    }else{
        clienteID = Clientes.Leer((Clientes.CantidadRegistros()-1)).getID() + 1;
    }

    Menu::setColor(2);
    cout << "Cliente cargado correctamente con ID: " << clienteID << endl;

    Menu::setColor(7);
}
