#include <iostream>
#include "Menu.h"
#include "windows.h"

using namespace std;
void cambiarFondo(int color);
int main()
{
   cambiarFondo(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    Menu menu;
    menu.getMainMenu();
    return 0;
}

void cambiarFondo(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    SetConsoleTextAttribute(hConsole, color);


    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);


    for (int i = 0; i < csbi.srWindow.Bottom; i++) {
        for (int j = 0; j < csbi.srWindow.Right; j++) {
            std::cout << " ";
        }
    }


    SetConsoleCursorPosition(hConsole, {0, 0});
}
