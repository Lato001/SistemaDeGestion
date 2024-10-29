#include <iostream>

using namespace std;
#include "Persona.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
Cliente::Cliente()
{
    cliente;
    clienteID = 0;
}
Cliente::Cliente(int _DNI, const char* _nombre,const char* _apellido,const char* _email, int _nTelefono, const char* _localidad, int _clienteID) : Persona(_DNI, _nombre, _apellido, _email, _nTelefono, _localidad)
{
    clienteID = _clienteID;
}
int Cliente::getID(){return clienteID;}
Persona Cliente::getPersona(){return cliente;}

void Cliente::setClienteID(int _clienteID)
{
clienteID = _clienteID;
}

void Cliente::mostrarCliente()
{
    cout<<"ID usuario: "<< clienteID << " ";
    cliente.mostrarPersona();
}

void Cliente::cargarCliente(){
    ArchivoClientes Clientes("ArchivoClientes.dat");

    cliente.cargarPersona();

    clienteID = (Clientes.CantidadRegistros()+1);

}
