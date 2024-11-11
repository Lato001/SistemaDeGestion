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

//    -----------------------------------

    void mVentas();
    void mEmpleados();
    void mProductos();

    //HOOOOOOOOOOOOO
    void modificarEmpleado();
    void modificarRegistroProducto();

    ///FUNCIONES PARA CREACION DE OBJETOS
    void crearEmpleado();
    void crearCliente();
    void registrarProducto();

    ///REGISTRACIONES DE VENTAS Y NUEVOS PRODUCTOS
    void registrarVenta();

    ///MODIFICACIONES DE VENTAS
    void modificarRegistroVenta();


    ///FUNCIONES PARA INTERFAZ
    void mensajeDeError(string mensaje);
    static void setColor(int color);
};


#endif // MENU_H_INCLUDED
