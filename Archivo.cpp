#pragma once
#include <string>
#include <cstring>

#include "Archivo.h"
#include "Persona.h"
using namespace std;


ArchivoPersona::ArchivoPersona(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoPersona::Guardar(Persona persona){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&persona, sizeof(Persona), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoPersona::Guardar(Persona persona, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(Persona) * posicion, SEEK_SET);
    bool ok = fwrite(&persona, sizeof(Persona), 1, registro);
    fclose(registro);
    return ok;
}

int ArchivoPersona::Buscar(int DNI){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return -1;
    }
    Persona persona;
    int i = 0;
    while(fread(&persona, sizeof(persona), 1, registro)){
        if(persona.getDNI() == DNI){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}
Persona ArchivoPersona::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return Persona();
    }
    Persona persona;
    fseek(registro, sizeof(Persona) * posicion, SEEK_SET);
    fread(&persona, sizeof(Persona), 1, registro);
    fclose(registro);
    return persona;
}

int ArchivoPersona::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Persona);
    fclose(registro);
    return cantidadRegistros;
}

void ArchivoPersona::Leer(int cantidadRegistros, Persona *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Persona), 1, registro);
    }
    fclose(registro);
}
