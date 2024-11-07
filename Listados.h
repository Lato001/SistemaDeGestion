#ifndef LISTADOS_H_INCLUDED
#define LISTADOS_H_INCLUDED

class Listados {
public:
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
    void listarClientesxComprasRealizadas();
    void listarClientesAll();

    void listarVentas();

    void MenulistarProductos();
    void MenuListarProductosDetalleVentas();

    void listarProductosxName();
    void listarProductosxID();
    void listarProductosxCategoria();
    void listarProductosAll();
    void listarProductosDisponibles();
};

#endif // LISTADOS_H_INCLUDED
