#include "FigBase.h"

FigBase::FigBase(double x, double y, int esp, int cor, int tipo)
{
    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(cor);
    setTipo(tipo);
}
    
double FigBase::getX() const
{
    return this->x;
}

void FigBase::setX(double x)
{
    this->x = x;
}

double FigBase::getY() const
{
    return this-> y;
}

void FigBase::setY(double y)
{
    this->y = y;
}

int FigBase::getEspessura() const
{
    return this->espessura;
}

void FigBase::setEspessura(int esp)
{
    if(esp < 1)
    {
        this->espessura = 1;
    }
    else  if(esp > 5)
    {
        this->espessura = 5;
    }
    else
    {
        this->espessura = esp;
    }
}

int FigBase::getCor() const
{
    return this->cor;
}

void FigBase::setCor(int cor)
{
    if(cor < 1)
    {
        this->cor = 1;
    }
    else  if(cor > 5)
    {
        this->cor = 5;
    }
    else
    {
        this->cor = cor;
    }
}

int FigBase::getTipo() const
{
    return this->tipo;
}

void FigBase::setTipo(int tipo)
{
    if(tipo < 1)
    {
        this->tipo = 1;
    }
    else  if(tipo > 3)
    {
        this->tipo = 3;
    }
    else
    {
        this->tipo = tipo;
    }
}

void FigBase::imprime() const { }