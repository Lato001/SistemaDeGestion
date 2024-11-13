#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <conio.h>

#include "ArchivoEmpleados.h"
#include "Empleado.h"
#include "Menu.h"
#include "rlutil.h"
#include "Fecha.h"

using namespace std;


ArchivoEmpleados::ArchivoEmpleados(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoEmpleados::Guardar(Empleado empleado)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "ab");
    if(registro == NULL)
void ArchivoEmpleados::ModificarEmpleado(int empleadoID, int atributo)
{
    Menu menu;
    Modificaciones modifica;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");

    int pos = BuscarPosRegistro(empleadoID);
    if (pos == -1)
    {

        menu.mensajeDeError("Empleado no encontrado." );
        cout << endl;
        return;
    }

    Empleado empleado = Leer(pos);

    switch (atributo)
    {
    case 1:
    {
        int nuevoDNI;
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "Ingrese nuevo DNI: ";
            Menu::setColor(0);
            cin >> nuevoDNI;
            Menu::setColor(7);
            if (nuevoDNI == 0)
        {
            system ("cls");
            modifica.modificarEmpleado();
        }
            empleado.setDNI(nuevoDNI);
            break;
    }
    case 2:
        {
            char nuevoNombre[50];
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "Ingrese nuevo nombre: ";
            Menu::setColor(0);
            cin.ignore();
            cin.getline(nuevoNombre, 50);
            Menu::setColor(7);
            if (strcmp(nuevoNombre, "0") == 0)
        {
            system ("cls");
            modifica.modificarEmpleado();
        }
            empleado.setNombre(nuevoNombre);
            break;
        }
    case 3:
        {
            char nuevoApellido[50];
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "Ingrese nuevo apellido: ";
            Menu::setColor(0);
            cin.ignore();
            cin.getline(nuevoApellido, 50);
            Menu::setColor(7);
            if (strcmp(nuevoApellido, "0") == 0)
            {
            system ("cls");
            modifica.modificarEmpleado();
            }
            empleado.setApellido(nuevoApellido);
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
                modifica.modificarEmpleado();
            }
            empleado.setEmail(nuevoEmail);
            break;
        }
    case 5:
        {

             int nuevonTelefono;
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "Ingrese nuevo nï¿½mero de telï¿½fono: ";
            cin.ignore();
            cin>>nuevonTelefono;
            if (nuevonTelefono == 0)
            {
                system ("cls");
                modifica.modificarEmpleado();
            }
            empleado.setnTelefono(nuevonTelefono);
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
                modifica.modificarEmpleado();
            }
            empleado.setLocalidad(nuevaLocalidad);
            break;
        }
    case 7:
        {
            Fecha nuevaFecha;
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "Ingrese nueva fecha de ingreso (dd mm yyyy): "<<endl;
            nuevaFecha.cargarFecha();
            break;
        }
    case 8:
        {
            int nuevasAsistencias;
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "Ingrese nuevas asistencias: ";
            cin >> nuevasAsistencias;
            if (nuevasAsistencias == 0)
            {
                system ("cls");
                modifica.modificarEmpleado();
            }
            empleado.setAsistencias(nuevasAsistencias);
            break;
        }
    case 9:
        {
            int enVacaciones;
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "ï¿½Esta de vacaciones? (1 para no, 2 para si): ";
            cin >> enVacaciones;
            if (enVacaciones == 0)
            {
                system ("cls");
                modifica.modificarEmpleado();
            }

            empleado.setvacacionesActivas(enVacaciones-1);
            break;
        }
    case 10:
        {
            float nuevoSueldo;
            cout << "0. Cancelar y volver al menu modificar "<<endl<<endl;
            cout << "Ingrese nuevo sueldo: ";
            cin >> nuevoSueldo;
            if (nuevoSueldo == 0)
            {
                system ("cls");
                modifica.modificarEmpleado();
            }
            empleado.setSueldo(nuevoSueldo);
            break;
        }
    default:
        menu.mensajeDeError("Atributo no vï¿½lido.");
        return;
    }
    if (Guardar(empleado, pos))
    {
        Menu::setColor(2);
        cout << "Datos del empleado actualizados." << endl;
        Menu::setColor(7);
    }
    else
    {

        menu.mensajeDeError("Error al actualizar los datos del empleado.");
        cout << endl;
    }
}

    {
        return false;
    }
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, registro);
    fclose(registro);
    return ok;
}

