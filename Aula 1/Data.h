#ifndef DATA_H
#define DATA_H

#include <iostream>

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia = 1, int mes = 1, int ano = 2018);
    Data(const Data& data);
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    int getDia() const;
    int getMes() const;
    int getAno() const;
    int compData(const Data& data) const;
    int difDias(const Data& data) const;
    void imprime();
    friend std::ostream& operator<<(std::ostream &os, const Data &data);
    friend std::istream& operator>>(std::istream &is, Data &data);
};

#endif