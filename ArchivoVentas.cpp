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
    Menu menu;
    int pos = BuscarPosRegistro(idVenta);
    if (pos == -1) {

         menu.mensajeDeError("Venta no encontrada.");
         cout  << endl;
        return;
        }
    Venta venta = Leer(pos);
    int idOriginal = venta.getIdVenta();
    venta.cargarVenta();
    venta.setidVenta(idOriginal);
    if (Guardar(venta, pos)) {
            Menu::setColor(2);
        cout << "Datos de la venta actualizados." << endl;
            Menu::setColor(7);
    } else {

         menu.mensajeDeError("Error al actualizar los datos de la venta." );
         cout<< endl;
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
        menu.mensajeDeError("Hubo un error al abrir el archivo ArchivoVentas.dat");
       cout << endl;
        cin.get();
        exit(0);
    }
    else
    {

        salida.close();
        entrada.close();

        remove("ArchivoVentas.dat");  // Eliminar el archivo original
        rename("temp.dat", "ArchivoVentas.dat");  // Renombrar el archivo temporal a "ArchivoEmpleados.dat"
        cout<<"Registros del archivo eliminados"<<endl;
    }
}
void ArchivoVentas::eliminarRegistroVenta(int ventaID)
{
    Menu menu;
    int idVenta;
    FILE* archivoOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if (archivoOriginal == nullptr)
    {
         menu.mensajeDeError("Error al abrir el archivo para lectura." );
        cout<< endl;
        return;
    }

    FILE* archivoTemporal = fopen("ventas_temp.dat", "wb");
    if (archivoTemporal == nullptr)
    {
         menu.mensajeDeError("Error al crear archivo temporal.");
         cout << endl;
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
         Menu::setColor(7);
        cout << "Venta con ID " ;
         Menu::setColor(0);
        cout<< idVenta ;
         Menu::setColor(7);
        cout<<" eliminado correctamente." << endl;
    }
    else
    {

        remove("ventas_temp.dat");
         Menu::setColor(7);
        cout << "Venta con ID ";
         Menu::setColor(0);
        cout << idVenta;
         Menu::setColor(7);
        cout<< " no encontrado." << endl;
    }
}


void ArchivoVentas::exportarVentasACSV(string nombreArchivoCSV) {
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if (registro == nullptr) {
        Menu menu;
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        return;
    }

    ofstream archivoCSV(nombreArchivoCSV);
    if (!archivoCSV.is_open()) {
        Menu menu;
        menu.mensajeDeError("Error al crear el archivo CSV.");
        fclose(registro);
        return;
    }

    cout << "idVenta,idEmpleado,idCliente,formaDePago,importeTotal,estado" << endl;

    Venta venta;
    int cont = 0;
    while (fread(&venta, sizeof(Venta), 1, registro)) {

              cout << venta.getIdVenta() << ","
                   << venta.getIdEmpleado() << ","
                   << venta.getIdCliente() << ","
                   << venta.getFormaDePago() << ","
                   << venta.getImporteTotal() << ","
                   << venta.getEstado() << endl;

        cont++;
    }

    fclose(registro);
    archivoCSV.close();
}
