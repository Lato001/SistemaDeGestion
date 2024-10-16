#pragma once
#include <string>
#include <cstring>

#include "ArchivoCompradores.h"
#include "Comprador.h"

using namespace std;


ArchivoCompradores::ArchivoCompradores(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCompradores::Guardar(Comprador comprador){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&comprador, sizeof(Comprador), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoCompradores::Guardar(Comprador comprador, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(Comprador) * posicion, SEEK_SET);
    bool ok = fwrite(&comprador, sizeof(Comprador), 1, registro);
    fclose(registro);
    return ok;
}

int ArchivoCompradores::Buscar(int compradorID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return -1;
    }
    Comprador comprador;
    int i = 0;
    while(fread(&comprador, sizeof(comprador), 1, registro)){
        if(comprador.getID() == compradorID){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}
Comprador ArchivoCompradores::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return Comprador();
    }
    Comprador comprador;
    fseek(registro, sizeof(Comprador) * posicion, SEEK_SET);
    fread(&comprador, sizeof(Comprador), 1, registro);
    fclose(registro);
    return comprador;
}

int ArchivoCompradores::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Comprador);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoCompradores::Leer(int cantidadRegistros, Comprador *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Comprador), 1, registro);
    }
    fclose(registro);
}

