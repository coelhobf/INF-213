#include <iostream>
using namespace std;

#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"
      
int main()
{
    Circulo c1, c2;
    Retangulo r1;
    Segmento s1, s2;

    FigBase *obj[5];

    obj[0] = &c1;
    obj[1] = &c2;
    obj[2] = &r1;
    obj[3] = &s1;
    obj[4] = &s2;

    for(int i = 0; i < 5; i++)
    {
        cin>> *(obj[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        cout<< *(obj[i]);
        if (typeid(*(obj[i])) == typeid(Circulo))
        {
            Circulo *temp = dynamic_cast<Circulo*>(obj[i]);
            temp->setRaio(temp->getRaio() * 2);
        }
    }

    for(int i = 0; i < 5; i++)
    {
        cout<< *(obj[i]);
    }
}