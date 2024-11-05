#pragma once
#include <string>
#include <cstring>
#include <iostream>

#include "ArchivoEmpleados.h"
#include "Empleado.h"
#include "Menu.h"

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
    Menu menu;
    int cont = 0;

    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron empleados.");
        return;
    }
    while (fread(&empleado, sizeof(empleado), 1, registro)) {
        cont++;
        cout << cont << ". ";
        empleado.mostrarEmpleado();
    }

    if (cont == 0) {
        menu.mensajeDeError("No se encontraron empleados en el archivo.");
    }

    fclose(registro);


}
void ArchivoEmpleados::FiltrarPorNombre(string _nombre){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron empleados." );
        return;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro))
    {
        if(empleado.getNombre() == _nombre){
            fclose(registro);
            empleado.mostrarEmpleado();
            cont++;
        }
    }
    if(cont == 0){
        menu.mensajeDeError("No se encontraron empleados con el nombre: ");
        cout << _nombre<<endl;
    }
    fclose(registro);

}

void ArchivoEmpleados::FiltrarPorOrdenAlfabetico()
{
    FILE *registroA = fopen(_nombreArchivo.c_str(), "rb");
    int cantRegistros = ArchivoEmpleados::CantidadRegistros();
    Empleado* registro = new Empleado[cantRegistros];

    Empleado empleado;
    Menu menu;

    if(registroA == nullptr)
    {

        menu.mensajeDeError("No se han encontrado empleados registrados");

        return;
    }
        if (cantRegistros != 0)
        {
            for (int i = 0; i < cantRegistros; i++ )
            {
                registro[i] = ArchivoEmpleados::Leer(i);
            }
            for (int i = 0; i <= cantRegistros ; i++)
            {
                for (int j = 0; j <= cantRegistros ; j++)
                {
                    if (strcmp (registro[j].getNombre(),registro[i].getNombre()) > 0)
                    {
                        Empleado temp = registro[i];
                        registro[i] = registro[j];
                        registro[j] = temp;
                    }
                }
            }
            for ( int i = 0 ; i <=cantRegistros ; i++ )
            {
                registro[i].mostrarEmpleado();
            }
        }
    delete[] registro;
    fclose(registroA);
}

void ArchivoEmpleados::FiltrarPorID(int _ID){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron empleados." );
        return;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro)){
        if(empleado.getID() == _ID)
        {
            empleado.mostrarEmpleado();
            cont++;
        }
    }
    if(cont == 0){
        menu.mensajeDeError("No se encontraron empleados con el ID: ");
        cout<< _ID<<endl;
    }
    fclose(registro);

}
void ArchivoEmpleados::FiltrarPorFecha()
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    int cantRegistros = ArchivoEmpleados::CantidadRegistros();
    Empleado* empleado = new Empleado [cantRegistros];
    Menu menu;
    Fecha fecha;
    int cont = 0;
    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron empleados." );
        return;
    }
    if (cantRegistros != 0)
    {
        for (int i = 0; i < cantRegistros; i++ )
        {
            empleado[i] = ArchivoEmpleados::Leer(i);
        }
        for (int i = 0; i < cantRegistros - 1; i++)
        {
            for (int j = 0; j < cantRegistros - i - 1; j++)
            {
                Fecha fechaA = empleado[j].getFechaIngreso();
                Fecha fechaB = empleado[j + 1].getFechaIngreso();

                if (fechaA.getAnio() > fechaB.getAnio() ||
                        (fechaA.getAnio() == fechaB.getAnio() && fechaA.getMes() > fechaB.getMes()) ||
                        (fechaA.getAnio() == fechaB.getAnio() && fechaA.getMes() == fechaB.getMes() && fechaA.getDia() > fechaB.getDia()))
                {
                    Empleado temp = empleado[j];
                    empleado[j] = empleado[j + 1];
                    empleado[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < cantRegistros; i++)
        {
            empleado[i].mostrarEmpleado();
        }
    }
    else
    {
        menu.mensajeDeError("No se encontraron empleados");
    }

    fclose(registro);
}

void ArchivoEmpleados::FiltrarPorAsistencias(){

 FILE *registro = fopen(_nombreArchivo.c_str(), "rb");

    Empleado empleadoArr[40];
    Empleado empleado;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
       menu.mensajeDeError("No se encontraron empleados.");
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
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron empleados.");
        return;
    }
    while (fread(&empleado, sizeof(empleado), 1, registro)) {
            if(empleado.getIsVacaciones() == _vacaciones){
            empleado.mostrarEmpleado();
            cont++;
        }
    }

    if(cont==0 && _vacaciones){
       menu.mensajeDeError("No se encontraron empleados con vacaciones activas");
    }else if(cont ==0 && !_vacaciones){
    menu.mensajeDeError("No se encontraron empleados con vacaciones inactivas");
    }


    fclose(registro);

}
void ArchivoEmpleados::eliminarRegistroEmpleado()
{
string nombreEmpleado;
    cout << "Ingrese el nombre del empleado que desea eliminar: ";
    cin.ignore();
    getline(cin, nombreEmpleado);

    FILE* archivoOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if (archivoOriginal == nullptr)
    {
        cout << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    FILE* archivoTemporal = fopen("empleados_temp.dat", "wb");
    if (archivoTemporal == nullptr)
    {
        cout << "Error al crear archivo temporal." << endl;
        fclose(archivoOriginal);
        return;
    }

    Empleado empleado;
    bool encontrado = false;


    while (fread(&empleado, sizeof(Empleado), 1, archivoOriginal))
    {
        if (empleado.getNombre() != nombreEmpleado)
        {

            fwrite(&empleado, sizeof(Empleado), 1, archivoTemporal);
        }
        else
        {
            encontrado = true;
        }
    }


    fclose(archivoOriginal);
    fclose(archivoTemporal);


    if (encontrado)
    {
        remove(_nombreArchivo.c_str());
        rename("empleados_temp.dat", _nombreArchivo.c_str());
        cout << "Empleado con nombre " << nombreEmpleado << " eliminado correctamente." << endl;
    }
    else
    {

        remove("empleados_temp.dat");
        cout << "Empleado con ID " << nombreEmpleado << " no encontrado." << endl;
    }
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
