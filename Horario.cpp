#include "Horario.h"
#include <iostream>

Horario::Horario(int segundo, int minuto, int hora)
{
    this->segundo = segundo;
    this->minuto = minuto;
    this->hora = hora;
}

Horario::Horario(const Horario& horario)
{
    this->segundo = horario.getSegundo();
    this->minuto = horario.getMinuto();
    this->hora = horario.getHora();
}

void Horario::setSegundo(int segundo)
{
    if(segundo > 59)
    {
        this->segundo = 59;
    }
    else if(segundo < 0)
    {
        this->segundo = 0;
    }
    else
    {
        this->segundo = segundo;
    }
}

void Horario::setMinuto(int minuto)
{
    if(minuto > 59)
    {
        this->minuto = 59;
    }
    else if(minuto < 0)
    {
        this->minuto = 0;
    }
    else
    {
        this->minuto = minuto;
    }
}

void Horario::setHora(int hora)
{
    if(hora > 23)
    {
        this->hora = 23;
    }
    else if(hora < 0)
    {
        this->hora = 0;
    }
    else
    {
        this->hora = hora;
    }
}

int Horario::getSegundo() const
{
    return this->segundo;
}

int Horario::getMinuto() const
{
    return this->minuto;
}

int Horario::getHora() const
{
    return this->hora; 
}

int Horario::compHorario(const Horario& horario)
{
    if(this->hora < horario.getHora())
    {
        return -1;
    }
    else if(this->hora > horario.getHora())
    {
        return 1;
    }
    else
    {
        if(this->minuto < horario.getMinuto())
        {
            return -1;
        }
        else if(this->minuto > horario.getMinuto())
        {
            return 1;
        }
        else
        {
            if(this->segundo < horario.getSegundo())
            {
                return -1;
            }
            else if(this->segundo > horario.getSegundo())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    } 
}

int Horario::difSegundos(const Horario& horario)
{
    int segundosObj = this->hora * 360 + this->minuto * 30 + this->segundo;
    int segundosComp = horario.getHora() * 360 + horario.getMinuto() * 30 + horario.getSegundo();
    int dif = segundosObj - segundosComp;
    
    return dif < 0 ? dif * -1 : dif;
}

std::ostream& operator<<(std::ostream &os, const Horario &horario)
{
    os<< horario.getHora() << " ";
    os<< horario.getMinuto() << " ";
    os<< horario.getSegundo();

    return os;
}

std::istream& operator>>(std::istream &is, Horario &horario)
{
    int hora, minuto, segundo;
    is>> hora >> minuto >> segundo;
    
    horario.setHora(hora);
    horario.setMinuto(minuto);
    horario.setSegundo(segundo);

    return is;
}

void Horario::imprime()
{
    std::cout<< this;
}