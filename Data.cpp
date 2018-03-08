#include "Data.h"
#include <iostream>

Data::Data(int dia, int mes, int ano)
{
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
}

Data::Data(const Data& data)
{
    this->dia = data.getDia();
    this->mes = data.getMes();
    this->ano = data.getAno();
}

void Data::setDia(int dia)
{
    if(dia > 30)
    {
        this->dia = 30;
    }
    else if(dia < 1)
    {
        this->dia = 1;
    }
    else
    {
        this->dia = dia;
    }
}

void Data::setMes(int mes)
{
    if(mes > 12)
    {
        this->mes = 12;
    }
    else if(mes < 1)
    {
        this->mes = 1;
    }
    else
    {
        this->mes = mes;
    }
}

void Data::setAno(int ano)
{
    if(ano > 2020)
    {
        this->ano = 2020;
    }
    else if(ano < 2018)
    {
        this->ano = 2018;
    }
    else
    {
        this->ano = ano;
    }
}

int Data::getDia() const
{
    return this->dia;
}

int Data::getMes() const
{
    return this->mes;
}

int Data::getAno() const
{
    return this->ano;
}

int Data::compData(const Data& data) const
{
    if(this->ano < data.getAno())
    {
        return -1;
    }
    if(this->ano > data.getAno())
    {
        return 1;
    }
    if(this->mes < data.getMes())
    {
        return -1;
    }
    if(this->mes > data.getMes())
    {
        return 1;
    }
    if(this->dia < data.getDia())
    {
        return -1;
    }
    if(this->dia > data.getDia())
    {
        return 1;
    }
    
    return 0;
}

int Data::difDias(const Data& data) const
{
    int diasObj = this->ano * 360 + this->mes * 30 + this->dia;
    int diasComp = data.getAno() * 360 + data.getMes() * 30 + data.getDia();
    int dif = diasObj - diasComp;
    
    return dif < 0 ? dif * -1 : dif;
}

std::ostream& operator<<(std::ostream &os, const Data &data)
{
    os<< data.getDia() << " ";
    os<< data.getMes() << " ";
    os<< data.getAno();

    return os;
}

std::istream& operator>>(std::istream &is, Data &data)
{
    int dia, mes, ano;
    is>> dia >> mes >> ano;
    
    data.setDia(dia);
    data.setMes(mes);
    data.setAno(ano);

    return is;
}

void Data::imprime()
{
    std::cout<< this;
}