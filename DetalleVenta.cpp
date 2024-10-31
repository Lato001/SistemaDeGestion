#include <iostream>
using namespace std;
#include "DetalleVenta.h"
#include "ArchivoProductos.h"
DetalleVenta::DetalleVenta()
{
    productoID = 0;
    cantidadProducto = 0;
}
DetalleVenta::DetalleVenta(int _productoID, int _cantidadProducto)
{
    productoID = _productoID;
    cantidadProducto = _cantidadProducto;
}

    int DetalleVenta :: getProductoID(){return productoID;}
    int DetalleVenta :: getCantidadProducto(){return cantidadProducto;}

    void DetalleVenta :: setProductoID(int _productoID){productoID = _productoID;}
    void DetalleVenta :: setCantidadProducto(int _cantidadProducto){cantidadProducto = _cantidadProducto;}

    void DetalleVenta :: cargarDetalleDeVenta(){
        ArchivoProductos Productos("ArchivoProductos.dat");
        Producto registro;
        int posReg, input;



        bool opcionValida = false;
        while(!opcionValida){
            for (int i = 0 ; i < Productos.CantidadRegistros();i++ ){
            registro = Productos.Leer(i);
             cout<< "i";
             registro.mostrarProducto();
             cout<< endl;
            }
        cout<< "Ingrese la opcion deseada: ";
        cin >> posReg;
            if(posReg > -1 && posReg < Productos.CantidadRegistros()){
                opcionValida = true;
                productoID = Productos.Leer(posReg).getProductoID();
            }else{
                cout << "Opcion invalida, vuelva a intentarlo"<<endl;
            }
        system("pause");
        system("cls");
        }

        opcionValida = false;
        while(!opcionValida){
            cout<< "Stock Disponible: " << Productos.Leer(posReg).getStock()<<endl<<endl;
            cout<< "Ingrese la cantidad comprada del producto: " << endl;
            cin>> input;
        if(input >0  && input <= Productos.Leer(posReg).getStock()){
            opcionValida = true;
            cantidadProducto = input;
            Productos.Leer(posReg).setStock( 0);
        }else{
            cout << "Opcion invalida! Vuelva a intentarlo"<<endl;
            system("pause");
            system("cls");


        }



    }}
    void DetalleVenta :: mostrarDetalleDeVenta(){
    cout<< "ID DEL PRODUCTO: " << getProductoID()<<endl;
    cout<< "CANTIDAD DEL PRODUCTO: " << getCantidadProducto()<<endl;
    }
