#include <bits/stdc++.h>
#include "Mediana.h"

using namespace std;

Mediana::Mediana()
{
    this->part = 0;
}

void Mediana::heapIni(int pos)
{
    if (pos == 0)
    {
        return;
    }

    int i;

    if (pos % 2 == 0) //filho 2
    {
        i = (pos - 2) / 2;
    }
    else //filho 1
    {
        i = (pos - 1) / 2;
    }

    if (data[pos] > data[i])
    {
        swap(data[pos], data[i]);
    }
    heapIni(i);
}

void Mediana::heapFim(int pos)
{
    if (pos == this->part)
    {
        return;
    }

    int i, j = pos - part;

    if (j % 2 == 0) //filho 2
    {
        i = (j - 2) / 2;
    }
    else //filho 1
    {
        i = (j - 1) / 2;
    }

    if (data[pos] < data[i + part])
    {
        swap(data[pos], data[i + part]);
    }
    heapFim(i + part);
}

void Mediana::insere(int x)
{
    cout<< endl;
    data.push_back(x);
    heapFim(data.size() - 1);
    cout<< endl<<  "Fim: " <<  *this <<endl;

    while (this->part < data.size() / 2)
    {
        heapIni(this->part);
        this->part++;
        cout<< "Ini: " << *this << endl;
        heapFim(data.size() - 1);
        cout<< "Fim: " << *this << endl;
    }
}

int Mediana::getMediana()
{
    int i = data.size();

    if (i % 2 == 0) //par
    {
        return (data[0] + data[i / 2]) / 2;
    }
    else
    {
        return data[i / 2];
    }
}

ostream &operator<<(ostream &os, const Mediana &med)
{
    for (int i = 0; i < med.data.size(); i++)
    {
        if(i == med.part)
        {
            cout<< "| ";
        }
        cout << med.data[i] << " ";
    }

    return os;
}
