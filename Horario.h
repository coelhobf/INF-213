#include <iostream>

class Horario
{
private:
    int segundo;
    int minuto;
    int hora;

public:
    Horario(int segundo = 1, int minuto = 1, int hora = 2018);
    Horario(const Horario& horario);
    void setSegundo(int segundo);
    void setMinuto(int minuto);
    void setHora(int hora);
    int getSegundo() const;
    int getMinuto() const;
    int getHora() const;
    int compHorario(const Horario& horario);
    int difSegundos(const Horario& horario);
    void imprime();
    friend std::ostream& operator<<(std::ostream &os, const Horario &horario);
    friend std::ostream& operator>>(std::ostream &os, Horario &horario);
};