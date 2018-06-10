#ifndef MEDIANA_H
#define MEDIANA_H

#include <bits/stdc++.h>

using namespace std;

class Mediana
{
public:
    Mediana();

    void insere(int);
    int getMediana();

    friend ostream& operator<<(ostream&, const Mediana&);

private:
    vector<int> data;
    void heapIni(int);
    void heapFim(int);
    int part;
};

#endif