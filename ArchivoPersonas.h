#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "Persona.h"

using namespace std;

class ArchivoPersonas {
private:
        string _nombreArchivo;

    public:
        ArchivoPersonas(string nombreArchivo);
        bool Guardar(Persona persona);
        bool Guardar(Persona persona, int posicion);
        int Buscar(int DNI);
        Persona Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Persona *vector);
};

#endif // ARCHIVO_H_INCLUDED
