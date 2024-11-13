#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <conio.h>

#include "ArchivoProductos.h"
#include "Producto.h"
#include "rlutil.h"
#include "Menu.h"
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

Producto ArchivoProductos::Buscar(int productoID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Producto producto, fallo;
    fallo.setProductoID(-1);
    if(registro == NULL){
        return fallo;
    }
    while(fread(&producto, sizeof(producto), 1, registro)){
        if(producto.getID() == productoID){
            fclose(registro);
            return producto;
        }
    }
    fclose(registro);
    return fallo;
}

void ArchivoProductos::FiltrarProductos()
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Producto producto;
    Menu menu;
    int cont = 0;

    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron productos.");
        return;
    }
    while (fread(&producto, sizeof(producto), 1, registro))
    {
        cont++;
        producto.mostrarProducto();
    }

    if (cont == 0)
    {
        menu.mensajeDeError("No se encontraron productos en el archivo.");
    }

    fclose(registro);
}
void ArchivoProductos::FiltrarPorNombre(string _nombre){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Producto producto;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron productos." );
        return;
    }
    while(fread(&producto, sizeof(producto), 1, registro))
    {
        if(producto.getNombre() == _nombre){
            fclose(registro);
            producto.mostrarProducto();
            cont++;
        }
    }
    if(cont == 0){
        menu.mensajeDeError("No se encontraron productos con el nombre: ");
        cout << _nombre<<endl;
    }
    fclose(registro);

}

void ArchivoProductos::FiltrarPorID(int _productoID)
{
FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Producto producto;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron productos." );
        return;
    }
    while(fread(&producto, sizeof(producto), 1, registro)){
        if(producto.getID() == _productoID)
        {
            producto.mostrarProducto();
            cont++;
        }
    }
    if(cont == 0){
        menu.mensajeDeError("No se encontraron productos con el ID: ");
        cout<< _productoID<<endl;
    }
    fclose(registro);
}

void ArchivoProductos::FiltrarPorCategoria (string _categoria)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Producto producto;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron categorias de productos" );
        return;
    }
    while(fread(&producto, sizeof(producto), 1, registro)){
        if(producto.getCategoriaProducto() == _categoria)
        {
            producto.mostrarProducto();
            cont++;
        }
    }
    if(cont == 0){
        menu.mensajeDeError("No se encontro esa categoria. ");
    }
    fclose(registro);
}

