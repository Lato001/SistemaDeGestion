#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Cliente.h"
#include "Empleado.h"
#include "rlutil.h"
using namespace std;
class Menu{
public:
    ///FUNCIONES DE MANEJO DE MENU
    void getMainMenu();
    void listar();
    void crear();
    void registrar();
    void modificar();
    void eliminar();

    ///LISTADOS DE CLASES
    void MenulistarEmpleados();

    void listarEmpleadosxName();
    void listarEmpleadosxOrdenAlfabetico();
    void listarEmpleadosxID();
    void listarEmpleadosxFecha();
    void listarEmpleadosxAsistencias();
    void listarEmpleadosxVacaciones();
    void listarEmpleadosAll();

    void MenulistarClientes();

    void listarClientesxName();
    void listarClientesxOrdenAlfabetico();
    void listarClientesxID();
    void listarClientesAll();

    void listarVentas();


    void listarProductos();

    ///FUNCIONES PARA CREACION DE OBJETOS
    void crearEmpleado();
    void crearCliente();

    ///REGISTRACIONES DE VENTAS Y NUEVOS PRODUCTOS
    void registrarVenta();
    void registrarProducto();

    ///MODIFICACIONES DE VENTAS
    void modificarRegistroVenta();

    //ELIMINAR REGISTROS
    void eliminarEmpleado();
    void eliminarCliente();
    void eliminarVenta();
    void eliminarProducto();

    ///FUNCIONES PARA INTERFAZ
    void mensajeDeError(string mensaje);
    static void setColor(int color);


};


#endif // MENU_H_INCLUDED