bool ArchivoEmpleados::Guardar(Empleado empleado, int posicion)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb+");
    if(registro == NULL)
    {
        return false;
    }
    fseek(registro, sizeof(Empleado) * posicion, SEEK_SET);
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, registro);
    fclose(registro);
    return ok;
}


Empleado ArchivoEmpleados::Buscar(int empleadoID)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado, fallo;
    fallo.setempleadoID(-1);
    if(registro == NULL)
    {
        return fallo;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro))
    {
        if(empleado.getID() == empleadoID)
        {
            fclose(registro);
            return empleado;
        }
    }
    fclose(registro);
    return fallo;
}




void ArchivoEmpleados::FiltrarEmpleados()
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    Menu menu;
    int cont = 0;

    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron empleados.");
        return;
    }
    while (fread(&empleado, sizeof(empleado), 1, registro))
    {
        cont++;
        cout << cont << ". ";
        empleado.mostrarEmpleado();
    }

    if (cont == 0)
    {
        menu.mensajeDeError("No se encontraron empleados en el archivo.");
    }

    fclose(registro);


}
void ArchivoEmpleados::FiltrarPorNombre(string _nombre)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    Menu menu;
    int cont = 0;
    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron empleados." );
        return;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro))
    {
        if(empleado.getNombre() == _nombre)
        {
            fclose(registro);
            empleado.mostrarEmpleado();
            cont++;
        }
    }
    if(cont == 0)
    {
        menu.mensajeDeError("No se encontraron empleados con el nombre: ");
        cout << _nombre<<endl;
    }
    fclose(registro);
}

