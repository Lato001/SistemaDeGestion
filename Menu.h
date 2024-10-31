#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Cliente.h"
#include "Empleado.h"
class Menu{
public:
    void getMainMenu();
    void InterfazCrearUsuario();
    void listarEmpleados();
    void listarClientes();
    void listarVentas();
    void registrarVenta();
    void crearCliente();
    void crearEmpleado();
    void crearProducto();
};

#endif // MENU_H_INCLUDED
