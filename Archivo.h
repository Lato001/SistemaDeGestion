#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "Persona.h"

using namespace std;

class ArchivoPersona {
private:
        string _nombreArchivo;

    public:
        ArchivoPersona(string nombreArchivo);

        bool Guardar(Persona persona);
        bool Guardar(Persona persona, int posicion);
        int Buscar(int DNI);
        ArchivoPersona Leer(int posicion);
        int CantidadRegistros();
        int registro;
        void Leer(int cantidadRegistros, ArchivoPersona *vector);
};

#endif // ARCHIVO_H_INCLUDED
