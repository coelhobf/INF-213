#include "FigBase.h"
#include "Segmento.h"
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

Segmento::Segmento(double x, double y, double x2, double y2, int esp, int c, int t) :
    FigBase(x, y, esp, c, t)
{
    setX2(x2);
    setY2(y2);
}

Segmento::Segmento() { }

double Segmento::getX2() const
{
    return this-> x2;
}

void Segmento::setX2(double x2)
{
    this-> x2 = x2;
}

double Segmento::getY2() const
{
    return this-> y2;
}

void Segmento::setY2(double y2)
{
    this-> y2 = y2;
}

float Segmento::area() const
{
    return 0;
}

float Segmento::perimetro() const
{
    float dx = getX2() - getX();
    dx = dx < 0 ? dx * -1 : dx;

    float dy = getY2() - getY();
    dy = dy < 0 ? dy * -1 : dy;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

void Segmento::le()
{
    FigBase::le();
    double x2, y2;
    cin>> x2 >> y2;
    setX2(x2);
    setY2(y2);
}

void Segmento::imprime() const
{
    cout << "--- [Segmento] ---" << endl;
    FigBase::imprime();
    cout << " x2 = " << getX2() << " y2 = " << getY2() << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

istream& operator>>(istream& is, Segmento& fig)
{
    fig.le();
    return is;
}

ostream& operator<<(ostream& os, const Segmento& fig)
{
    fig.imprime();
    return os;
}