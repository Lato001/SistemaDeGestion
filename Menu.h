#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Cliente.h"
#include "Empleado.h"
class Menu{
public:
    void getMainMenu();

    void listarEmpleados();
    void listarClientes();
    void listarVentas();
    void listarProductos();

    void registrarVenta();
    void crearCliente();
    void crearEmpleado();
    void registrarProducto();

};

#endif // MENU_H_INCLUDED
