#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
private:
    int  DNI;
    char nombre [50];
    char apellido [50];
    char email [50];
    int  nTelefono;
    char localidad [50];
public:
    Persona();
    Persona(int _DNI, const char* _nombre,const char* _apellido,const char* _email, int _nTelefono, const char* _localidad);

    int getDNI();
    const char* getNombre();
    const char* getApellido();
    const char* getEmail();
    const char* getLocalidad();
    int getnTelefono();

    void setDNI(int _DNI);
    void setNombre(const char* _nombre);
    void setApellido(const char* _apellido);
    void setEmail(const char* _email);
    void setnTelefono(int _nTelefono);
    void setLocalidad(const char* _localidad);
    void mostrarPersona();
    void cargarPersona();

};

#endif // PERSONA_H_INCLUDED
