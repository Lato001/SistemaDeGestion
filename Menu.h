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
    void listarClientes();
    void registrarVenta();
    void crearCliente();
    void crearEmpleado();
};

#endif // MENU_H_INCLUDED
