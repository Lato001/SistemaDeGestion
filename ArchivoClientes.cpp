

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>

#include "ArchivoClientes.h"
#include "ArchivoVentas.h"
#include "Cliente.h"
#include "rlutil.h"

#include "Menu.h"
#include "Modificaciones.h"

using namespace std;


ArchivoClientes::ArchivoClientes(string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoClientes::Guardar(Cliente cliente){
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL){
        return false;
    }
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoClientes::Guardar(Cliente cliente, int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL){
        return false;
    }
    fseek(registro, sizeof(Cliente) * posicion, SEEK_SET);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, registro);
    fclose(registro);
    return ok;
}

Cliente ArchivoClientes::Buscar(int clienteID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente, fallo;
    fallo.setClienteID(-1);
    if(registro == NULL){
        return fallo;
    }
    while(fread(&cliente, sizeof(cliente), 1, registro) == 1){
        if(cliente.getID() == clienteID){
            fclose(registro);
            return cliente;
        }
    }
    fclose(registro);
    return fallo;
}
int ArchivoClientes::BuscarPosRegistro(int clienteID){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente;
    if(registro == NULL){
        return -1;
    }
    int i = 0;
    while(fread(&cliente, sizeof(cliente), 1, registro) == 1){
        if(cliente.getID() == clienteID){
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}
void ArchivoClientes::FiltrarClientes(){
   FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente;
    Menu menu;
    int cont = 0;

    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron clientes." );
        return;
    }
    while (fread(&cliente, sizeof(cliente), 1, registro)) {
        cont++;
        cliente.mostrarCliente();
    }

    if (cont == 0) {
        menu.mensajeDeError("No se encontraron clientes en el archivo.");
    }

    fclose(registro);


}
void ArchivoClientes::FiltrarPorNombre(string _nombre){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
        menu.mensajeDeError("No se encontraron clientes." );
        return;
    }
    while(fread(&cliente, sizeof(cliente), 1, registro)){
        if(cliente.getNombre() == _nombre){
            fclose(registro);
            cliente.mostrarCliente();
            cont++;
        }
    }
    if(cont == 0){
        menu.mensajeDeError("No se encontraron clientes con el nombre: ");
        Menu::setColor(0);
        cout << _nombre<<endl;
        Menu::setColor(7);    }
    fclose(registro);

}
void ArchivoClientes::FiltrarPorOrdenAlfabetico()
{
    FILE *registroA = fopen(_nombreArchivo.c_str(), "rb");
    int cantRegistros = ArchivoClientes::CantidadRegistros();
    Cliente* registro = new Cliente[cantRegistros];

    Cliente cliente;
    Menu menu;

    if (registroA == nullptr)
    {
        menu.mensajeDeError("No se han encontrado clientes registrados");
        return;
    }

    if (cantRegistros != 0)
    {
        for (int i = 0; i < cantRegistros; i++)
        {
            registro[i] = ArchivoClientes::Leer(i);  // Asegúrate de que Leer(i) devuelve el cliente correcto
        }

        // Ordenamiento alfabético usando burbuja
        for (int i = 0; i < cantRegistros - 1; i++)
        {
            for (int j = i + 1; j < cantRegistros; j++)
            {
                if (strcmp(registro[i].getApellido(), registro[j].getApellido()) > 0)
                {
                    Cliente temp = registro[i];
                    registro[i] = registro[j];
                    registro[j] = temp;
                }
            }
        }

        // Mostrar los clientes ordenados
        for (int i = 0; i < cantRegistros; i++)
        {
            registro[i].mostrarCliente();
        }
    }

    delete[] registro;
    fclose(registroA);
}

