#include "Agenda.h"
#include <string>

ItemAgenda::ItemAgenda() { }

ItemAgenda::ItemAgenda(const std::string &descricao, const Data &data, const Horario &horario)
{
    this->descricao = descricao;
    
    this->data.setDia(data.getDia());
    this->data.setMes(data.getMes());
    this->data.setAno(data.getAno());

    this->horario.setHora(horario.getHora());
    this->horario.setMinuto(horario.getMinuto());
    this->horario.setSegundo(horario.getSegundo());
}

ItemAgenda::ItemAgenda(const ItemAgenda &itemAgenda)
{
    this->descricao = itemAgenda.getDescricao();
    this->data = itemAgenda.getData();
    this->horario = itemAgenda.getHorario();
}

void ItemAgenda::setDescricao(const std::string &descricao)
{
    this->descricao = descricao;
}

void ItemAgenda::setData(const Data &data)
{
    this->data.setDia(data.getDia());
    this->data.setMes(data.getMes());
    this->data.setAno(data.getAno());
}

void ItemAgenda::setHorario(const Horario &horario)
{
    this->horario.setHora(horario.getHora());
    this->horario.setMinuto(horario.getMinuto());
    this->horario.setSegundo(horario.getSegundo());
}

const std::string& ItemAgenda::getDescricao() const
{
    return this->descricao;
}

const Data& ItemAgenda::getData() const
{
    return this->data;
} 

const Horario& ItemAgenda::getHorario() const
{
    return this->horario;
}

// Classe Agenda

Agenda::Agenda()
{
    this->quantItens = 0;
}

void Agenda::inserirItem(const ItemAgenda &item)
{
    this->itens[quantItens] = item;

    this->quantItens++;
}

void Agenda::compromissosData(const Data &data) const
{
    for(int i=0; i < quantItens; i++)
    {
        if(itens[i].getData().compData(data) == 0)
        {
            std::cout<< itens[i].getHorario() << " " << itens[i].getDescricao() << std::endl;
        }
    }
} 