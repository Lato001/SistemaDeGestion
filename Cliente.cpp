#include <iostream>

using namespace std;
#include "Persona.h"
#include "Cliente.h"
Cliente::Cliente()
{
    clienteID = 0;
}
Cliente::Cliente(int _DNI, const char* _nombre,const char* _apellido,const char* _email, int _nTelefono, const char* _localidad, int _clienteID) : Persona(_DNI, _nombre, _apellido, _email, _nTelefono, _localidad)
{
    clienteID = _clienteID;
}
int Cliente::getID(){return clienteID;}

void Cliente::setClienteID(int _clienteID)
{
clienteID = _clienteID;
}
void Cliente::mostrarCliente()
{
    mostrarPersona();
    cout<< "Usuario: "<< getNombre() << "  ID usuario: "<< clienteID << endl;
}
