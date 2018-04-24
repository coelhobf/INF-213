#include <iostream>
using namespace std;

#ifndef TETRIS_H
#define TETRIS_H

/*Realocação de vetor*/
template<class Type>
Type* realocaVetor(Type* vetor, int &tamanho, int novoTamanho)
{
    Type* novoVetor = new Type[novoTamanho];
    
    for(int i=0; i < novoTamanho; i++)
    {
        if(i >= tamanho)
        {
            novoVetor[i] = Type();
            continue;
        }
        novoVetor[i] = vetor[i];
    }
    tamanho = novoTamanho;

    delete [] vetor;
    return novoVetor;
}

/*Troca*/
template<class Type>
void swap(Type *a, Type *b)
{
    Type *c = a;
    a = b;
    b = c;
}
/*template<class Type>
void swap(Type &a, Type &b)
{
    Type &c = a;
    a = b;
    b = c;
}*/


/*Inverte Linhas da Matriz*/
template<class Type>
void inverteLinhaMatriz(Type **matriz, int altura)
{
    for(int i=0; i<altura/2; i++)
    {
        swap(matriz[i], matriz[altura-1-i]);
    }
}

/*Inverte coluna matriz*/
template<class Type>
void inverteColunaMatriz(Type **matriz, int altura, int largura)
{
    for(int i=0; i < altura; i++)
    {
        for(int j=0; j < (largura/2); j++)
        {
            matriz[i][j] = matriz[i][largura-j-1];
        }
    }
}

/*Rotacao de Matriz*/
template<class Type>
Type** rotacionaMatriz(Type** matriz, int &altura, int &largura, int rotacao)
{
    if(rotacao == 0 || rotacao == 360)
    {
        return matriz;
    }
    
    if(rotacao == 90)
    {
        Type ** novaMatriz = new Type *[largura];
        for(int i=0; i<largura; i++)
        {
            novaMatriz[i] = new Type[altura];
        }

        inverteLinhaMatriz(matriz, altura);
        for(int i=0; i<altura; i++)
        {
            for(int j=0; j<largura; j++)
            {
                novaMatriz[j][i] = matriz[i][j];
            }
        }

        for(int i=0; i<altura; i++)
        {
            delete [] matriz[i];
        }
        delete [] matriz;

        swap(altura, largura);

        return novaMatriz;
    }

    if(rotacao == 180)
    {
        inverteColunaMatriz(matriz, altura, largura);
        inverteLinhaMatriz(matriz, altura);

        return matriz;
    }

    if(rotacao == 270)
    {
        matriz = rotacionaMatriz(matriz, altura, largura, 90);
        inverteColunaMatriz(matriz, altura, largura);
        inverteLinhaMatriz(matriz, altura);

        return matriz;
    }
}


struct Peca
{
    char **forma;
    int altura;
    int largura;
    char id;

    Peca(char **forma, int altura, int largura, char id)
    {
        this->forma = forma;
        this->altura = altura;
        this->largura = largura;
        this->id = id;
    }

    Peca(){}

    ~Peca()
    {
        destroi();
    }

    Peca(Peca &peca)
    {
        this->forma = NULL;
        this->altura = 0;
        this->largura = 0;
        *this = peca;
    }

    Peca& operator=(const Peca &peca)
    {
        if(this == &peca)
        {
            return *this;
        }
        destroi();

        this->id = peca.id;
        this->altura = peca.altura;
        this->largura = peca.largura;

        this->forma = new char *[this->altura];
        for(int i=0; i < altura; i++)
        {
            this->forma[i] = new char [this->largura];
            for(int j=0; j < largura; j++)
            {
                this->forma[i][j] = peca.forma[i][j];
            }
        }

        return *this;
    }

    void destroi()
    {
        /*for(int i=0; i<this->altura; i++)
        {
            delete [] this->forma[i];
        }
        delete [] this->forma;*/
        //VERIFICAR DEPOIS
    }

