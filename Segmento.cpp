
#include "Segmento.h"
#include <iostream>

using namespace std;

#include <math.h>

Segmento::Segmento(double x, double y, double x2, double y2,
                     int e, int c, int t) : FigBase(x, y, e, c, t) {
    setX2(x2);
    setY2(y2);
}

double Segmento::getX2() const {
    return x2;
}

void Segmento::setX2(double x2) {
    this->x2 = x2;
}

double Segmento::getY2() const {
    return y2;
}

void Segmento::setY2(double y2) {
    this->y2 = y2;
}

float Segmento::area() const {
    return 0;
}

//Esse perimetro de um segmento nao faz muito sentido!
float Segmento::perimetro() const {
    return sqrt((getX() - x2)*(getX() - x2) + (getY() - y2) * (getY() - y2));
}

void Segmento::ler()
{
    double x2,y2;

    cout << "Forneca os dados do Segmento \n";
    this->FigBase::ler();
    cout << "x2 = ";
    cin >> x2;
    this->setX2(x2);
    cout << "y2 = ";
    cin >> y2;
    this->setY2(y2);
}

void Segmento::imprime() const
{
    cout << "--- [Segmento] ---" << endl;
    this->FigBase::imprime();
    cout << " x2 = " << this->getX2() << " Y2 = " << this->getY2() << endl;
    cout << " area = " << this->area() << " perimetro = " << this->perimetro() << endl;
}
