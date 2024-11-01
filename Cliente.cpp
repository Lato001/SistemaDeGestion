#include <iostream>
#include "rlutil.h"  // Incluimos rlutil.h

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
    rlutil::setColor(rlutil::CYAN); // Establece el color cyan para mostrar el ID del cliente
    cout << "////////////////// ID CLIENTE: " << getID() << " //////////////////" << endl;
    rlutil::setColor(rlutil::WHITE); // Establece el color blanco para mostrar la información
    mostrarPersona();
}

void Cliente::cargarCliente() {
    ArchivoClientes Clientes("ArchivoClientes.dat");

    rlutil::setColor(rlutil::BLACK); // Establece el color negro para la entrada de datos
    cout << "Ingrese los datos del cliente:" << endl;

    cargarPersona();
    clienteID = (Clientes.CantidadRegistros() + 1);

    rlutil::setColor(rlutil::GREEN); // Establece el color verde para el mensaje de éxito
    cout << "Cliente cargado correctamente con ID: " << clienteID << endl;

    rlutil::setColor(rlutil::WHITE); // Restablece el color a blanco
}
