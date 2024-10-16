#ifndef COMPRADOR_H_INCLUDED
#define COMPRADOR_H_INCLUDED
#include "persona.h"
class Comprador {
private:
    Persona comprador;
    int compradorID;
    int nComprasRealizadas;
public:
    Comprador();
    Comprador(int _compradorID, int _nComprasRealizadas);

    int getID();
    int getComprasRealizadas();

    void setcompradorID (int _compradorID);
    void setnComprasRealizadas (int _nComprasRealizadas);
    void crearUsuarioComprador();
    void mostrarComprador();
};

#endif // COMPRADOR_H_INCLUDED
