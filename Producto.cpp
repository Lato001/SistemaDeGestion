#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;

#include "Producto.h"
#include "ArchivoProductos.h"

Producto::Producto()
{
    productoID = 0;
    idLineaP = 0;
    nombreProducto[0] = '\0';
    categoriaProducto[0] = '\0';
    precioUnitario = 0;
    stock = 0;
}

Producto::Producto(int _productoID, int _idLineaP, const char* _nombreProducto, float _precioUnitario, int _stock, const char* _categoriaProducto)
{
    productoID = _productoID;

    idLineaP = _idLineaP;

    strncpy(nombreProducto, _nombreProducto, sizeof(nombreProducto) - 1);
    nombreProducto[sizeof(nombreProducto) - 1] = '\0';

    strncpy(categoriaProducto, _categoriaProducto, sizeof(categoriaProducto) - 1);
    categoriaProducto[sizeof(categoriaProducto) - 1] = '\0';

    precioUnitario = _precioUnitario;
    stock = _stock;
}

int Producto::getProductoID() { return productoID; }
int Producto::getIdLineaP() { return idLineaP; }
const char* Producto::getNombre() { return nombreProducto; }
const char* Producto::getCategoriaProducto() { return categoriaProducto; }
float Producto::getPrecioUnitario() { return precioUnitario; }
int Producto::getStock() { return stock; }

void Producto::setProductoID(int _productoID) { productoID = _productoID; }

void Producto::setIdLineaP(int _idLineaP) { idLineaP = _idLineaP; }

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
    rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el nombre del Producto: ";
    rlutil::setColor(rlutil::WHITE);
    cin.getline(inputNombreProducto, 50);
    setNombre(inputNombreProducto);
    system("pause");
    system("cls");

    rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese la categoria del Producto: ";
    rlutil::setColor(rlutil::WHITE);
    cin.getline(inputCategoriaProducto, 50);
    setCategoriaProducto(inputCategoriaProducto);
    system("pause");
    system("cls");

    rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el precio del Producto: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> inputPrecioUnitario;
    setPrecioUnitario(inputPrecioUnitario);
    system("pause");
    system("cls");

    rlutil::setColor(rlutil::BLACK);
    cout << "Ingrese el stock del Producto: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> inputStock;
    setStock(inputStock);
    system("pause");
    system("cls");

}
void Producto::mostrarProducto()
{
    rlutil::setColor(rlutil::CYAN);
    cout << "////////////////// ID PRODUCTO: " << getProductoID() << " //////////////////" << endl;
   rlutil::setColor(rlutil::BLACK);
    cout << "Nombre del Producto: " << getNombre() << endl;
    cout << "Categoría del Producto: " << getCategoriaProducto() << endl;
    cout << "Precio Unitario: " << getPrecioUnitario() << endl;
    cout << "Stock: " << getStock() << endl;
    cout << "////////////////////////////////////////////////////" << endl << endl;
    rlutil::setColor(rlutil::WHITE);
}
