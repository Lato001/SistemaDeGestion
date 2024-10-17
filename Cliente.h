#ifndef COMPRADOR_H_INCLUDED
#define COMPRADOR_H_INCLUDED
#include "persona.h"

class Cliente {
private:
    Persona cliente;
    int clienteID;
//    int nComprasRealizadas;
public:
    Comprador();
    Comprador(int _compradorID/* int _nComprasRealizadas*/);

    int getID();
//    int getComprasRealizadas();

    void setclienteID (int _clienteID);
//    void setnComprasRealizadas (int _nComprasRealizadas);
    void crearUsuarioComprador();
    void mostrarComprador();
};

#endif // COMPRADOR_H_INCLUDED
