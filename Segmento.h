#include "FigBase.h"

#ifndef SEGMENTO_H
#define SEGMENTO_H

class Segmento : public FigBase
{
private:
    double x2;
    double y2;

public:
    Segmento(double, double, double, double, int, int, int);

    double getX2() const;
    void setX2(double);

    double getY2() const;
    void setY2(double);

    float area() const;
    float perimetro() const;

    void imprime() const;
};

#endif