#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
using namespace std;
class Persona{
private:
    int DNI;
    string nombre;
    string apellido;
    string email;
    string localidad;
public:
    Persona();
    Persona(int _DNI, string _nombre,string _apellido,string _email,string _localidad);

    int getDNI();
    string getNombre();
    string getApellido();
    string getEmail();
    string getLocalidad();

    void setDNI(int _DNI);
    void setNombre(string _nombre);
    void  setApellido(string _apellido);
    void setEmail(string _email);
    void  setLocalidad(string _localidad);
    void mostrarPersona();
};

#endif // PERSONA_H_INCLUDED
