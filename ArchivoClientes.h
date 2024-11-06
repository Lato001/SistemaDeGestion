#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED

#include "Persona.h"
#include "Cliente.h"

using namespace std;

class ArchivoClientes {
private:
        string _nombreArchivo;

    public:
        ArchivoClientes(string nombreArchivo);
        bool Guardar(Cliente cliente);
        bool Guardar(Cliente cliente, int posicion);
        Cliente Buscar(int clienteID);
        int BuscarPosRegistro(int clienteID);
        void FiltrarClientes();
        void FiltrarPorNombre(string _nombre);
        void FiltrarPorOrdenAlfabetico();
        void FiltrarPorID(int _ID);
        void FiltrarPorNComprasRealizadas();
        void ModificarCliente(int clienteID);
        Cliente Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, Cliente *vector);
};

#endif // ARCHIVOCLIENTES_H_INCLUDED
