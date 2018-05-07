#include "Tetris.h"

/*Implementação da classe peça*/
Peca::Peca(char **forma, int altura, int largura, char id)
{
    this->forma = forma;
    this->altura = altura;
    this->largura = largura;
    this->id = id;
}

Peca::Peca()
{
    this->altura = 0;
    this->forma = 0;
    this->id = '\0';
    this->largura = 0;
}

Peca::~Peca()
{
    this->destroi();
}

Peca::Peca(const Peca &peca)
{
    this->forma = 0;
    this->altura = 0;
    this->largura = 0;
    this->id = '\0';
    *this = peca;
}

Peca &Peca::operator=(const Peca &peca)
{
    if (this == &peca)
    {
        return *this;
    }
    this->destroi();

    this->id = peca.id;
    this->altura = peca.altura;
    this->largura = peca.largura;

    this->forma = new char *[this->altura];
    for (int i = 0; i < this->altura; i++)
    {
        this->forma[i] = new char[this->largura];
        for (int j = 0; j < this->largura; j++)
        {
            this->forma[i][j] = peca.forma[i][j];
        }
    }

    return *this;
}

void Peca::destroi()
{
    if (this->forma)
    {
        for (int i = 0; i < this->altura; i++)
        {
            if (this->forma[i])
            {
                delete[] this->forma[i];
                this->forma[i] = 0;
            }
        }
        delete[] this->forma;
    }
    this->forma = 0;
    this->altura = 0;
    this->largura = 0;
    this->id = '\0';
}

Peca &Peca::rotaciona(int rotacao)
{
    this->forma = rotacionaMatriz(this->forma, this->altura, this->largura, rotacao);
    return *this;
}

char Peca::get(int i, int j)
{
    return this->forma[i][j];
}

/*Implementação da Classe Tetris*/
Tetris::Tetris(int largura)
{
    this->jogo = new char *[largura];
    this->alturas = new int[largura];
    this->largura = largura;

    for (int i = 0; i < largura; i++)
    {
        this->jogo[i] = 0;
        this->alturas[i] = 0;
    }

    this->alocaPecas();
}

void Tetris::destroi()
{
    if (this->pecas)
    {
        delete[] this->pecas;
    }
    for (int i = 0; i < this->largura; i++)
    {
        if (this->jogo[i])
        {
            delete[] this->jogo[i];
        }
    }
    if (this->jogo)
    {
        delete[] this->jogo;
    }
    if (this->alturas)
    {
        delete[] this->alturas;
    }

    this->pecas = 0;
    this->jogo = 0;
    this->alturas = 0;
    this->largura = 0;
}

Tetris &Tetris::operator=(const Tetris &other)
{
    if (this == &other)
    {
        return *this;
    }
    this->destroi();

    this->largura = other.largura;
    this->alturas = new int[this->largura];
    this->jogo = new char *[this->largura];

    for (int i = 0; i < this->largura; i++)
    {
        this->alturas[i] = other.alturas[i];
        if (this->alturas[i] == 0)
        {
            this->jogo[i] = 0;
            continue;
        }
        this->jogo[i] = new char[this->alturas[i]];
        for (int j = 0; j < this->alturas[i]; j++)
        {
            this->jogo[i][j] = other.jogo[i][j];
        }
    }

    this->alocaPecas();

    return *this;
}

Tetris::Tetris(const Tetris &other)
{
    this->alturas = 0;
    this->jogo = 0;
    this->largura = 0;
    this->pecas = 0;
    *this = other;
}

Tetris::~Tetris()
{
    this->destroi();
}

char Tetris::get(int coluna, int linha) const
{
    if (coluna < this->largura && linha < this->alturas[coluna])
    {
        return (this->jogo[coluna][linha] == '\0' ? ' ' : this->jogo[coluna][linha]);
    }
    else
    {
        return char(' ');
    }
}

void Tetris::removeColuna(int coluna)
{
    if (this->jogo[coluna])
    {
        delete[] this->jogo[coluna];
    }

    for (int i = coluna; i < this->largura - 1; i++)
    {
        this->jogo[i] = this->jogo[i + 1];
        this->alturas[i] = this->alturas[i + 1];
    }

    int a, b;
    a = b = this->largura;
    realocaVetor(this->jogo, a, a - 1);
    realocaVetor(this->alturas, b, b - 1);

    this->largura--;
}
/*Alterei pra terornar a quantidade de linhas removidas*/
int Tetris::removeLinhasCompletas()
{
    int removidas = 0;
    int minAlt = this->alturas[0];
    for (int i = 0; i < this->largura; i++)
    {
        if (this->alturas[i] < minAlt)
        {
            minAlt = this->alturas[i];
        }
    }

    for (int j = 0; j < minAlt; j++)
    {
        bool remove = true;
        for (int i = 0; i < this->largura; i++)
        {
            if (this->get(i, j) == ' ')
            {
                remove = false;
            }
        }

        if (remove)
        {
            removidas++;
        }
        else
        {
            continue;
        }

        for (int i = 0; i < this->largura; i++)
        {
            for (int k = 0; k < this->alturas[i] - 1; k++)
            {
                if (k >= j)
                {
                    this->jogo[i][k] = this->jogo[i][k + 1];
                }
            }
            realocaVetor(this->jogo[i], this->alturas[i], this->alturas[i] - 1);
        }
        j--;
    }

    return removidas;
}

