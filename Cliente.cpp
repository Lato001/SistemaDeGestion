#include <iostream>

using namespace std;
#include "Persona.h"
#include "Comprador.h"

Cliente::Cliente()
{
    clienteID = 0;
//    nComprasRealizadas = 0;
}
Cliente::Cliente(int _clienteID /*int _nComprasRealizadas*/)
{
    clienteID = _clienteID;
//    nComprasRealizadas = _nComprasRealizadas;
}

int Cliente::getID(){return clienteID;}
//int Cliente::getComprasRealizadas(){return nComprasRealizadas;}

void Comprador::setclienteID(int _clienteID)
{
clienteID = _clienteID;
}
/* void Cliente::setnComprasRealizadas(int _nComprasRealizadas)
{
nComprasRealizadas = _nComprasRealizadas;
} */
Cliente actual;
void Cliente::mostrarCliente()
{
    cout<< "Usuario: "<< cliente.getNombre() << "  ID usuario: "<< actual.getID() <</* "  Compras realizadas: "<< actual.getComprasRealizadas() <<*/ endl;
}
