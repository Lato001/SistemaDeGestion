#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "persona.h"

class Cliente {
private:
    Persona cliente;
    int clienteID;
//    int nComprasRealizadas;
public:
    Cliente();
    Cliente(int _compradorID/* int _nComprasRealizadas*/);

    int getID();
//    int getComprasRealizadas();

    void setclienteID (int _clienteID);
//    void setnComprasRealizadas (int _nComprasRealizadas);
    void crearCliente();
    void mostrarCliente();
};

#endif // CLIENTE_H_INCLUDED