int ArchivoProductos::BuscarPos(int productoID)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Producto producto;
    int posicion = 0;

    if (registro == NULL)
    {
        return -1;
    }

    while (fread(&producto, sizeof(producto), 1, registro))
    {
        if (producto.getID() == productoID)
        {
            fclose(registro);
            return posicion;
        }
        posicion++;
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

void ArchivoProductos::ModificarProducto(int productoID, int atributo)
{
    Menu menu;
    int pos = BuscarPos(productoID);
    if (pos == -1) {

         menu.mensajeDeError("Producto no encontrado.") ;
         cout << endl;
        return;
        }

    Producto producto = Leer(pos);

    switch (atributo)
    {
    case 1:
        ///NOMBRE
        char nuevoNombreProducto[50];
         menu.setColor(7);
        cout << "Ingrese el nuevo nombre: ";
         menu.setColor(0);
        cin.ignore();
        cin.getline(nuevoNombreProducto, 50);
        producto.setNombre(nuevoNombreProducto);
        break;
    case 2:
        ///CATEGORIA
        char nuevoNombreCategoria[50];
         menu.setColor(7);
            cout << "Ingrese el nuevo nombre de Categoria: ";
             menu.setColor(0);
            cin.ignore();
            cin.getline(nuevoNombreCategoria, 50);
            producto.setNombre(nuevoNombreCategoria);
        break;
    case 3:
        ///PRECIO UNITARIO
        float nuevoPrecioUnitario;
         menu.setColor(7);
        cout<<"Ingrese el nuevo importe unitario: ";
         menu.setColor(0);
        cin >> nuevoPrecioUnitario;
        producto.setPrecioUnitario(nuevoPrecioUnitario);
        break;
    case 4:
        ///STOCK
        int nuevoStock;
         menu.setColor(7);
        cout<<"Ingrese el stock actual: ";
         menu.setColor(0);
        cin >> nuevoStock;
        producto.setStock(nuevoStock);
        break;


    default:
        menu.mensajeDeError("Atributo no válido.");
        return;
        break;
    }

    if (Guardar(producto, pos)) {
            menu.setColor(2);
        cout << "Datos del producto actualizados." << endl;
        menu.setColor(7);
    } else {

        menu.mensajeDeError("Error al actualizar los datos del producto.");
        cout  << endl;
    }
}

void ArchivoProductos::eliminarArchivoProductos()
{
    Menu menu;
    menu.setColor(7);
    string nombre, aux;
    ifstream salida;
    salida.open("ArchivoProductos.dat", ios::in);
    ofstream entrada;
    entrada.open("temp.dat", ios::out);

    if (salida.fail())
    {
        menu.mensajeDeError("Hubo un error al abrir el archivo ArchivoProductos.dat");
       cout << endl;
        cin.get();
        exit(0);
    }
    else
    {

        salida.close();
        entrada.close();

        remove("ArchivoProductos.dat");  // Eliminar el archivo original

        rename("temp.dat", "ArchivoProductos.dat");  // Renombrar el archivo temporal a "ArchivoVentas.dat"
        Menu::setColor(2);
        cout<<"Registros del archivo Productos eliminados"<<endl;
        Menu::setColor(7);
    }
}
void ArchivoProductos::eliminarRegistroProducto(int productoID)
{
    Menu menu;
    string nombreProducto;
    FILE* archivoOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if (archivoOriginal == nullptr)
    {
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        cout << endl;
        return;
    }

    FILE* archivoTemporal = fopen("productos_temp.dat", "wb");
    if (archivoTemporal == nullptr)
    {
      menu.mensajeDeError("Error al crear archivo temporal.");
      cout << endl;
        fclose(archivoOriginal);
        return;
    }

    Producto producto;
    bool encontrado = false;


    while (fread(&producto, sizeof(Producto), 1, archivoOriginal))
    {
        if (producto.getID() != productoID)
        {

            fwrite(&producto, sizeof(Producto), 1, archivoTemporal);
        }
        else
        {
            nombreProducto = producto.getNombre();
            encontrado = true;
        }
    }


    fclose(archivoOriginal);
    fclose(archivoTemporal);


    if (encontrado)
    {
        remove(_nombreArchivo.c_str());
        rename("productos_temp.dat", _nombreArchivo.c_str());
        menu.setColor(7);
        cout << "Producto con ID " ;
        menu.setColor(0);
        cout << productoID;

        menu.setColor(7);
        cout <<" y con nombre " ;
        menu.setColor(0);
        cout<< nombreProducto ;
        menu.setColor(7);
        cout<< " eliminado correctamente." ;
        cout << endl;
    }
    else
    {

        remove("productos_temp.dat");
        cout << "Producto con ID ";
        menu.setColor(0);
        cout << productoID ;
        menu.setColor(7);
        cout << " no encontrado." ;
        cout << endl;
    }
}


void ArchivoProductos::exportarProductosACSV(string nombreArchivoCSV)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if (registro == nullptr)
    {
        Menu menu;
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        return;
    }

    ofstream archivoCSV(nombreArchivoCSV);
    if (!archivoCSV.is_open())
    {
        Menu menu;
        menu.mensajeDeError("Error al crear el archivo CSV.");
        fclose(registro);
        return;
    }

    int cont = 0;
    Producto producto;
//  Lee en binario y escibe en CSV
    while (fread(&producto, sizeof(Producto), 1, registro))
    {
        Menu::setColor(7);
//      Escribe los datos en el archivo .csv
        archivoCSV << "ID:" << producto.getID() <<endl;
        archivoCSV << "NOMBRE: " <<producto.getNombre() <<endl;
        archivoCSV << "CATEGORIA: " <<producto.getCategoriaProducto() <<endl;
        archivoCSV << "PRECIO UNITARIO: " <<producto.getPrecioUnitario() <<endl;
        archivoCSV << "STOCK: " <<producto.getStock() << endl;
        archivoCSV << endl;
        archivoCSV << "-----------------------------------------------------" << endl;
        archivoCSV << endl;

        cout << "ID:";
        Menu::setColor(0);
        cout << producto.getID();
        Menu::setColor(7);
        cout << endl;
        cout <<"NOMBRE:";
        Menu::setColor(0);
        cout << producto.getNombre();
        cout << endl;
        Menu::setColor(7);
        cout <<"CATEGORIA:";
        Menu::setColor(0);
        cout << producto.getCategoriaProducto();
        cout << endl;
        Menu::setColor(7);
        cout <<"PRECIO UNITARIO:";
        Menu::setColor(0);
        cout << producto.getPrecioUnitario();
        cout << endl;
        Menu::setColor(7);
        cout <<"STOCK:" ;
        Menu::setColor(0);
        cout << producto.getStock();
        Menu::setColor(7);
        cout << endl;
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << endl;
        cont++;
    }
    fclose(registro);
    archivoCSV.close();
    Menu::setColor(2);
    cout << "Se exportaron " << cont << " productos al archivo CSV." << endl;
    Menu::setColor(7);
}
