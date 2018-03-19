#ifndef FIGBASE_H
#define FIGBASE_H

#include <iostream>
using namespace std;

class FigBase
{
private:
    double x;
    double y;
    int espessura;
    int cor;
    int tipo;

public:
    FigBase(double, double, int, int, int);
    FigBase() { }
    
    double getX() const;
    void setX(double);

    double getY() const;
    void setY(double);

    int getEspessura() const;
    void setEspessura(int);

    int getCor() const;
    void setCor(int);

    int getTipo() const;
    void setTipo(int);

    virtual void le();
    virtual void imprime() const;

    friend istream& operator>> (istream &is, FigBase &obj);
    friend ostream& operator<< (ostream &os, FigBase &obj);
};

#endif