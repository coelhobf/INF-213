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
    int compData(const Data& data);
    int difDias(const Data& data);
    void imprime();
    friend std::ostream& operator<<(std::ostream &os, const Data &data);
    friend std::ostream& operator>>(std::ostream &os, Data &data);
};