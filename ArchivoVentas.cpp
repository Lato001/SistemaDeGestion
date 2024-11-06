#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <conio.h>

#include "ArchivoVentas.h"
#include "Venta.h"
#include "rlutil.h"
#include "Menu.h"
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

Venta ArchivoVentas::Buscar(int idVenta){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Venta venta,fallo;
    fallo.setidVenta(-1);
    if(registro == NULL){
        return fallo;
    }
    while(fread(&venta, sizeof(venta), 1, registro)){
        if(venta.getIdVenta() == idVenta){
            fclose(registro);
            return venta;
        }
    }
    fclose(registro);
    return fallo;
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

int ArchivoVentas::BuscarPosRegistro(int idVenta){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Venta venta;
    if(registro == NULL){
        return -1;
    }
    int i = 0;
    while(fread(&venta, sizeof(venta), 1, registro) == 1){
        if(venta.getIdVenta() == idVenta){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}

void ArchivoVentas::ModificarVenta(int idVenta) {
    int pos = BuscarPosRegistro(idVenta);
    if (pos == -1) {
            Menu::setColor(4);
        cout << "Venta no encontrada." << endl;
        return;
        }
    Venta venta = Leer(pos);
    int idOriginal = venta.getIdVenta();
    venta.cargarVenta();
    venta.setidVenta(idOriginal);
    if (Guardar(venta, pos)) {
            Menu::setColor(7);
        cout << "Datos de la venta actualizados." << endl;
    } else {
        Menu::setColor(4);
        cout << "Error al actualizar los datos de la venta." << endl;
    }
}

void ArchivoVentas::eliminarArchivoVentas()
{
    Menu menu;
    menu.setColor(7);
    int id, aux;
    ifstream salida;
    salida.open("ArchivoVentas.dat", ios::in);
    ofstream entrada;
    entrada.open("temp.dat", ios::out);

    if (salida.fail())
    {
        cout << "Hubo un error al abrir el archivo ArchivoVentas.dat" << endl;
        cin.get();
        exit(0);
    }
    else
    {
        cout << "Introduzca el ID: ";
        cin >> aux;

        while (salida >> id)
        {
            if (id == aux)
            {
                cout << "El registro ha sido eliminado." << endl;
            }
            else
            {
                entrada << id << " " << endl;
            }
        }

        salida.close();
        entrada.close();

        remove("ArchivoVentas.dat");  // Eliminar el archivo original
        rename("temp.dat", "ArchivoVentas.dat");  // Renombrar el archivo temporal a "ArchivoEmpleados.dat"
    }
}
void ArchivoVentas::eliminarRegistroVenta(int ventaID)
{
    int idVenta;
    FILE* archivoOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if (archivoOriginal == nullptr)
    {
        cout << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    FILE* archivoTemporal = fopen("ventas_temp.dat", "wb");
    if (archivoTemporal == nullptr)
    {
        cout << "Error al crear archivo temporal." << endl;
        fclose(archivoOriginal);
        return;
    }

    Venta venta;
    bool encontrado = false;


    while (fread(&venta, sizeof(Venta), 1, archivoOriginal))
    {
        if (venta.getIdVenta() != ventaID)
        {

            fwrite(&venta, sizeof(Venta), 1, archivoTemporal);
        }
        else
        {
            idVenta = venta.getIdVenta();
            encontrado = true;
        }
    }


    fclose(archivoOriginal);
    fclose(archivoTemporal);


    if (encontrado)
    {
        remove(_nombreArchivo.c_str());
        rename("ventas_temp.dat", _nombreArchivo.c_str());
        cout << "Venta con ID " << idVenta <<" eliminado correctamente." << endl;
    }
    else
    {

        remove("ventas_temp.dat");
        cout << "Venta con ID " << idVenta << " no encontrado." << endl;
    }
}
