#include <iostream>
#include "rlutil.h"

using namespace std;

#include "DetalleVenta.h"
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

int DetalleVenta::getIdVenta() {
    return idVenta;
}

int DetalleVenta::getIdLinea() {
    return idLinea;
}

int DetalleVenta::getIdProducto() {
    return idProducto;
}

int DetalleVenta::getCantidadProducto() {
    return cantidadProducto;
}

float DetalleVenta::getImporte() {
    return importe;
}

bool DetalleVenta::getEstado() {
    return estado;
}

void DetalleVenta::setIdVenta(int _idVenta) {
    idVenta = _idVenta;
}

void DetalleVenta::setIdLinea(int _idLinea) {
    idLinea = _idLinea;
}

void DetalleVenta::setIdProducto(int _idProducto) {
    idProducto = _idProducto;
}

void DetalleVenta::setCantidadProducto(int _cantidadProducto) {
    cantidadProducto = _cantidadProducto;
}

void DetalleVenta::setImporte(float _importe) {
    importe = _importe;
}

void DetalleVenta::setEstado(bool _estado) {
    estado = _estado;
}

void DetalleVenta::cargarDetalleDeVenta(int _idVenta) {\
    idVenta = _idVenta;
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
         rlutil::setColor(rlutil::BLACK);
        cout << "Ingrese la opcion deseada: ";

         rlutil::setColor(rlutil::WHITE);
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
        rlutil::setColor(rlutil::BLACK);
        cout << "Stock Disponible: " << Productos.Buscar(idProducto).getStock() << endl << endl;
        cout << "Ingrese la cantidad comprada del producto: " << endl;
        rlutil::setColor(rlutil::WHITE);
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

void DetalleVenta::mostrarDetalleDeVenta() {
    rlutil::setColor(rlutil::CYAN);
    cout << "ID DEL PRODUCTO: " << getIdProducto() << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "CANTIDAD DEL PRODUCTO: " << getCantidadProducto() << endl;
    cout<< "IMPORTE: $" << importe<<endl;
}

