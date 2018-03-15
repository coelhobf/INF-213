#include "FigBase.h" 
#include "Retangulo.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

Retangulo::Retangulo(double x, double y, double larg, double alt, int esp, int c, int t) :
    FigBase(x, y, esp, c, t)
{
    setLargura(larg);
    setAltura(alt);
}

Retangulo::Retangulo() { }

double Retangulo::getLargura() const
{
    return largura;
}

void Retangulo::setLargura(double larg)
{
    largura = larg;
}

double Retangulo::getAltura() const
{
    return altura;
}

void Retangulo::setAltura(double alt)
{
    altura = alt;
}

float Retangulo::area() const
{
    return altura * largura;     
}      
          
float Retangulo::perimetro() const
{
    return 2*(largura + altura);      
}

void Retangulo::le()
{
    FigBase::le();
    int largura, altura;
    cin>> largura >> altura;
    this->setLargura(largura);
    this->setAltura(altura);
}

void Retangulo::imprime() const
{
    cout << "--- [Retangulo] ---" << endl;
    FigBase::imprime();
    cout << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

istream& operator>>(istream& is, Retangulo& fig)
{
    fig.le();
    return is;
}

ostream& operator<<(ostream& os, const Retangulo& fig)
{
    fig.imprime();
    return os;
}
