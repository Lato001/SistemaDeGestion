#pragma once
#include <string>
#include <cstring>

#include "ArchivoVentas.h"
#include "Venta.h"
using namespace std;


ArchivoVentas::ArchivoVentas(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoVentas::Guardar(Venta venta){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&venta, sizeof(Venta), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoVentas::Guardar(Venta venta, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(Venta) * posicion, SEEK_SET);
    bool ok = fwrite(&venta, sizeof(Venta), 1, registro);
    fclose(registro);
    return ok;
}

int ArchivoVentas::Buscar(int nDeVenta){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return -1;
    }
    Venta venta;
    int i = 0;
    while(fread(&venta, sizeof(venta), 1, registro)){
        if(venta.getNDeVenta() == nDeVenta){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}
Venta ArchivoVentas::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return Venta();
    }
    Venta venta;
    fseek(registro, sizeof(Venta) * posicion, SEEK_SET);
    fread(&venta, sizeof(Venta), 1, registro);
    fclose(registro);
    return venta;
}

int ArchivoVentas::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Venta);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoVentas::Leer(int cantidadRegistros, Venta *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Venta), 1, registro);
    }
    fclose(registro);
}
