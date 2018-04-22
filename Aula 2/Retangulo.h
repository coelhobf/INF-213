#include "FigBase.h"
#include <iostream>
using std::istream;
using std::ostream;

#ifndef __Retangulo_h
#define __Retangulo_h

class Retangulo : public FigBase
{
private:
    double largura, altura;

public:
    Retangulo(double, double, double, double, int, int, int);
    Retangulo() { }

    double getLargura() const;
    void setLargura(double);

    double getAltura() const;
    void setAltura(double);

    float area() const;
    float perimetro() const;

    void le();
    void imprime() const;

    friend istream& operator>>(istream& is, Retangulo& fig);
    friend ostream& operator<<(ostream& os, const Retangulo& fig);
};

#endif
