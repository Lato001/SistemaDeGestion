#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

#include "ArchivoDetalleVentas.h"
#include "DetalleVenta.h"
#include "rlutil.h"
#include "Menu.h"
using namespace std;


ArchivoDetalleVentas::ArchivoDetalleVentas(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoDetalleVentas::Guardar(DetalleVenta detalleVenta){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoDetalleVentas::Guardar(DetalleVenta detalleVenta, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(DetalleVenta) * posicion, SEEK_SET);
    bool ok = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, registro);
    fclose(registro);
    return ok;
}

DetalleVenta ArchivoDetalleVentas::Buscar(int idVenta){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    DetalleVenta detalleVenta, fallo;
    fallo.setIdVenta(-1);
    if(registro == NULL){
        return fallo;
    }
    while(fread(&detalleVenta, sizeof(detalleVenta), 1, registro)){
        if(detalleVenta.getIdVenta() == idVenta){
            fclose(registro);
            return detalleVenta;
        }
    }
    fclose(registro);
    return fallo;
}
DetalleVenta ArchivoDetalleVentas::BuscarPorLinea(int idVenta, int idLinea){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    DetalleVenta detalleVenta, fallo;
    fallo.setIdVenta(-1);
    if(registro == NULL){
        return fallo;
    }
    while(fread(&detalleVenta, sizeof(detalleVenta), 1, registro)){
        if(detalleVenta.getIdVenta() == idVenta && detalleVenta.getIdLinea() == idLinea){
            fclose(registro);
            return detalleVenta;
        }
    }
    fclose(registro);
    return fallo;
}
int ArchivoDetalleVentas::ContLineas(int idVenta) {
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if (registro == NULL) {
        return 0;
    }

    DetalleVenta detalleVenta;
    int cont = 0;

    for (int i = 0; i < CantidadRegistros(); i++) {
        if (fread(&detalleVenta, sizeof(detalleVenta), 1, registro) == 1) {
            if (detalleVenta.getIdVenta() == idVenta) {
                cont++;
            }
        } else {
            fclose(registro);
            return -1;
        }
    }

    fclose(registro);
    return cont;
}
DetalleVenta ArchivoDetalleVentas::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return DetalleVenta();
    }
    DetalleVenta detalleVenta;
    fseek(registro, sizeof(DetalleVenta) * posicion, SEEK_SET);
    fread(&detalleVenta, sizeof(DetalleVenta), 1, registro);
    fclose(registro);
    return detalleVenta;
}

int ArchivoDetalleVentas::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(DetalleVenta);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoDetalleVentas::Leer(int cantidadRegistros, DetalleVenta *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(DetalleVenta), 1, registro);
    }
    fclose(registro);
}

int ArchivoDetalleVentas::BuscarPosRegistro(int idVenta){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    DetalleVenta detalleVenta;
    if(registro == NULL){
        return -1;
    }
    int i = 0;
    while(fread(&detalleVenta, sizeof(detalleVenta), 1, registro) == 1){
        if(detalleVenta.getIdVenta() == idVenta){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}

void ArchivoDetalleVentas::ModificarDetalleVenta(int idVenta) {
    int pos = BuscarPosRegistro(idVenta);
    if (pos == -1) {
            Menu::setColor(4);
        cout << "Detalle de Venta no encontrada." << endl;
        return;
        }
    DetalleVenta detalleVenta = Leer(pos);
    int idOriginal = detalleVenta.getIdVenta();
    detalleVenta.cargarDetalleDeVenta(idOriginal);
    detalleVenta.setIdVenta(idOriginal);
    if (Guardar(detalleVenta, pos)) {
            Menu::setColor(7);
        cout << "Datos del detalle venta actualizados." << endl;
    } else {
        Menu::setColor(4);
        cout << "Error al actualizar los datos del detalle de venta." << endl;
    }
}


void ArchivoDetalleVentas::exportarDetalleVentasACSV(string nombreArchivoCSV) {
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if (registro == nullptr) {
        Menu menu;
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        return;
    }

    ofstream archivoCSV(nombreArchivoCSV);
    if (!archivoCSV.is_open()) {
        Menu menu;
        menu.mensajeDeError("Error al crear el archivo CSV.");
        fclose(registro);
        return;
    }


    DetalleVenta detalleVenta;
    int cont = 0;
    while (fread(&detalleVenta, sizeof(DetalleVenta), 1, registro)) {
    cout << "ID Venta:" << detalleVenta.getIdVenta()<< endl;
    cout << "Importe Total:" << detalleVenta.getImporte()<< endl;
    cout << "Estado:" << detalleVenta.getEstado()<< endl;
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;


    }

    fclose(registro);
    archivoCSV.close();
}