    Peca& rotaciona(int rotacao)
    {
        this->forma = rotacionaMatriz(this->forma, this->altura, this->largura, rotacao);
        return *this;
    }
};

class Tetris
{
private:
    char **jogo;
    int *alturas;
    int largura;

    Peca *pecas;

public:

    /*Construtor com um argumento: o argumento do construtor será um inteiro indicando
    a largura (numero de colunas) do jogo Tetris que será representado.*/
    Tetris(int largura)
    {
        this->jogo = new char *[largura];
        this->alturas = new int[largura];
        this->largura = largura;

        for(int i=0; i<largura; i++)
        {
            this->jogo[i] = NULL;
            this->alturas[i] = 0;
        }

        this->alocaPecas();
    }

    void destroi()
    {
        delete [] this->pecas;
        delete [] this->alturas;
        for(int i=0; i < this->largura; i++)
        {
            delete [] this->jogo[i];
        }
        delete [] this->jogo;
    }

    Tetris& operator=(const Tetris& other)
    {
        if(this == &other)
        {
            return *this;
        }
        destroi();

        this->largura = other.largura;
        this->alturas = new int[this->largura];
        this->jogo = new char *[this->largura];

        for(int i=0; i < this->largura; i++)
        {
            this->alturas[i] = other.alturas[i];
            if(this->alturas[i] == 0)
            {
                continue;
            }
            this->jogo[i] = new char [this->alturas[i]];
            for(int j=0; j < this->alturas[i]; j++)
            {
                this->jogo[i][j] = other.jogo[i][j];
            }
        }

        this->alocaPecas();

        return *this;
    }

    Tetris(const Tetris& other)
    {
        this->alturas = NULL;
        this->jogo = NULL;
        *this = other;
    }
    
    /*Método get(int c,int l): recebe dois argumentos: a coluna (primeiro argumento)
    e a linha(segundo argumento) de um pixel e retorna um caractere que representa o
    estado de tal pixelno jogo atual.*/
    char get(int coluna, int linha) const
    {
        if(this->jogo[coluna] != NULL && linha < this->alturas[coluna])
        {
            return this->jogo[coluna][linha];
        }
        else
        {
            return char(' ');
        }
    }

    /*Método removeColuna(char c): dado o índice c de
    uma coluna (0<= c < número de colunas),remove a coluna do jogo (diminuindo, assim,
    sua largura).*/
    void removeColuna(int coluna)
    {
        if(this->jogo[coluna] != NULL)
        {
            delete [] this->jogo[coluna];
        }
        
        for(int i = coluna; i < this->largura; i++)
        {
            this->jogo[i] = this->jogo[i+1];
            this->alturas[i] = this->alturas[i+1];
        }

        this->jogo = realocaVetor(this->jogo, this->largura, this->largura-1);
        this->alturas = realocaVetor(this->alturas, this->largura, this->largura-1);

        this->largura--;
    }
    
    /*Método removeLinhasCompletas: remove todos os pixels do jogo que estiverem em
    linhascompletas (linhas que não contém espaço em branco). Ao remover uma linha
    completa ospixels acima de tal linha são “deslocados para baixo”.*/
    void removeLinhasCompletas()
    {
        int linhaRemover;

        for(int j=0; j < this->alturas[0]; j++)
        {
            for(int i=0; i < this->largura; i++)
            {
                if(j < this->alturas[i])
                {
                    //cout<< this->jogo[i][j] << " ";
                }
                else
                {
                    //cout<< "  ";
                }  
            }
            //cout<< endl;
        }
    }
    
    /*Método getNumColunas: retorna o número de colunas (largura) do jogo Tetris.
    Esse númerodeverá ser igual ao valor passado pelo construtor do jogo (a não ser
    que algumas colunastenham sido removidas utilizando o método removeColuna).*/
    int getNumColunas() const
    {
        return this->largura;
    }
    
