#include <iostream>
#include "rlutil.h"

using namespace std;

#include "Producto.h"
#include "ArchivoProductos.h"
#include "ArchivoProductos.h"
#include "Venta.h"


Producto::Producto() {
    idVenta = 0;
    idLinea = 0;
    idProducto = 0;
    cantidadProducto = 0;
    importe = 0;
    estado = false;
}

Producto::Producto(int _idVenta, int _idLinea, int _idProducto, int _cantidadProducto, float _importe, bool _estado) {
    idVenta = _idVenta;
    idLinea = _idLinea;
    idProducto = _idProducto;
    cantidadProducto = _cantidadProducto;
    importe = _importe;
    estado = _estado;
}

int Producto::getIdVenta() {return idVenta;}

int Producto::getIdLinea() {return idLinea;}

int Producto::getIdProducto() {return idProducto;}

int Producto::getCantidadProducto() {return cantidadProducto;}

float Producto::getImporte() {return importe;}

bool Producto::getEstado() {return estado;}

void Producto::setIdVenta(int _idVenta) {idVenta = _idVenta;}

void Producto::setIdLinea(int _idLinea) {idLinea = _idLinea;}

void Producto::setIdProducto(int _idProducto) {idProducto = _idProducto;}

void Producto::setCantidadProducto(int _cantidadProducto) {cantidadProducto = _cantidadProducto;}

void Producto::setImporte(float _importe) {importe = _importe;}

void Producto::setEstado(bool _estado) {estado = _estado;}

void Producto::cargarDetalleDeVenta(int _idVenta) {
    idVenta = _idVenta;
    ArchivoProductos DetalleVentas("ArchivoDetalleVentas.dat");

    if(DetalleVentas.ContLineas(idVenta) > 0){
        idLinea = DetalleVentas.ContLineas(idVenta) + 1;
    }else{
        idLinea = 1;
    }

    ArchivoProductos Productos("ArchivoProductos.dat");

    Producto registro;
    int input;

    bool opcionValida = false;
    while (!opcionValida) {
        rlutil::setColor(rlutil::WHITE);
        for (int i = 0; i < Productos.CantidadRegistros(); i++) {
            registro = Productos.Leer(i);
            registro.mostrarProducto();
            cout << endl;
        }
         rlutil::setColor(rlutil::WHITE);
        cout << "Ingrese la opcion deseada: ";

         rlutil::setColor(rlutil::BLACK);
        cin >> input;

        if (Productos.Buscar(input).getProductoID() != -1) {
            opcionValida = true;
            idProducto = Productos.Buscar(input).getProductoID();
        } else {
                  rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida, vuelva a intentarlo" << endl;
                  rlutil::setColor(rlutil::WHITE);
        }
        system("pause");
        system("cls");
    }

    opcionValida = false;
    while (!opcionValida) {
        rlutil::setColor(rlutil::WHITE);
        cout << "Stock Disponible: " << Productos.Buscar(idProducto).getStock() << endl << endl;
        cout << "Ingrese la cantidad comprada del producto: " << endl;
        rlutil::setColor(rlutil::BLACK);
        cin >> input;

        if (input <= Productos.Buscar(idProducto).getStock()) {
            cantidadProducto = input;
            Productos.Buscar(idProducto).setStock(Productos.Buscar(idProducto).getStock() - input);
            opcionValida = true;
        } else {
                rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida! Vuelva a intentarlo" << endl;
               rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
        }
        importe = Productos.Buscar(idProducto).getPrecioUnitario() * cantidadProducto;
    }
}

void Producto::mostrarDetalleDeVenta() {

    ArchivoProductos DetalleVentas("ArchivoDetalleVentas.dat");
    ArchivoProductos Productos ("ArchivoProductos.dat");
    Venta venta;
    for (int i =1; i<= DetalleVentas.ContLineas(idVenta);i++ ){
    rlutil::setColor(rlutil::CYAN);
    cout << "ID DEL PRODUCTO: " << DetalleVentas.BuscarPorLinea(idVenta,i).getIdProducto()<< endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "PRECIO UNITARIO: " << Productos.Buscar(idProducto).getPrecioUnitario() << endl;
    cout << "CANTIDAD DEL PRODUCTO: " << DetalleVentas.BuscarPorLinea(idVenta,i).getCantidadProducto() << endl;
    cout<< "IMPORTE: $" << DetalleVentas.BuscarPorLinea(idVenta,i).getImporte()<<endl;
    cout<<endl;
    cout<<endl;
    }
}

