#pragma once
#include <string>
#include <cstring>

#include "ArchivoDetalleVentas.h"
#include "DetalleVenta.h"
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
