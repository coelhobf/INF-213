#include "FigBase.h"
#include "Circulo.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

const float PI = 3.141592653589;

Circulo::Circulo(double x, double y, double r, int esp, int c, int t) :
    FigBase(x, y, esp, c, t)
{
    setRaio(r);
}

Circulo::Circulo() { }

double Circulo::getRaio() const
{
    return raio;
}

void Circulo::setRaio(double r)
{
    raio = r;
}

float Circulo::area() const
{
    return PI * raio * raio;    
}      
          
float Circulo::perimetro() const
{
    return 2 * PI * raio;      
}

void Circulo::le()
{
    FigBase::le();
    double raio;
    cin>> raio;
    setRaio(raio);
}

void Circulo::imprime() const
{
    cout << "--- [Circulo] ---" << endl;
    FigBase::imprime();
    cout << " raio = " << getRaio() << endl; 
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

istream& operator>>(istream& is, Circulo& fig)
{
    fig.le();
    return is;
}

ostream& operator<<(ostream& os, const Circulo& fig)
{
    fig.imprime();
    return os;
}