void ArchivoEmpleados::FiltrarPorOrdenAlfabetico()
{
    FILE *registroA = fopen(_nombreArchivo.c_str(), "rb");
    int cantRegistros = ArchivoEmpleados::CantidadRegistros();
    Empleado* registro = new Empleado[cantRegistros];

    Empleado empleado;
    Menu menu;

    if (registroA == nullptr)
    {
        menu.mensajeDeError("No se han encontrado empleados registrados");
        return;
    }

    if (cantRegistros > 0)
    {
        for (int i = 0; i < cantRegistros; i++)
        {
            registro[i] = ArchivoEmpleados::Leer(i);
        }

        for (int i = 0; i < cantRegistros - 1; i++)
        {
            for (int j = 0; j < cantRegistros - i - 1; j++)
            {
                if (strcmp(registro[j].getApellido(), registro[j + 1].getApellido()) > 0)
                {
                    Empleado temp = registro[j];
                    registro[j] = registro[j + 1];
                    registro[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < cantRegistros; i++)
        {
            registro[i].mostrarEmpleado();
        }
    }

    delete[] registro;
    fclose(registroA);
}

void ArchivoEmpleados::FiltrarPorID(int _ID)
{

    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    Menu menu;
    int cont = 0;
    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron empleados." );
        return;
    }
    while(fread(&empleado, sizeof(empleado), 1, registro))
    {
        if(empleado.getID() == _ID)
        {
            empleado.mostrarEmpleado();
            cont++;
        }
    }
    if(cont == 0)
    {
        menu.mensajeDeError("No se encontraron empleados con el ID: ");
        cout<< _ID<<endl;
    }
    fclose(registro);

}
void ArchivoEmpleados::FiltrarPorFecha()
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    int cantRegistros = ArchivoEmpleados::CantidadRegistros();
    Empleado* empleado = new Empleado [cantRegistros];
    Menu menu;
    Fecha fecha;
    int cont = 0;
    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron empleados." );
        return;
    }
    if (cantRegistros != 0)
    {
        for (int i = 0; i < cantRegistros; i++ )
        {
            empleado[i] = ArchivoEmpleados::Leer(i);
        }
        for (int i = 0; i < cantRegistros - 1; i++)
        {
            for (int j = 0; j < cantRegistros - i - 1; j++)
            {
                Fecha fechaA = empleado[j].getFechaIngreso();
                Fecha fechaB = empleado[j + 1].getFechaIngreso();

                if (fechaA.getAnio() > fechaB.getAnio() ||
                        (fechaA.getAnio() == fechaB.getAnio() && fechaA.getMes() > fechaB.getMes()) ||
                        (fechaA.getAnio() == fechaB.getAnio() && fechaA.getMes() == fechaB.getMes() && fechaA.getDia() > fechaB.getDia()))
                {
                    Empleado temp = empleado[j];
                    empleado[j] = empleado[j + 1];
                    empleado[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < cantRegistros; i++)
        {
            empleado[i].mostrarEmpleado();
        }
    }
    else
    {
        menu.mensajeDeError("No se encontraron empleados");
    }

    fclose(registro);
}

void ArchivoEmpleados::FiltrarPorAsistencias()
{

    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");

    Empleado empleadoArr[40];
    Empleado empleado;
    Menu menu;
    int cont = 0;
    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron empleados.");
        return;
    }

    // Leer empleados desde el archivo
    while (fread(&empleado, sizeof(empleado), 1, registro) && cont < 40)
    {
        empleadoArr[cont] = empleado; // Agregar empleado al arreglo
        cont++;
    }
    fclose(registro);

    // Ordenar empleados por asistencias de manera ascendente
    for (int i = 0; i < cont - 1; i++)
    {
        for (int j = 0; j < cont - i - 1; j++)
        {
            if (empleadoArr[j].getAsistencias() < empleadoArr[j + 1].getAsistencias())
            {
                // Intercambiar empleados
                Empleado temp = empleadoArr[j];
                empleadoArr[j] = empleadoArr[j + 1];
                empleadoArr[j + 1] = temp;
            }
        }
    }

    // Mostrar empleados ordenados por asistencias
    for (int i = 0; i < cont; i++)
    {
        empleadoArr[i].mostrarEmpleado();
    }

}
void ArchivoEmpleados::FiltrarPorVacacionesActivas(bool _vacaciones)
{

    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    Menu menu;
    int cont = 0;
    if (registro == nullptr)
    {
        menu.mensajeDeError("No se encontraron empleados.");
        return;
    }
    while (fread(&empleado, sizeof(empleado), 1, registro))
    {
        if(empleado.getIsVacaciones() == _vacaciones)
        {
            empleado.mostrarEmpleado();
            cont++;
        }
    }

    if(cont==0 && _vacaciones)
    {
        menu.mensajeDeError("No se encontraron empleados con vacaciones activas");
    }
    else if(cont ==0 && !_vacaciones)
    {
        menu.mensajeDeError("No se encontraron empleados con vacaciones inactivas");
    }


    fclose(registro);

}
void ArchivoEmpleados::eliminarArchivoEmpleados()
{
    Menu menu;
    menu.setColor(7);
    string nombre, aux;
    ifstream salida;
    salida.open("ArchivoEmpleados.dat", ios::in);
    ofstream entrada;
    entrada.open("temp.dat", ios::out);

    if (salida.fail())
    {
        menu.mensajeDeError("Hubo un error al abrir el archivo ArchivoEmpleados.dat");
        cout << endl;
        cin.get();
        exit(0);
    }
    else
    {
        salida.close();
        entrada.close();

        remove("ArchivoEmpleados.dat");  // Eliminar el archivo original
        rename("temp.dat", "ArchivoEmpleados.dat");  // Renombrar el archivo temporal a "ArchivoEmpleados.dat"
        cout<<"Registros del archivo eliminados"<<endl;
    }
}
void ArchivoEmpleados::eliminarRegistroEmpleado(int empleadoID)
{
    Menu menu;
    string nombreEmpleado;
    FILE* archivoOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if (archivoOriginal == nullptr)
    {
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        cout << endl;
        return;
    }

    FILE* archivoTemporal = fopen("empleados_temp.dat", "wb");
    if (archivoTemporal == nullptr)
    {
        menu.mensajeDeError("Error al crear archivo temporal.");
        cout << endl;
        fclose(archivoOriginal);
        return;
    }

    Empleado empleado;
    bool encontrado = false;


    while (fread(&empleado, sizeof(Empleado), 1, archivoOriginal))
    {
        if (empleado.getID() != empleadoID)
        {

            fwrite(&empleado, sizeof(Empleado), 1, archivoTemporal);
        }
        else
        {
            nombreEmpleado = empleado.getNombre();
            encontrado = true;
        }
    }


    fclose(archivoOriginal);
    fclose(archivoTemporal);


    if (encontrado)
    {
        remove(_nombreArchivo.c_str());
        rename("empleados_temp.dat", _nombreArchivo.c_str());
        Menu::setColor(7);
        cout << "Empleado con ID " ;
        Menu::setColor(0);
        cout<< empleadoID ;
        Menu::setColor(7);
        cout<<" y con nombre ";
        Menu::setColor(0);
        cout<< nombreEmpleado;
        Menu::setColor(7);
        cout<< " eliminado correctamente." << endl;
    }
    else
    {

        remove("empleados_temp.dat");
        Menu::setColor(7);
        cout << "Empleado con ID " ;
        Menu::setColor(0);
        cout << empleadoID;
        Menu::setColor(7);
        cout << " no encontrado." << endl;
    }
}

Empleado ArchivoEmpleados::Leer(int posicion)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL)
    {
        return Empleado();
    }
    Empleado empleado;
    fseek(registro, sizeof(Empleado) * posicion, SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, registro);
    fclose(registro);
    return empleado;
}

