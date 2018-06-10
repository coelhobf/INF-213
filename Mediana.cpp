#include <bits/stdc++.h>
#include "Mediana.h"
using namespace std;

Mediana::Mediana()
{
    hasLeft = 0;
}

void Mediana::insere(int el)
{
    el *= -1;
    data.push(el);
    if ((hasLeft + data.size()) % 2 == 0)
    {
        left = data.top();
        hasLeft++;
        data.pop();
    }
}

int Mediana::getMediana()
{
    int med;

    if (size() % 2 == 0)
    {
        med = left + data.top();
        med /= 2;
    }
    else
    {
        med = data.top();
    }

    return -1 * med;
}

ostream &operator<<(ostream &os, const Mediana &med)
{
    med.data.print();
    return os;
}

int Mediana::size()
{
    return hasLeft + data.size();
}