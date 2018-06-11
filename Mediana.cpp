#include <bits/stdc++.h>
#include "Mediana.h"
using namespace std;

Mediana::Mediana()
{
  
}

void Mediana::insere(int el)
{
    el *= -1;
    d2.push(el);
    if (size() % 2 == 0)
    {
        d1.push(-1 * d2.top());
        d2.pop();
    }

    if(size() > 1)
    {
        if(d1.top() > (-1 * d2.top()))
        {
            d2.push(-1 * d1.top());
            d1.pop();
            d1.push(-1 * d2.top());
            d2.pop();
        }
    }
}

int Mediana::getMediana()
{
    int med;

    if (size() % 2 == 0)
    {
        med = d1.top() + (-1 * d2.top());
        med /= 2;
    }
    else
    {
        med = -1 * d2.top();
    }

    return med;
}

ostream &operator<<(ostream &os, const Mediana &med)
{
    med.d1.print();
    med.d2.print();
    return os;
}

int Mediana::size()
{
    return d1.size() + d2.size();
}
