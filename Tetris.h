#include <iostream>
using namespace std;

#ifndef TETRIS_H
#define TETRIS_H

/*Funções globais genéricas que foram ultilizadas na implementação da classe*/

/*Realocação de vetor*/
template <class Type>
void realocaVetor(Type *&vetor, int &tamanho, int novoTamanho)
{
    Type *novoVetor = new Type[novoTamanho];

    for (int i = 0; i < novoTamanho; i++)
    {
        if (i >= tamanho)
        {
            novoVetor[i] = Type();
            continue;
        }
        novoVetor[i] = vetor[i];
    }
    tamanho = novoTamanho;

    if (vetor)
    {
        delete[] vetor;
    }
    vetor = novoVetor;
}

/*Troca*/
template <class Type>
void swap(Type *&a, Type *&b)
{
    Type *c = a;
    a = b;
    b = c;
}

/*Inverte Linhas da Matriz*/
template <class Type>
void inverteLinhaMatriz(Type **matriz, int altura)
{
    for (int i = 0; i < altura / 2; i++)
    {
        swap(matriz[i], matriz[altura - 1 - i]);
    }
}

/*Inverte coluna matriz*/
template <class Type>
void inverteColunaMatriz(Type **matriz, int altura, int largura)
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < (largura / 2); j++)
        {
            swap(matriz[i][j], matriz[i][largura - j - 1]);
        }
    }
}

/*Rotacao de Matriz*/
template <class Type>
Type **rotacionaMatriz(Type **matriz, int &altura, int &largura, int rotacao)
{
    if (rotacao == 0 || rotacao == 360)
    {
        //printCerr(matriz, altura, largura, "rotacao = 0");
        return matriz;
    }

    if (rotacao == 90)
    {
        Type **novaMatriz = new Type *[largura];
        for (int i = 0; i < largura; i++)
        {
            novaMatriz[i] = new Type[altura];
        }

        inverteLinhaMatriz(matriz, altura);

        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                novaMatriz[j][i] = matriz[i][j];
            }
        }

        for (int i = 0; i < altura; i++)
        {
            delete[] matriz[i];
        }
        delete[] matriz;

        swap(altura, largura);

        //printCerr(novaMatriz, altura, largura, "rotacao = 90");
        return novaMatriz;
    }

    if (rotacao == 180)
    {
        inverteColunaMatriz(matriz, altura, largura);
        inverteLinhaMatriz(matriz, altura);

        //printCerr(matriz, altura, largura, "rotacao = 180");
        return matriz;
    }

    if (rotacao == 270)
    {
        matriz = rotacionaMatriz(matriz, altura, largura, 90);
        inverteColunaMatriz(matriz, altura, largura);
        inverteLinhaMatriz(matriz, altura);

        //printCerr(matriz, altura, largura, "rotacao = 270");
        return matriz;
    }
}

/*Declaração classe peça*/
class Peca
{
private:
    char **forma;
    int altura;
    int largura;
    char id;

public:
    
    /*Costrutor de peça com argumentos, recebe um matriz, altura, largura e id*/
    Peca(char **forma, int altura, int largura, char id);

    /*Construtor de cópia, copia uma peça usando o operador de atribuição*/
    Peca(const Peca& peca);

    /*Costrutor vazio para criação de vetor*/
    Peca();
    
    /*Destrutor de peça, chama a função destroi*/
    ~Peca();

    /*Operador de atribuição, recebe uma peça e copia*/
    Peca &operator=(const Peca &peca);

    /*Método de rotação, ultiliza as funções genéricas para rotacionar a matriz*/
    Peca& rotaciona(int rotacao);

    /*Retorna o caracter referente a uma dada posição da peça*/
    char get(int i, int j);

    int getAltura() const { return this->altura; }
    int getLargura() const { return this->largura; }

private:
    /*Desaloca a classe peça*/
    void destroi();
};


/*Declaração classe tetris*/
class Tetris
{
private:
    char **jogo;
    int *alturas;
    int largura;
    Peca *pecas;

public:
    
    /*Costrutor com argumento, recebe a largura do jogo*/
    Tetris(int largura);

    /*Operador de atribuição, recebe um jogo, e copia*/
    Tetris &operator=(const Tetris &other);

    /*Construtor de cópia, recebe um jogo e copia usando a função de atribuição*/
    Tetris(const Tetris &other);

    /*Desaloca a classe Tetris, chamando a função destroi*/
    ~Tetris();

    /*Método get, recebe uma linha e coluna e retorna caso exista o caracter da peça nesse
    local, caso contrario retorna ' '*/
    char get(int coluna, int linha) const;

    /*Método remove coluna, remove uma dada coluna do jogo*/
    void removeColuna(int coluna);

    /*Método removeLinhasCompletas, remove todos os pixels do jogo que estiverem em
    linhascompletas (linhas que não contém espaço em branco). Ao remover uma linha
    completa os pixels acima de tal linha são “deslocados para baixo”.*/
    int removeLinhasCompletas();

    /*Método getNumColunas, retorna o número de colunas (largura) do jogo Tetris.*/
    int getNumColunas() const;

    /*Método getAltura, retorna a altura da coluna c do jogo. A altura de uma
    coluna é igual altura do pixel (não vazio) mais alto da coluna. Uma coluna onde
    todos os pixels são vazios possui altura 0.*/
    int getAltura(int coluna) const;

    /*Método getAltura: retorna a altura maxima do jogo atual.*/
    int getAltura() const;

    /*Método adicionaForma, recebe como argumentos: coluna (um inteiro), linha
    (inteiro), o id de uma peca (umccaractere) e uma rotacao (um inteiro que pode
    valer 0, 90, 180 ou 270), e verifica se tal peça pode ser adicionada ao jogo,
    caso possivel adiciona e retorna true, caso contrário, retorna false*/
    bool adicionaForma(int coluna, int linha, char id, int rotacao);

    /*Para uso do visual*/
    Peca getPeca(char id);

private:
    /*Desaloca a classe Tetris*/    
    void destroi();

    /*Define pecas*/
    void alocaPecas();

    /*Retorna indice da peça de acordo com o id*/
    int id(char id);

};

#endif