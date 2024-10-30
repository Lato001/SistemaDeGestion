#include <iostream>
#include "Menu.h"
#include "rlutil.h"

using namespace std;
void cambiarFondo(int color);
int main()
{
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    system("cls");

    Menu menu;
    menu.getMainMenu();
    return 0;
}

