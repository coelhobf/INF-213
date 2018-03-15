#include "FigBase.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

FigBase::FigBase(double x, double y, int esp, int cor, int tipo)
{
    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(cor);
    setTipo(tipo);
}

FigBase::FigBase() { }
    
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
    this->espessura = (esp < 1 || esp > 5) ? 1 : esp;
}

int FigBase::getCor() const
{
    return this->cor;
}

void FigBase::setCor(int cor)
{
    this->cor = (cor < 1 || cor > 5) ? 1 : cor;
}

int FigBase::getTipo() const
{
    return this->tipo;
}

void FigBase::setTipo(int tipo)
{
    this->tipo = (tipo < 1 || tipo > 3) ? 1 : tipo;
}

void FigBase::le()
{
    int esp, cor, tipo;
    double x, y;
    cin>> esp >> cor >> tipo >> x >> y;
    this->setEspessura(esp);
    this->setCor(cor);
    this->setTipo(tipo);
    this->setX(x);
    this->setY(y);
}

void FigBase::imprime() const
{
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << getEspessura() << endl;
    cout << "     Cor       = " << getCor() << endl;
    cout << "     Tipo      = " << getTipo() << endl;          
    cout << " x = " << getX() << " y = " << getY() << endl;
}