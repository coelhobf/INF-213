#include <string>
#include "Data.h"
#include "Horario.h"

class ItemAgenda
{
private:
    string descricao;
    Data data;
    Horario horario;

public:
    ItemAgenda();
    ItemAgenda(const string &descricao, const Data &data, const Horario &horario);
    ItemAgenda(const ItemAgenda &itemAgenda);
    void setDescricao(const string &descricao);
    void setData(const Data &data);
    void setHorario(const Horario &horario);
    const string& getDescricao();
    const Data& getData();
    const Horario& getHorario();
};