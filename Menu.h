#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Persona.h"
#include "Cliente.h"
#include "Empleado.h"
class Menu{
public:
    void getMainMenu();
    void InterfazCrearUsuario();
    void listarEmpleados();
    void listarUsuarios();
    void listarVentas();
    void crearCliente();
};

#endif // MENU_H_INCLUDED
