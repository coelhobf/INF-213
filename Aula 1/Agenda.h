#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "Data.h"
#include "Horario.h"

class ItemAgenda
{
private:
    std::string descricao;
    Data data;
    Horario horario;

public:
    ItemAgenda();
    ItemAgenda(const std::string &descricao, const Data &data, const Horario &horario);
    ItemAgenda(const ItemAgenda &itemAgenda);
    void setDescricao(const std::string &descricao);
    void setData(const Data &data);
    void setHorario(const Horario &horario);
    const std::string& getDescricao() const;
    const Data& getData() const;
    const Horario& getHorario() const;
};

class Agenda
{
private:
    ItemAgenda itens[1000];
    int quantItens;

public:
    Agenda();
    void inserirItem(const ItemAgenda &item);
    void compromissosData(const Data &data) const;
};

#endif