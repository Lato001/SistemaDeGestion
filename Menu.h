#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Cliente.h"
#include "Empleado.h"
class Menu{
public:
    ///FUNCIONES DE MANEJO DE MENU
    void getMainMenu();
    void listar();
    void crear();
    void registrar();

    ///LISTADOS DE CLASES
    void listarEmpleados();
    void listarClientes();
    void listarVentas();
    void listarProductos();

    ///FUNCIONES PARA CREACION DE OBJETOS
    void crearEmpleado();
    void crearCliente();

    ///REGISTRACIONES DE VENTAS Y NUEVOS PRODUCTOS
    void registrarVenta();
    void registrarProducto();

};

#endif // MENU_H_INCLUDED