int Tetris::getNumColunas() const
{
    return this->largura;
}

int Tetris::getAltura(int coluna) const
{
    if (coluna < this->largura)
    {
        return this->alturas[coluna];
    }
    else
    {
        return 0;
    }
}

int Tetris::getAltura() const
{
    int max = this->alturas[0];
    for (int i = 0; i < this->largura; i++)
    {
        if (this->alturas[i] > max)
        {
            max = this->alturas[i];
        }
    }

    return max;
}

int Tetris::id(char id)
{
    switch (id)
    {
    case 'I':
        return 0;
    case 'J':
        return 1;
    case 'L':
        return 2;
    case 'O':
        return 3;
    case 'S':
        return 4;
    case 'T':
        return 5;
    case 'Z':
        return 6;
    }
}

bool Tetris::adicionaForma(int coluna, int linha, char id, int rotacao)
{
    Peca p = this->pecas[this->id(id)];
    p.rotaciona(rotacao);

    for (int i = 0; i < p.getAltura(); i++)
    {
        for (int j = 0; j < p.getLargura(); j++)
        {
            int nC = coluna + j, nL = linha - i;

            if (nL < 0 || nC < 0 || nC >= this->largura)
            {
                return false;
            }
            if (p.get(i, j) != ' ' && this->get(nC, nL) != ' ')
            {
                return false;
            }
        }
    }

    for (int i = 0; i < p.getAltura(); i++)
    {
        for (int j = 0; j < p.getLargura(); j++)
        {
            int nC = coluna + j, nL = linha - i;

            int nT = linha + 1 + (p.get(0, j) == ' ' ? -1 : 0);

            if (nT > this->getAltura(nC))
            {
                realocaVetor(this->jogo[nC], this->alturas[nC], nT);
            }

            if (p.get(i, j) != ' ')
            {
                this->jogo[nC][nL] = p.get(i, j);
            }
        }
    }

    return true;
}

/*Define pecas*/
void Tetris::alocaPecas()
{
    this->pecas = new Peca[7];

    /*Peça I*/
    char **i = new char *[4];
    i[0] = new char[1]{'I'};
    i[1] = new char[1]{'I'};
    i[2] = new char[1]{'I'};
    i[3] = new char[1]{'I'};
    this->pecas[0] = Peca(i, 4, 1, 'I');

    /*Peça J*/
    char **j = new char *[2];
    j[0] = new char[4]{'J', 'J', 'J', 'J'};
    j[1] = new char[4]{' ', ' ', ' ', 'J'};
    this->pecas[1] = Peca(j, 2, 4, 'J');

    /*Peça L*/
    char **l = new char *[2];
    l[0] = new char[4]{'L', 'L', 'L', 'L'};
    l[1] = new char[4]{'L', ' ', ' ', ' '};
    this->pecas[2] = Peca(l, 2, 4, 'L');

    /*Peça O*/
    char **o = new char *[2];
    o[0] = new char[2]{'O', 'O'};
    o[1] = new char[2]{'O', 'O'};
    this->pecas[3] = Peca(o, 2, 2, 'O');

    /*Peça S*/
    char **s = new char *[2];
    s[0] = new char[3]{' ', 'S', 'S'};
    s[1] = new char[3]{'S', 'S', ' '};
    this->pecas[4] = Peca(s, 2, 3, 'S');

    /*Peça T*/
    char **t = new char *[2];
    t[0] = new char[3]{'T', 'T', 'T'};
    t[1] = new char[3]{' ', 'T', ' '};
    this->pecas[5] = Peca(t, 2, 3, 'T');

    /*Peça Z*/
    char **z = new char *[2];
    z[0] = new char[3]{'Z', 'Z', ' '};
    z[1] = new char[3]{' ', 'Z', 'Z'};
    this->pecas[6] = Peca(z, 2, 3, 'Z');
}

Peca Tetris::getPeca(char id)
{
    return this->pecas[this->id(id)];
}
