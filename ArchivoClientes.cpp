#pragma once
#include <string>
#include <cstring>

#include "ArchivoClientes.h"
#include "Cliente.h"

using namespace std;


ArchivoClientes::ArchivoClientes(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoClientes::Guardar(Cliente cliente){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoClientes::Guardar(Cliente cliente, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(Cliente) * posicion, SEEK_SET);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, registro);
    fclose(registro);
    return ok;
}

int ArchivoClientes::Buscar(int clienteID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return -1;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(cliente), 1, registro)){
        if(cliente.getID() == clienteID){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}
Cliente ArchivoClientes::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return Cliente();
    }
    Cliente cliente;
    fseek(registro, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, registro);
    fclose(registro);
    return cliente;
}

int ArchivoClientes::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Cliente);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoClientes::Leer(int CantidadRegistros, Cliente *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < CantidadRegistros; i++){
        fread(&vector[i], sizeof(Cliente), 1, registro);
    }
    fclose(registro);
}

