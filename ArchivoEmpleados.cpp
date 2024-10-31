#pragma once
#include <string>
#include <cstring>

#include "ArchivoEmpleados.h"
#include "Empleado.h"
using namespace std;


ArchivoEmpleados::ArchivoEmpleados(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoEmpleados::Guardar(Empleado empleado){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoEmpleados::Guardar(Empleado empleado, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(Empleado) * posicion, SEEK_SET);
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, registro);
    fclose(registro);
    return ok;
}

int ArchivoEmpleados::Buscar(int DNI){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return -1;
    }
    Empleado empleado;
    int i = 0;
    while(fread(&empleado, sizeof(empleado), 1, registro)){
        if(empleado.getDNI() == DNI){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}
Empleado ArchivoEmpleados::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return Empleado();
    }
    Empleado empleado;
    fseek(registro, sizeof(Empleado) * posicion, SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, registro);
    fclose(registro);
    return empleado;
}

int ArchivoEmpleados::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Empleado);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoEmpleados::Leer(int cantidadRegistros, Empleado *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Empleado), 1, registro);
    }
    fclose(registro);
}
/*
bool ArchivoEmpleados::eliminar(int ID) {
    FILE *punteroFile, *punteroTemp;
    Empleado empleado;


    punteroFile = fopen("Empleados.dat", "rb");
    if (punteroFile == nullptr) {return false;}
    punteroTemp = fopen("temp.dat", "wb");
    if (punteroTemp == nullptr) {return false;}

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
        if (strcmp(nombre, nombre) != 0) {
            fwrite(&nombre, sizeof(char), 50, punteroTemp);
            fread(&ID,sizeof(int),1,punteroFile);
            fwrite(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fwrite(&team, sizeof(char), 50, punteroTemp);
            fread(&edad, sizeof(int), 1, punteroFile);
            fwrite(&edad, sizeof(int), 1, punteroTemp);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fwrite(&posicion, sizeof(char), 50, punteroTemp);
            fread(&numero, sizeof(int), 1, punteroFile);
            fwrite(&numero, sizeof(int), 1, punteroTemp);
            fread(&goles, sizeof(int), 1, punteroFile);
            fwrite(&goles, sizeof(int), 1, punteroTemp);
            fread(&asistencias, sizeof(int), 1, punteroFile);
            fwrite(&asistencias, sizeof(int), 1, punteroTemp);
        } else {
            encontrado = true;
            fread(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        }
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    if (!encontrado) {
        cout << "No se encontro elempleado..." <<endl;
        remove("temp.dat");
    }
    remove("Empleados.dat");
    rename("temp.dat", "Empleados.dat");

    return encontrado;
}
*/