void ArchivoClientes::FiltrarPorID(int _ID){

FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Cliente cliente;
    Menu menu;
    int cont = 0;
    if (registro == nullptr) {
       menu.mensajeDeError("No se encontraron clientes.") ;
        return;
    }
    while(fread(&cliente, sizeof(cliente), 1, registro)){
        if(cliente.getID() == _ID){
            fclose(registro);
            cliente.mostrarCliente();
            cont++;
        }
    }
    if(cont == 0){
       menu.mensajeDeError("No se encontraron clientes con el ID: ");
       Menu::setColor(0);
    cout << _ID<<endl;
       Menu::setColor(7);
    }
    fclose(registro);

}
void ArchivoClientes::FiltrarPorNComprasRealizadas(){

  ArchivoVentas ventas("ArchivoVentas.dat");
    ArchivoClientes clientes("ArchivoClientes.dat");

    const int nClientes = clientes.CantidadRegistros();

    vector<int> clientesContNComprasArr(nClientes, 0);

    for (int i = 0; i < ventas.CantidadRegistros(); i++) {
        Venta venta = ventas.Leer(i);
        int posCliente = clientes.BuscarPosRegistro(venta.getIdCliente());

        if (posCliente >= 0 && posCliente < nClientes) {
            clientesContNComprasArr[posCliente]++;
        }
    }

    for (int i = 0; i < nClientes; i++) {
        if (clientesContNComprasArr[i] > 0) {
            Cliente cliente = clientes.Leer(i);
       Menu::setColor(7);
            cout << "El cliente: "<<endl;
       Menu::setColor(0);
            cliente.mostrarCliente();
       Menu::setColor(7);
            cout<<"ha realizado: ";
       Menu::setColor(0);
            cout << clientesContNComprasArr[i] ;
       Menu::setColor(7);
            cout << " compras." << endl;
        }
    }

}

Cliente ArchivoClientes::Leer(int posicion){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return Cliente();
    }
    Cliente cliente;
    fseek(registro, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, registro);
    fclose(registro);
    return cliente;
}

int ArchivoClientes::CantidadRegistros(){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Cliente);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoClientes::Leer(int CantidadRegistros, Cliente *vector){
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL){
        return;
    }
    for(int i = 0; i < CantidadRegistros; i++){
        fread(&vector[i], sizeof(Cliente), 1, registro);
    }
    fclose(registro);
}

void ArchivoClientes::ModificarCliente(int clienteID, int atributo)
{
    Menu menu;
    Modificaciones modifica;
    int pos = BuscarPosRegistro(clienteID);
    if (pos == -1)
    {

        menu.mensajeDeError("Cliente no encontrado.");
        return;
    }
    Cliente cliente = Leer(pos);

    switch (atributo)
    {
    case 1:
    {
        int nuevoDNI;
        cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
        cout << "Ingrese nuevo DNI: ";
        cin >> nuevoDNI;
        if (nuevoDNI == 0 )
        {
            system("cls");
            return;
        }
        cliente.setDNI(nuevoDNI);
    break;
    }
    case 2:
    {
        char nuevoNombre[50];
        cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
        cout << "Ingrese nuevo nombre: ";
        cin.ignore();
        cin.getline(nuevoNombre, 50);
        if (strcmp(nuevoNombre, "0") == 0)
        {
            system ("cls");
            return;
        }
        cliente.setNombre(nuevoNombre);
    break;
    }
    case 3:
    {
        char nuevoApellido[50];
        cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
        cout << "Ingrese nuevo apellido: ";
        cin.ignore();
        cin.getline(nuevoApellido, 50);
        if (strcmp(nuevoApellido, "0") == 0)
        {
            system ("cls");
            return;
        }
        cliente.setApellido(nuevoApellido);
        break;
    }
    case 4:
    {
        char nuevoEmail[50];
        cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
        cout << "Ingrese nuevo email: ";
        cin.ignore();
        cin.getline(nuevoEmail, 50);
        if (strcmp(nuevoEmail, "0") == 0)
        {
            system ("cls");
            return;
        }
        cliente.setEmail(nuevoEmail);
        break;
    }
    case 5:
    {
        int nuevonTelefono;
        cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
        cout << "Ingrese nuevo número de teléfono: ";
        cin.ignore();
        cin>>nuevonTelefono;
        if (nuevonTelefono == 0)
        {
            system ("cls");
            return;
        }
        cliente.setnTelefono(nuevonTelefono);
        break;
    }
    case 6:
    {
        char nuevaLocalidad[50];
        cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
        cout << "Ingrese nueva localidad: ";
        cin.ignore();
        cin.getline(nuevaLocalidad, 50);
        if (strcmp(nuevaLocalidad, "0") == 0)
        {
            system ("cls");
            return;
        }
        cliente.setLocalidad(nuevaLocalidad);
        break;
    }
    default:
        menu.mensajeDeError("Atributo no válido.");
        return;
        break;
    }


    if (Guardar(cliente, pos))
    {
        menu.setColor(2);
        cout << "Datos del cliente actualizados." << endl;
        menu.setColor(7);
    }
    else
    {

        menu.mensajeDeError("Error al actualizar los datos del cliente.");
    }
}

