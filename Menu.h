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

    ///FUNCIONES PARA CREACION DE OBJETOS
    void crearEmpleado();
    void crearCliente();

    ///REGISTRACIONES DE VENTAS Y NUEVOS PRODUCTOS
    void registrarVenta();
    void registrarProducto();

    ///MODIFICACIONES DE VENTAS
    void modificarRegistroVenta();

    ///INFORMES
    void menuInformes();
    void clientesMasActivos();
    void clientesMenosActivos();
    void empleadosMayoresVentas();
    void empleadosMayoresAsistencias();
    void fdpMasUtilizadas();
    //EXPORTAR .toCSV

    void menuExportarCSV();
    void Exportar();

    ///FUNCIONES PARA INTERFAZ
    void mensajeDeError(string mensaje);
    static void setColor(int color);
};


#endif // MENU_H_INCLUDED