int ArchivoEmpleados::CantidadRegistros()
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL)
    {
        return 0;
    }
    fseek(registro, 0, SEEK_END);
    int cantidadRegistros = ftell(registro) / sizeof(Empleado);
    fclose(registro);
    return cantidadRegistros;
}


void ArchivoEmpleados::Leer(int cantidadRegistros, Empleado *vector)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if(registro == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Empleado), 1, registro);
    }
    fclose(registro);
}

void ArchivoEmpleados::ModificarEmpleado(int empleadoID, int atributo)
{
    Menu menu;
    ArchivoEmpleados Empleados("ArchivoEmpleados.dat");

    int pos = BuscarPosRegistro(empleadoID);
    if (pos == -1)
    {

        menu.mensajeDeError("Empleado no encontrado." );
        cout << endl;
        return;
    }

    Empleado empleado = Leer(pos);

    switch (atributo)
    {
    case 1:
    {
        int nuevoDNI;
        cout << "Ingrese nuevo DNI: ";
        cin >> nuevoDNI;
        empleado.setDNI(nuevoDNI);
        break;
    }
    case 2:
    {
        char nuevoNombre[50];
        cout << "Ingrese nuevo nombre: ";
        cin.ignore();
        cin.getline(nuevoNombre, 50);
        empleado.setNombre(nuevoNombre);
        break;
    }
    case 3:
    {
        char nuevoApellido[50];
        cout << "Ingrese nuevo apellido: ";
        cin.ignore();
        cin.getline(nuevoApellido, 50);
        empleado.setApellido(nuevoApellido);
        break;
    }
    case 4:
    {
        char nuevoEmail[50];
        cout << "Ingrese nuevo email: ";
        cin.ignore();
        cin.getline(nuevoEmail, 50);
        empleado.setEmail(nuevoEmail);
        break;
    }
    case 5:
    {

        int nuevonTelefono;
        cout << "Ingrese nuevo número de teléfono: ";
        cin.ignore(); // Ignorar el salto de línea pendiente
        cin>>nuevonTelefono;
        empleado.setnTelefono(nuevonTelefono);
        break;
    }
    case 6:
    {
        char nuevaLocalidad[50];
        cout << "Ingrese nueva localidad: ";
        cin.ignore();
        cin.getline(nuevaLocalidad, 50);
        empleado.setLocalidad(nuevaLocalidad);
        break;
    }
    case 7:
    {
        Fecha nuevaFecha;
        cout << "Ingrese nueva fecha de ingreso (dd mm yyyy): "<<endl;
        nuevaFecha.cargarFecha();
        empleado.setfechadeingreso(nuevaFecha);
        break;
    }
    case 8:
    {
        int nuevasAsistencias;
        cout << "Ingrese nuevas asistencias: ";
        cin >> nuevasAsistencias;
        empleado.setAsistencias(nuevasAsistencias);
        break;
    }
    case 9:
    {
        bool enVacaciones;
        cout << "¿Esta de vacaciones? (1 para si, 0 para no): ";
        cin >> enVacaciones;
        empleado.setvacacionesActivas(enVacaciones);
        break;
    }
    case 10:
    {
        float nuevoSueldo;
        cout << "Ingrese nuevo sueldo: ";
        cin >> nuevoSueldo;
        empleado.setSueldo(nuevoSueldo);
        break;
    }
    default:
        menu.mensajeDeError("Atributo no válido.");
        return;
    }
    if (Guardar(empleado, pos))
    {
        Menu::setColor(2);
        cout << "Datos del empleado actualizados." << endl;
        Menu::setColor(7);
    }
    else
    {

        menu.mensajeDeError("Error al actualizar los datos del empleado.");
        cout << endl;
    }
}

