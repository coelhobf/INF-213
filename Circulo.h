#include "FigBase.h"

#ifndef __Circulo_h
#define __Circulo_h

class Circulo : public FigBase
{
private:
    double raio;

public:
    Circulo(double, double, double, int, int, int);
    Circulo() { }

    double getRaio() const;
    void setRaio(double);

    float area() const;
    float perimetro() const;

    void le();
    void imprime() const;
};

#endif
