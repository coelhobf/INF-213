#include "FigBase.h"
#include "Segmento.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

Segmento::Segmento(double x, double y, double x2, double y2, int esp, int c, int t) :
    FigBase(x, y, esp, c, t)
{
    setX2(x2);
    setY2(y2);
}

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

void Segmento::imprime() const
{
    cout << "--- [Segmento] ---" << endl;
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << getEspessura() << endl;
    cout << "     Cor       = " << getCor() << endl;
    cout << "     Tipo      = " << getTipo() << endl;          
    cout << " x = " << getX() << " y = " << getY() << endl;
    cout << " x2 = " << getX2() << " y2 = " << getY2() << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}