#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;

#include "DetalleVenta.h"
#include "Producto.h"
#include "ArchivoProductos.h"
#include "Menu.h"

Producto::Producto()
{
    productoID = 0;
    nombreProducto[0] = '\0';
    categoriaProducto[0] = '\0';
    precioUnitario = 0;
    stock = 0;
}

Producto::Producto(int _productoID, const char* _nombreProducto, float _precioUnitario, int _stock, const char* _categoriaProducto)
{

    productoID = _productoID;


    strncpy(nombreProducto, _nombreProducto, sizeof(nombreProducto) - 1);
    nombreProducto[sizeof(nombreProducto) - 1] = '\0';

    precioUnitario = _precioUnitario;

    stock = _stock;

    strncpy(categoriaProducto, _categoriaProducto, sizeof(categoriaProducto) - 1);
    categoriaProducto[sizeof(categoriaProducto) - 1] = '\0';

}

int Producto::getProductoID() { return productoID; }
const char* Producto::getNombre() { return nombreProducto; }
const char* Producto::getCategoriaProducto() { return categoriaProducto; }
float Producto::getPrecioUnitario() { return precioUnitario; }
int Producto::getStock() { return stock; }

void Producto::setProductoID(int _productoID) { productoID = _productoID; }


void Producto::setNombre(const char* _nombreProducto) {
    strncpy(nombreProducto, _nombreProducto, sizeof(nombreProducto) - 1);
    nombreProducto[sizeof(nombreProducto) - 1] = '\0';
}

void Producto::setCategoriaProducto(const char* _categoriaProducto) {
    strncpy(categoriaProducto, _categoriaProducto, sizeof(categoriaProducto) - 1);
    categoriaProducto[sizeof(categoriaProducto) - 1] = '\0';
}

void Producto::setPrecioUnitario(float _PrecioUnitario) { precioUnitario = _PrecioUnitario; }

void Producto::setStock(int _stock) { stock = _stock; }


void Producto::cargarProducto()
{
    ArchivoProductos Productos("ArchivoProductos.dat");

    int inputProductoID;
    char inputNombreProducto[50];
    char inputCategoriaProducto[50];
    float inputPrecioUnitario;
    int inputStock;

    productoID = Productos.CantidadRegistros() + 1;

    cin.ignore();
    Menu::setColor(7);
    cout << "Ingrese el nombre del Producto: ";
    Menu::setColor(0);
    cin.getline(inputNombreProducto, 50);
    setNombre(inputNombreProducto);
    system("pause");
    system("cls");

    Menu::setColor(7);
    cout << "Ingrese la categoria del Producto: ";
    Menu::setColor(0);
    cin.getline(inputCategoriaProducto, 50);
    setCategoriaProducto(inputCategoriaProducto);
    system("pause");
    system("cls");

    Menu::setColor(7);
    cout << "Ingrese el precio del Producto: ";
    Menu::setColor(0);
    cin >> inputPrecioUnitario;
    setPrecioUnitario(inputPrecioUnitario);
    system("pause");
    system("cls");

    Menu::setColor(7);
    cout << "Ingrese el stock del Producto: ";
    Menu::setColor(0);
    cin >> inputStock;
    setStock(inputStock);
    system("pause");
    system("cls");

}
void Producto::mostrarProducto()
{
    Menu menu;
    Menu::setColor(3);
    cout << "////////////////// ID PRODUCTO: " << getProductoID() << " //////////////////" << endl;
   Menu::setColor(7);
    cout << "Nombre del Producto: ";
    menu.setColor(0);
    cout<< getNombre() << endl;
    menu.setColor(7);
    cout << "Categoria del Producto: ";
    menu.setColor(0);
    cout << getCategoriaProducto() << endl;
    menu.setColor(7);
    cout << "Precio Unitario: ";
    menu.setColor(0);
    cout << getPrecioUnitario() << endl;
    menu.setColor(7);
    cout << "Stock: ";
    menu.setColor(0);
    cout << getStock() << endl;
    menu.setColor(3);
    cout << "////////////////////////////////////////////////////" << endl << endl;
    Menu::setColor(7);
}
