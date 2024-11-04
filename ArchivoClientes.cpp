#pragma once
#include <string>
#include <cstring>
#include <iostream>

#include "ArchivoClientes.h"
#include "Cliente.h"
#include "Menu.h"

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

Cliente ArchivoClientes::Buscar(int clienteID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente, fallo;
    fallo.setClienteID(-1);
    if(registro == NULL){
        return fallo;
    }
    int i = 0;
    while(fread(&cliente, sizeof(cliente), 1, registro) == 1){
        if(cliente.getID() == clienteID){
            fclose(registro);
            return cliente;
        }
        i++;
    }
    fclose(registro);
    return fallo;
}
void ArchivoClientes::FiltrarClientes(){
   FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente;
    int cont = 0;

    if (registro == nullptr) {
        cout << "No se encontraron clientes." << endl;
        return;
    }
    while (fread(&cliente, sizeof(cliente), 1, registro)) {
        cont++;
        cout << cont << ". ";
        cliente.mostrarCliente();
    }

    if (cont == 0) {
        cout << "No se encontraron clientes en el archivo." << endl;
    }

    fclose(registro);


}
void ArchivoClientes::FiltrarPorNombre(string _nombre){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente;
    int cont = 0;
    if (registro == nullptr) {
        cout << "No se encontraron clientes." << endl;
        return;
    }
    while(fread(&cliente, sizeof(cliente), 1, registro)){
        if(cliente.getNombre() == _nombre){
            fclose(registro);
            cliente.mostrarCliente();
            cont++;
        }
    }
    if(cont == 0){
        cout<< "No se encontraron clientes con el nombre: " << _nombre<<endl;
    }
    fclose(registro);

}
void ArchivoClientes::FiltrarPorOrdenAlfabetico()
{
    FILE *registroA = fopen(_nombreArchivo.c_str(), "rb");
    int cantRegistros = ArchivoClientes::CantidadRegistros();
    Cliente* registro = new Cliente[cantRegistros];

    Cliente cliente;
    Menu menu;

    if(registroA == nullptr)
    {
            menu.setColor(4);
        cout<< "No se han encontrado clientes registrados" << endl;
            menu.setColor(7);
            return;
    }
    if (cantRegistros != 0)
    {
        for (int i = 0; i < cantRegistros; i++ )
        {
            registro[i] = ArchivoClientes::Leer(i);
        }
        for (int i = 0; i <= cantRegistros ; i++)
        {
            for (int j = 0; j <= cantRegistros ; j++)
            {
                if (strcmp (registro[j].getNombre(),registro[i].getNombre()) > 0)
                {
                    Cliente temp = registro[i];
                    registro[i] = registro[j];
                    registro[j] = temp;
                }
            }
        }
        for ( int i = 0 ; i <=cantRegistros ; i++ )
        {
        registro[i].mostrarCliente();
        }
    }
    delete[] registro;
    fclose(registroA);
}

void ArchivoClientes::FiltrarPorID(int _ID){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente;
    int cont = 0;
    if (registro == nullptr) {
        cout << "No se encontraron clientes." << endl;
        return;
    }
    while(fread(&cliente, sizeof(cliente), 1, registro)){
        if(cliente.getID() == _ID){
            fclose(registro);
            cliente.mostrarCliente();
            cont++;
        }
    }
    if(cont == 0){
        cout<< "No se encontraron clientes con el ID: " << _ID<<endl;
    }
    fclose(registro);

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

