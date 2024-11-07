#include <iostream>
#include "Menu.h"
#include "rlutil.h"

using namespace std;
void cambiarFondo(int color);
int main()
{
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    Menu::setColor(7);
    system("cls");

    Menu menu;
    menu.getMainMenu();
    return 0;
}

