#pragma once
#include <string>
#include <cstring>
#include <iostream>
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


Empleado ArchivoEmpleados::Buscar(int empleadoID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado, fallo;
    fallo.setempleadoID(-1);
    if(registro == NULL){
        return fallo;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro)){
        if(empleado.getID() == empleadoID){
            fclose(registro);
            return empleado;
        }
    }
    fclose(registro);
    return fallo;
}
void ArchivoEmpleados::FiltrarEmpleados(){
   FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    int cont = 0;

    if (registro == nullptr) {
        cout << "No se encontraron empleados." << endl;
        return;
    }
    while (fread(&empleado, sizeof(empleado), 1, registro)) {
        cont++;
        cout << cont << ". ";
        empleado.mostrarEmpleado();
    }

    if (cont == 0) {
        cout << "No se encontraron empleados en el archivo." << endl;
    }

    fclose(registro);


}
void ArchivoEmpleados::FiltrarPorNombre(string _nombre){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    int cont = 0;
    if (registro == nullptr) {
        cout << "No se encontraron empleados." << endl;
        return;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro)){
        if(empleado.getNombre() == _nombre){
            fclose(registro);
            empleado.mostrarEmpleado();
            cont++;
        }
    }
    if(cont == 0){
        cout<< "No se encontraron empleados con el nombre: " << _nombre<<endl;
    }
    fclose(registro);

}
void ArchivoEmpleados::FiltrarPorID(int _ID){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    int cont = 0;
    if (registro == nullptr) {
        cout << "No se encontraron empleados." << endl;
        return;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro)){
        if(empleado.getID() == _ID){
            fclose(registro);
            empleado.mostrarEmpleado();
            cont++;
        }
    }
    if(cont == 0){
        cout<< "No se encontraron empleados con el ID: " << _ID<<endl;
    }
    fclose(registro);

}
void ArchivoEmpleados::FiltrarPorAsistencias(){

 FILE *registro = fopen(_nombreArchivo.c_str(), "rb");

    Empleado empleadoArr[40];
    Empleado empleado;
    int cont = 0;
    if (registro == nullptr) {
        cout << "No se encontraron empleados." << endl;
        return;
    }

    // Leer empleados desde el archivo
    while (fread(&empleado, sizeof(empleado), 1, registro) && cont < 40) {
        empleadoArr[cont] = empleado; // Agregar empleado al arreglo
        cont++;
    }
    fclose(registro);

    // Ordenar empleados por asistencias de manera ascendente
    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (empleadoArr[j].getAsistencias() < empleadoArr[j + 1].getAsistencias()) {
                // Intercambiar empleados
                Empleado temp = empleadoArr[j];
                empleadoArr[j] = empleadoArr[j + 1];
                empleadoArr[j + 1] = temp;
            }
        }
    }

    // Mostrar empleados ordenados por asistencias
    for (int i = 0; i < cont; i++) {
        empleadoArr[i].mostrarEmpleado();
    }

}
void ArchivoEmpleados::FiltrarPorVacacionesActivas(bool _vacaciones){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    int cont = 0;
    if (registro == nullptr) {
        cout << "No se encontraron empleados." << endl;
        return;
    }
    while (fread(&empleado, sizeof(empleado), 1, registro)) {
            if(empleado.getIsVacaciones() == _vacaciones){
            empleado.mostrarEmpleado();
            cont++;
        }
    }

    if(cont==0 && _vacaciones){
        cout<< "No se encontraron empleados con vacaciones activas";
    }else if(cont ==0 && !_vacaciones){
    cout<< "No se encontraron empleados con vacaciones inactivas";
    }


    fclose(registro);

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
