#include <iostream>
#include "rlutil.h"

using namespace std;

#include "DetalleVenta.h"
#include "ArchivoDetalleVentas.h"
#include "Venta.h"
#include "Producto.h"
#include "ArchivoProductos.h"

DetalleVenta::DetalleVenta() {
    idVenta = 0;
    idLinea = 0;
    idProducto = 0;
    cantidadProducto = 0;
    importe = 0;
    estado = false;
}

DetalleVenta::DetalleVenta(int _idVenta, int _idLinea, int _idProducto, int _cantidadProducto, float _importe, bool _estado) {
    idVenta = _idVenta;
    idLinea = _idLinea;
    idProducto = _idProducto;
    cantidadProducto = _cantidadProducto;
    importe = _importe;
    estado = _estado;
}

int DetalleVenta::getIdVenta() {return idVenta;}

int DetalleVenta::getIdLinea() {return idLinea;}

int DetalleVenta::getIdProducto() {return idProducto;}

int DetalleVenta::getCantidadProducto() {return cantidadProducto;}

float DetalleVenta::getImporte() {return importe;}

bool DetalleVenta::getEstado() {return estado;}

void DetalleVenta::setIdVenta(int _idVenta) {idVenta = _idVenta;}

void DetalleVenta::setIdLinea(int _idLinea) {idLinea = _idLinea;}

void DetalleVenta::setIdProducto(int _idProducto) {idProducto = _idProducto;}

void DetalleVenta::setCantidadProducto(int _cantidadProducto) {cantidadProducto = _cantidadProducto;}

void DetalleVenta::setImporte(float _importe) {importe = _importe;}

void DetalleVenta::setEstado(bool _estado) {estado = _estado;}

void DetalleVenta::cargarDetalleDeVenta(int _idVenta) {
    idVenta = _idVenta;
    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");

    if(DetalleVentas.ContLineas(idVenta) > 0){
        idLinea = DetalleVentas.ContLineas(idVenta) + 1;
    }else{
        idLinea = 1;
    }

    ArchivoProductos Productos("ArchivoProductos.dat");

    Producto registro;
    int input;
    Producto productoActual;

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

        productoActual = Productos.Buscar(input);

        if (productoActual.getProductoID() != -1) {
            opcionValida = true;
            idProducto = productoActual.getProductoID();
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
        cout << "Stock Disponible: " << productoActual.getStock() << endl << endl;
        cout << "Ingrese la cantidad comprada del producto: " << endl;
        rlutil::setColor(rlutil::BLACK);
        cin >> input;

        if (input <= productoActual.getStock()) {
            cantidadProducto = input;

            productoActual.setStock(productoActual.getStock() - input);
            Productos.Guardar(productoActual, Productos.BuscarPos(idProducto)); ///??? PARA QUE SIRVE
            opcionValida = true;
        } else {
                rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida! Vuelva a intentarlo" << endl;
               rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");

        }
    }
        importe = Productos.Buscar(idProducto).getPrecioUnitario() * cantidadProducto;
        cout<< importe;
}

void DetalleVenta::mostrarDetalleDeVenta()
{

    ArchivoDetalleVentas DetalleVentas("ArchivoDetalleVentas.dat");
    ArchivoProductos Productos("ArchivoProductos.dat");
    Producto producto;
    for (int i =1; i<= DetalleVentas.ContLineas(idVenta); i++ )
    {
        rlutil::setColor(rlutil::CYAN);
        cout << "ID DEL PRODUCTO: " << DetalleVentas.BuscarPorLinea(idVenta,i).getIdProducto()<< endl;

        idProducto=getIdProducto();

        rlutil::setColor(rlutil::WHITE);

        cout << "PRECIO UNITARIO: " << Productos.Buscar(DetalleVentas.BuscarPorLinea(idVenta, i).getIdProducto()).getPrecioUnitario() << endl; //llamar al precio unitario que traeria desde producto asociado a DetalleVentas por herencia

        cout << "CANTIDAD DEL PRODUCTO: " << DetalleVentas.BuscarPorLinea(idVenta,i).getCantidadProducto() << endl;
        cout<< "IMPORTE: $" << DetalleVentas.BuscarPorLinea(idVenta,i).getImporte()<<endl;
        cout<<endl;
        cout<<endl;
    }
}
