#ifndef ARCHIVOCOMPRADORES_H_INCLUDED
#define ARCHIVOCOMPRADORES_H_INCLUDED

#include "Persona.h"
#include "Comprador.h"

using namespace std;

class ArchivoClientes {
private:
        string _nombreArchivo;

    public:
        ArchivoClientes(string nombreArchivo);
        bool Guardar(Cliente cliente);
        bool Guardar(Cliente cliente, int posicion);
        int Buscar(int clienteID);
        Cliente Leer(int posicion);
        int CantidadRegistros();
        void Leer(int Cliente, *vector);
};

#endif // ARCHIVOCOMPRADORES_H_INCLUDED
