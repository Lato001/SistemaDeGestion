#pragma once
#include <string>
#include <cstring>

#include "ArchivoProductos.h"
#include "Producto.h"
using namespace std;


ArchivoProductos::ArchivoProductos(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoProductos::Guardar(Producto producto){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&producto, sizeof(Producto), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoProductos::Guardar(Producto producto, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(Producto) * posicion, SEEK_SET);
    bool ok = fwrite(&producto, sizeof(Producto), 1, registro);
    fclose(registro);
    return ok;
}

int ArchivoProductos::Buscar(int ID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return -1;
    }
    Producto producto;
    int i = 0;
    while(fread(&producto, sizeof(producto), 1, registro)){
        if(producto.getProductoID()== ID){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}
Producto ArchivoProductos::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return Producto();
    }
    Producto producto;
    fseek(registro, sizeof(Producto) * posicion, SEEK_SET);
    fread(&producto, sizeof(Producto), 1, registro);
    fclose(registro);
    return producto;
}

int ArchivoProductos::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Producto);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoProductos::Leer(int cantidadRegistros, Producto *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Producto), 1, registro);
    }
    fclose(registro);
}

