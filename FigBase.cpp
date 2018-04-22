#include "FigBase.h"
#include <iostream>
using namespace std;

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
    double x, y;
    int esp, cor, tipo;

    cin>> x >> y >> esp >> cor >> tipo;

    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(cor);
    setTipo(tipo);
}

void FigBase::imprime() const
{
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << getEspessura() << endl;
    cout << "     Cor       = " << getCor() << endl;
    cout << "     Tipo      = " << getTipo() << endl;      
    cout << " x = " << getX() << " y = " << getY() << endl;
}

istream& operator>> (istream &is, FigBase &obj)
{
    obj.le();
    return is;
}

ostream& operator<< (ostream &os, FigBase &obj)
{
    obj.imprime();
    return os;
}