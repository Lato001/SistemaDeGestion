#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
class Fecha{
    private:
    int dia, mes, anio;

    public:
    Fecha();
    Fecha(int _dia, int _mes, int _anio);

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int _dia);
    void setMes(int _mes);
    void setAnio(int _anio);
    char* toString();
};

#endif // FECHA_H_INCLUDED
