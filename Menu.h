#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Cliente.h"
#include "Empleado.h"
using namespace std;
class Menu{
public:
    ///FUNCIONES DE MANEJO DE MENU
    void getMainMenu();
    void listar();
    void crear();
    void registrar();

    ///LISTADOS DE CLASES
    void MenulistarEmpleados();

    void listarEmpleadosxName();
    void listarEmpleadosxOrdenAlfabetico();
    void listarEmpleadosxID();
    void listarEmpleadosxFecha();
    void listarEmpleadosAll();

    void MenulistarClientes();

    void listarClientesxName();
    void listarClientesxOrdenAlfabetico();
    void listarClientesxID();
    void listarClientesxFecha();
    void listarClientesAll();

    void listarVentas();


    void listarProductos();

    ///FUNCIONES PARA CREACION DE OBJETOS
    void crearEmpleado();
    void crearCliente();

    ///REGISTRACIONES DE VENTAS Y NUEVOS PRODUCTOS
    void registrarVenta();
    void registrarProducto();


    ///FUNCIONES PARA INTERFAZ
    void mensajeDeError(string mensaje);

};

#endif // MENU_H_INCLUDED
