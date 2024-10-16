#include <iostream>

using namespace std;
#include "Persona.h"
#include "Comprador.h"

Comprador::Comprador()
{
    compradorID = 0;
    nComprasRealizadas = 0;
}
Comprador::Comprador(int _compradorID, int _nComprasRealizadas)
{
    compradorID = _compradorID;
    nComprasRealizadas = _nComprasRealizadas;
}

int Comprador::getID(){return compradorID;}
int Comprador::getComprasRealizadas(){return nComprasRealizadas;}

///void Comprador::setcompradorID(_compradorID);
///void Comprador::setnComprasRealizadas(_nComprasRealizadas);

Comprador actual;
void Comprador::mostrarComprador()
{
    cout<< "Usuario: "<< comprador.getNombre() << "ID usuario: "<< actual.getID() << " Compras realizadas: "<< actual.getComprasRealizadas() << endl;
}
