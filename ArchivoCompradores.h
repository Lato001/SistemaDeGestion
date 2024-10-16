#ifndef ARCHIVOCOMPRADORES_H_INCLUDED
#define ARCHIVOCOMPRADORES_H_INCLUDED

#include "Persona.h"
#include "Comprador.h"

using namespace std;

class ArchivoCompradores {
private:
        string _nombreArchivo;

    public:
        ArchivoCompradores(string nombreArchivo);
        bool Guardar(Comprador comprador);
        bool Guardar(Comprador comprador, int posicion);
        int Buscar(int compradorID);
        Comprador Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Comprador *vector);
};

#endif // ARCHIVOCOMPRADORES_H_INCLUDED
