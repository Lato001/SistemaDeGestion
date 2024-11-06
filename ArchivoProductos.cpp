#pragma once
#include <string>
#include <cstring>

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
        if(producto.getProductoID() == productoID){
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
        if(producto.getProductoID() == _productoID)
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
        if (producto.getProductoID() == productoID)
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

void ArchivoProductos::ModificarProducto(int productoID) {
    int pos = BuscarPos(productoID);
    if (pos == -1) {
            Menu::setColor(4);
        cout << "Producto no encontrado." << endl;
        return;
        }
    Producto producto = Leer(pos);
    int idOriginal = producto.getProductoID();
    producto.cargarProducto();
    producto.setProductoID(idOriginal);
    if (Guardar(producto, pos)) {
            Menu::setColor(7);
        cout << "Datos del producto actualizados." << endl;
    } else {
        Menu::setColor(4);
        cout << "Error al actualizar los datos del producto." << endl;
    }
}

