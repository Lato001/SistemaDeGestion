#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include "Empleado.h"
#include "Cliente.h"
#include "DetalleVenta.h"

class Venta
{
private:
    int idVenta;
    int idEmpleado;
    int idCliente;
    Fecha fecha;
    int formaDePago;
    float importeTotal = 0;
    bool estado = false;
public:

    Venta();
    Venta(int _idVenta,  int _idEmpleado, int _idCliente, Fecha _fecha, int _formaDePago, float _importeTotal, bool _estado);
    int getIdVenta();
    int getIdEmpleado();
    int getIdCliente();
    Fecha getFecha();
    int getFormaDePago();
    float getImporteTotal();
    bool getEstado();

    void setidVenta(int _idVenta);
    void setidEmpleado(int _idEmpleado);
    void setidCliente(int _idCliente);
    void setFecha(Fecha _fecha);
    void setFormaDePago(int _formaDePago);
    void setImporteTotal(float _ImporteTotal);
    void setEstado(bool _estado);

    void cargarVenta();
    void mostrarVenta();
};


#endif // VENTA_H_INCLUDED