void ArchivoClientes::eliminarArchivoClientes()
{
    Menu menu;
    menu.setColor(7);
    string nombre, aux;
    ifstream salida;
    salida.open("ArchivoClientes.dat", ios::in);
    ofstream entrada;
    entrada.open("temp.dat", ios::out);

    if (salida.fail())
    {
        menu.mensajeDeError("Hubo un error al abrir el archivo ArchivoClientes.dat");
        cout << endl;
        cin.get();
        exit(0);
    }
    else
    {

        salida.close();
        entrada.close();

        remove("ArchivoClientes.dat");  // Eliminar el archivo original
        rename("temp.dat", "ArchivoClientes.dat");  // Renombrar el archivo temporal a "ArchivoEmpleados.dat"
        Menu::setColor(2);
        cout<<"Registros del archivo eliminados"<<endl;
        Menu::setColor(7);
    }
}
void ArchivoClientes::eliminarRegistroCliente(int clienteID)
{
    Menu menu;
string nombreCliente;
    FILE* archivoOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if (archivoOriginal == nullptr)
    {
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        return;
    }

    FILE* archivoTemporal = fopen("clientes_temp.dat", "wb");
    if (archivoTemporal == nullptr)
    {
        menu.mensajeDeError("Error al crear archivo temporal.");
        fclose(archivoOriginal);
        return;
    }

    Cliente cliente;
    bool encontrado = false;


    while (fread(&cliente, sizeof(Cliente), 1, archivoOriginal))
    {
        if (cliente.getID() != clienteID)
        {

            fwrite(&cliente, sizeof(Cliente), 1, archivoTemporal);
        }
        else
        {
            nombreCliente = cliente.getNombre();
            encontrado = true;
        }
    }


    fclose(archivoOriginal);
    fclose(archivoTemporal);


    if (encontrado)
    {
        remove(_nombreArchivo.c_str());
        rename("clientes_temp.dat", _nombreArchivo.c_str());
        Menu::setColor(7);
        cout << "Cliente con ID: " ;
        Menu::setColor(0);
        cout << clienteID ;
        Menu::setColor(7);        cout <<" y con nombre: ";
        Menu::setColor(0);
        cout << nombreCliente ;
        Menu::setColor(7);
        cout << " eliminado correctamente." << endl;
    }
    else
    {

        remove("clientes_temp.dat");
        cout << "Cliente con ID " ;
        Menu::setColor(0);
        cout<< clienteID ;
        Menu::setColor(7);
        cout<< " no encontrado." << endl;
    }
}

void ArchivoClientes::exportarClientesACSV(string nombreArchivoCSV) {
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if (registro == nullptr)
    {
        Menu menu;
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        return;
    }

    ofstream archivoCSV(nombreArchivoCSV);
    if (!archivoCSV.is_open())
    {
        Menu menu;
        menu.mensajeDeError("Error al crear el archivo CSV.");
        fclose(registro);
        return;
    }

    int cont = 0;
    Cliente cliente;
        archivoCSV << "   -------------Datos de Clientes----------------"<<endl;
    while (fread(&cliente, sizeof(Cliente), 1, registro))
    {
        Menu::setColor(7);
        archivoCSV << "DNI: " << cliente.getDNI() <<endl;
        archivoCSV << "NOMBRE: " <<cliente.getNombre() <<endl;
        archivoCSV << "APELLIDO: " <<cliente.getApellido() <<endl;
        archivoCSV << "EMAIL: " <<cliente.getEmail() <<endl;
        archivoCSV << "NUMERO DE TELEFONO: " <<cliente.getnTelefono() << endl;
        archivoCSV << "LOCALIDAD: " <<cliente.getLocalidad() << endl;
        archivoCSV << endl;
        archivoCSV << "-----------------------------------------------------" << endl;
        archivoCSV << endl;

        cout << "DNI:"<< cliente.getDNI()<< endl;
        cout <<"APELLIDO:"<< cliente.getApellido()<< endl;
        cout <<"EMAIL:"<< cliente.getEmail()<< endl;
        cout <<"TELEFONO:"<< cliente.getnTelefono()<< endl;
        cout <<"LOCALIDAD:" << cliente.getLocalidad() << endl;
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << endl;
        cont++;
    }
    fclose(registro);
    archivoCSV.close();

    cout << "Se exportaron " << cont << " Clientes al archivo CSV." << endl;
}
