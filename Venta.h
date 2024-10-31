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
    int idEmpleado; //Cambio
    int idCliente; //Cambio
    Fecha fecha;
    int formaDePago;
    float importeTotal = 0;
    bool estado;
public:

    Venta();
    Venta(int _idVenta, Fecha _fecha, int _idEmpleado, int _idCliente, int _formaDePago, float _importeTotal, bool _estado);
    int getIdVenta();
    int getIdEmpleado(); //Cambio
    int getIdCliente();  //Cambio
    Fecha getFecha();
    int getFormaDePago();
    float getImporteTotal(); //Cambio
    bool getEstado(); //Cambio

    void setidVenta(int _idVenta); //Cambio
    void setFecha(Fecha _fecha);
    void setFormaDePago(int _formaDePago);
    void setidEmpleado(int _idEmpleado); //Cambio
    void setidCliente(int _idCliente); //Cambio
    void setImporteTotal(float _ImporteTotal); //CambioD
    void setEstado(bool _estado);

    void cargarVenta();
    void mostrarVenta();
};


#endif // VENTA_H_INCLUDED
