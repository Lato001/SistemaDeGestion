#include <iostream>
#include "rlutil.h"

using namespace std;

#include "Persona.h"
#include "Cliente.h"
#include "ArchivoClientes.h"

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
    rlutil::setColor(rlutil::CYAN);
    cout << "////////////////// ID CLIENTE: " << getID() << " //////////////////" << endl;
    rlutil::setColor(rlutil::WHITE);
    mostrarPersona();
}

void Cliente::cargarCliente() {
    ArchivoClientes Clientes("ArchivoClientes.dat");

    rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese los datos del cliente:" << endl;

    cargarPersona();
    clienteID = (Clientes.CantidadRegistros() + 1);

    rlutil::setColor(rlutil::GREEN);
    cout << "Cliente cargado correctamente con ID: " << clienteID << endl;

    rlutil::setColor(rlutil::WHITE);
}
