#include <iostream>

using namespace std;
#include "Persona.h"
#include "Cliente.h"

Cliente::Cliente()
{
    clienteID = 0;
}
Cliente::Cliente(int _clienteID )
{
    clienteID = _clienteID;
}

int Cliente::getID(){return clienteID;}

void Cliente::setclienteID(int _clienteID)
{
clienteID = _clienteID;
}
void Cliente::mostrarCliente()
{
    Cliente actual;
    cout<< "Usuario: "<< cliente.getNombre() << "  ID usuario: "<< actual.getID() << endl;
}
