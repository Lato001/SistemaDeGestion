#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "persona.h"

class Cliente : public Persona {
private:
    int clienteID;
public:
    Cliente();
    Cliente(int, const char*, const char*, const char*, int, const char*, int _clienteID); //Constructor de la clase Cliente

    int getID();
    void setClienteID (int _clienteID);
    Persona getPersona();

  //  void crearCliente(); Crear MenuCliente y luego llamar desde Menu.cpp a crearCliente que estará en MenuCliente
    void cargarCliente();
    void mostrarCliente();
};

#endif // CLIENTE_H_INCLUDED