    /*Método getAltura(int c): retorna a altura da coluna c do jogo. A altura de uma
    coluna e’ igual aaltura do pixel (não vazio) mais alto da coluna. Uma coluna onde
    todos os pixels são vazios possui altura 0.*/
    int getAltura(int coluna) const
    {
        if(coluna < this->largura)
        {
            return this->alturas[coluna];
        }
        else
        {
            return 0;
        }
    }
    
    /*Método getAltura: retorna a altura maxima do jogo atual.*/
    int getAltura() const
    {
        int max = this->alturas[0];
        for(int i=0; i <  this->largura; i++)
        {
            if(this->alturas[i] > max)
            {
                max = this->alturas[i];
            }
        }

        return max;
    }

    /*Retorna indice da peça de acordo com o id*/
    int id(char id)
    {
        switch(id)
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
    
    /*Método adicionaForma(int coluna,int linha,char id, int rotacao): método mais
    importante dasua classe. Recebe como argumentos: coluna (um inteiro), linha
    (inteiro), o id de uma peca (umcaractere) e uma rotacao (um inteiro que pode
    valer 0, 90, 180 ou 270).*/
    bool adicionaForma(int coluna, int linha, char id, int rotacao)
    {
        Peca forma = this->pecas[this->id(id)];
        forma.rotaciona(rotacao).rotaciona(90);

        for(int i=0; i < forma.altura; i++)
        {
            for(int j=0; j < forma.largura; j++)
            {
                if(forma.forma[i][j] != ' ' && this->get(i, j) != ' ')
                {
                    return false;
                }
            }
        }

        for(int i=0; i < forma.altura; i++)
        {
            int nTam = largura + forma.largura + (forma.forma[i][largura-1] == ' ' ? -1 : 0);
            this->jogo[i+coluna] = realocaVetor(this->jogo[i+coluna], this->alturas[i+coluna], nTam);
            for(int j=0; j < forma.largura; j++)
            {
                this->jogo[i+coluna][j+largura] = forma.forma[i][j];
            }
        }
    }

    /*Define pecas*/
    void alocaPecas()
    {
        this->pecas = new Peca[7];

        /*Peça I*/
        char **i = new char *[4];
        i[0] =  new char[1] {'I'};
        i[1] =  new char[1] {'I'};
        i[2] =  new char[1] {'I'};
        i[3] =  new char[1] {'I'};
        this->pecas[0] = Peca(i, 4, 1, 'I');

        /*Peça J*/
        char **j = new char *[2];
        j[0] =  new char[4] {'J','J','J','J'};
        j[1] =  new char[4] {' ',' ',' ','J'};
        this->pecas[1] = Peca(j, 2, 4, 'J');

        /*Peça L*/
        char **l = new char *[2];
        l[0] =  new char[4] {'L','L','L','L'};
        l[1] =  new char[4] {'L',' ',' ',' '};
        this->pecas[2] = Peca(l, 2, 4, 'L');

        /*Peça O*/
        char **o = new char *[2];
        o[0] = new char[2] {'O','O'};
        o[1] = new char[2] {'O','O'};
        this->pecas[3] = Peca(o, 2, 2, 'O');

        /*Peça S*/
        char **s = new char *[2];
        s[0] = new char[3] {' ','S','S'};
        s[1] = new char[3] {'S','S',' '};
        this->pecas[4] = Peca(s, 2, 3, 'S');

        /*Peça T*/
        char **t = new char *[2];
        t[0] = new char[3] {'T','T','T'};
        t[1] = new char[3] {' ',' ','T'};
        this->pecas[5] = Peca(t, 2, 3, 'T');

        /*Peça Z*/
        char **z = new char *[2];
        z[0] = new char[3] {'Z','Z',' '};
        z[1] = new char[3] {' ','Z','Z'};
        this->pecas[6] = Peca(z, 2, 3, 'Z');
    }

    /*Desalocar Peças*/
    void desalocaPecas()
    {
        delete [] this->pecas;
    }
};

#endif