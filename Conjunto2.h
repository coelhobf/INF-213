#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
using namespace std;

#pragma region ClassDefinition
template <class Type> class Conjunto;

template <class Type> ostream &operator<<(ostream &,const Conjunto<Type> &conj);
template <class Type> istream &operator>>(istream &, Conjunto<Type> &conj);

template <class Type> class Conjunto
{
private:
    Type *elementos;
    int num_elementos;
    int tam_array;

public:
    Conjunto(int = 10);
    Conjunto(const Conjunto&);
    ~Conjunto();

    bool pertence(const Type&) const;
    bool insere(const Type&);

    int numelementos() const;
    int tamanhoarray() const;

    Type operator[](int i) const;
    bool operator==(Conjunto&);
    Conjunto<Type>& operator=(const Conjunto&);

    friend ostream &operator<< <Type>(ostream &,const Conjunto<Type> &conj);
    friend istream &operator>> <Type>(istream &, Conjunto<Type> &conj);

    Conjunto<Type> operator+(const Conjunto<Type> &b) const;
    Conjunto<Type> operator*(const Conjunto<Type> &b) const;
    Conjunto<Type> operator-(const Conjunto<Type> &b) const;
};

#pragma endregion

#pragma region ClassImplementation

template <class Type>
Conjunto<Type>::Conjunto(int tam)
{
    this->elementos = new Type[tam];
    this->tam_array = tam;
    this->num_elementos = 0;
}

template <class Type>
Conjunto<Type>::Conjunto(const Conjunto &other)
{
    this->tam_array = other.tamanhoarray();
    this->num_elementos = other.numelementos();
    this->elementos = new Type [this->tam_array];
    for(int i = 0; i < this->num_elementos; i++)
    {
        this->elementos[i] = other[i];
    }
}

template <class Type>
Conjunto<Type>::~Conjunto()
{
    delete [] this->elementos;
}

template <class Type>
bool Conjunto<Type>::pertence(const Type &element) const
{
    for(int i = 0; i < this->num_elementos; i++)
    {
        if(this->elementos[i] == element)
        {
            return true;
        }
    }
    return false;
}

template <class Type>
bool Conjunto<Type>::insere(const Type &element)
{
    if(this->pertence(element))
    {
        return false;
    }
    else if(this->num_elementos < this->tam_array)
    {
        this->elementos[this->num_elementos] = element;
        this->num_elementos++;
        return true;
    }
    else
    {
        return false;
    }
}

template <class Type>
int Conjunto<Type>::numelementos() const
{
    return this->num_elementos;
}

template <class Type>
int Conjunto<Type>::tamanhoarray() const
{
    return this->tam_array;
}

template <class Type>
Type Conjunto<Type>::operator[](int i) const
{
    return this->elementos[i];
}

template <class Type>
bool Conjunto<Type>::operator==(Conjunto &other)
{
    int tamanho = this->numelementos();
    if(this->numelementos() != other.numelementos())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < tamanho; i++)
        {
            if(!this->pertence(other[i]))
            {
                return false;
            }
        }
    }

    return true;
}

template <class Type>
Conjunto<Type>& Conjunto<Type>::operator=(const Conjunto &other)
{
    this->tam_array = other.tamanhoarray();
    this->num_elementos = other.numelementos();
    delete [] this->elementos;
    this->elementos = new Type [this->tam_array];
    for(int i = 0; i < this->num_elementos; i++)
    {
        this->elementos[i] = other[i];
    }

    return *this;
}

template <class Type>
ostream &operator<<(ostream &out,const Conjunto<Type> &conj)
{
    out<< "{";
    for(int i = 0; i < conj.numelementos() - 1; i++)
    {
        out<< conj[i] << ",";
    }
    out<< conj[conj.numelementos() - 1] << "}";

    return out;
}

template <class Type>
istream &operator>>(istream &in, Conjunto<Type> &conj)
{
    Type item;
    cin.ignore();

    do {
        cin.get(item);
        if(item != '\n' && item != ' ')
        {
            conj.insere(item);
        }
    } while(item != '\n');

    return in;
}

template <class Type>
Conjunto<Type> Conjunto<Type>::operator+(const Conjunto<Type> &b) const
{
    Conjunto<Type> conj(this->tamanhoarray() + b.tamanhoarray());
    int tam = this->numelementos();
    for(int i = 0; i < tam; i++)
    {
        conj.insere((*this)[i]);
    }

    tam = b.numelementos();
    for(int i = 0; i < tam; i++)
    {
        conj.insere(b[i]);
    }

    return conj;
}

template <class Type>
Conjunto<Type> Conjunto<Type>::operator*(const Conjunto<Type> &b) const
{
    int tam;
    if(this->tamanhoarray() < b.tamanhoarray())
        { tam = this->tamanhoarray(); } else
        { tam = b.tamanhoarray(); }

    Conjunto<Type> conj(tam);
    int num = this->numelementos();
    for(int i = 0; i < num; i++)
    {
        if(b.pertence((*this)[i]))
        {
            conj.insere((*this)[i]);
        }
    }

    return conj;
}

template <class Type>
Conjunto<Type> Conjunto<Type>::operator-(const Conjunto<Type> &b) const
{
    Conjunto<Type> conj(this->tamanhoarray());
    int tam = this->numelementos();
    for(int i = 0; i < tam; i++)
    {
        if(!b.pertence((*this)[i]))
        {
            conj.insere((*this)[i]);
        }
    }

    return conj;
}

#pragma endregion

#endif