int ArchivoEmpleados::BuscarPosRegistro(int empleadoID)
{
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    Empleado empleado;
    if(registro == NULL)
    {
        return -1;
    }
    int i = 0;
    while(fread(&empleado, sizeof(empleado), 1, registro) == 1)
    {
        if(empleado.getID() == empleadoID)
        {
            fclose(registro);
            return i;
        }
        i++;
    }
    fclose(registro);
    return -1;
}

void ArchivoEmpleados::exportarEmpleadosACSV(string nombreArchivoCSV)
{
    Menu menu;
    FILE *registro = fopen(_nombreArchivo.c_str(), "rb");
    if (registro == nullptr)
    {
        menu.mensajeDeError("Error al abrir el archivo para lectura.");
        return;
    }

    ofstream archivoCSV(nombreArchivoCSV);
    if (!archivoCSV.is_open())
    {
        menu.mensajeDeError("Error al crear el archivo CSV.");
        fclose(registro);
        return;
    }

    int cont = 0;
    Empleado empleado;
    archivoCSV << "     -------------Datos de Empleados----------------"<<endl;
    while (fread(&empleado, sizeof(Empleado), 1, registro))
    {
        Menu::setColor(7);
        archivoCSV <<"ID: "<<empleado.getID() << endl;
        archivoCSV <<"NOMBRE: "<<empleado.getNombre() << endl;
        archivoCSV <<"APELLIDO: "<<empleado.getApellido() << endl;
        archivoCSV <<"EMAIL: "<<empleado.getEmail() << endl;
        archivoCSV <<"NUMERO DE TELEFONO: "<<empleado.getnTelefono() << endl;
        archivoCSV <<"LOCALIDAD: "<<empleado.getLocalidad() << endl;
        archivoCSV << endl;
        archivoCSV << "FECHA DE INGRESO: " << empleado.getFechaIngreso().getDia()<<"/"<<empleado.getFechaIngreso().getMes()<<"/"<<empleado.getFechaIngreso().getAnio()<<endl;
        archivoCSV << "ASISTENCIAS: " <<empleado.getAsistencias() <<endl;
        archivoCSV << "VACACIONES ACTIVAS: ";
        if (empleado.getIsVacaciones() == true)
        {
            archivoCSV << "Si";
        }
        else
        {
            archivoCSV << "No";
        }
        archivoCSV<<endl;
        archivoCSV << "SUELDO: " ;
        archivoCSV << empleado.getSueldo() <<endl;
        archivoCSV << endl;
        archivoCSV << "-----------------------------------------------------" << endl;
        archivoCSV << endl;

        cout << "FECHA DE INGRESO: " << empleado.getFechaIngreso().getDia()<<"/"<<empleado.getFechaIngreso().getMes()<<"/"<<empleado.getFechaIngreso().getAnio() <<endl;
        cout <<"ASISTNCIAS:"<< empleado.getAsistencias()<< endl;
        cout << "VACACIONES ACTIVAS: ";
        if (empleado.getIsVacaciones())
        {
            cout << "Si"  ;
        }
        else
        {
            cout << "No"  ;
        }
        cout <<"SUELDO:"<< empleado.getSueldo()<< endl;
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << endl;
        cont++;
    }
    fclose(registro);
    archivoCSV.close();

    cout << "Se exportaron " << cont << " productos al archivo CSV." << endl;
}
