#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

using namespace std;

class Persona{
private:
    int DNI;
    char nombre [30];
    char apellido [30];
    string email;
    char localidad [30];
public:
    Persona();
    Persona(int _DNI, const char* _nombre,const char* _apellido,string _email,const char* _localidad);

    int getDNI();
    const char* getNombre();
    const char* getApellido();
    string getEmail();
    const char* getLocalidad();

    void setDNI(int _DNI);
    void setNombre(const char* _nombre);
    void  setApellido(const char* _apellido);
    void setEmail(string _email);
    void  setLocalidad(const char* _localidad);
    void mostrarPersona();
};

#endif // PERSONA_H_INCLUDED
