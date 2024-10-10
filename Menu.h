#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Persona.h"

class Menu{
public:
    void getMainMenu();
    void listarVentas();
    void listarEmpleados();
    void EjecutarFuncion(int opcionElegida, bool &exit);
    void InterfazCrearUsuario();

};

#endif // MENU_H_INCLUDED
