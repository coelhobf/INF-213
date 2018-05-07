#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include "Tetris.h"

using namespace std;

void exibeJogo(const Tetris &jogoComPecaCaindo,int larguraJogo,int alturaMaximaJogo)
{
    for(int j=0; j<larguraJogo+2; j++)
    {
        cout<< '-';
    }
    cout<< endl;
	for(int i=0;i<alturaMaximaJogo;i++)
	{
        cout<< '|';
		for(int j=0;j<larguraJogo;j++)
		{   
            cout<< jogoComPecaCaindo.get(j, alturaMaximaJogo-i-1);
		}
		cout<< '|' << endl;
	}
    for(int j=0; j<larguraJogo+2; j++)
    {
        cout<< '-';
    }
    cout<< endl;
    cout<< ' ';
	for(int j=0;j<larguraJogo;j++)
    {
        cout<< jogoComPecaCaindo.getAltura(j)/10;
	}
    cout<< endl;
    cout<< ' ';
    for(int j=0; j<larguraJogo; j++)
    {
        cout<< jogoComPecaCaindo.getAltura(j)%10;
    }
    cout<< endl;
}

int main()
{
    Tetris jogo(17);
    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 0, 'I', 270) << endl;
    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    jogo.removeLinhasCompletas();
    jogo.removeColuna(16);

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 1, 'I', 90) << endl;
    cout<< jogo.adicionaForma(4, 0, 'I', 90) << endl;
    cout<< jogo.adicionaForma(8, 0, 'I', 90) << endl;
    cout<< jogo.adicionaForma(12, 0, 'I', 90) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(4, 1, 'I', 90) << endl;
    cout<< jogo.adicionaForma(8, 1, 'I', 90) << endl;
    cout<< jogo.adicionaForma(12, 1, 'I', 90) << endl;    

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 2, 'I', 90) << endl;
    cout<< jogo.adicionaForma(4, 2, 'I', 90) << endl;
    cout<< jogo.adicionaForma(8, 2, 'I', 90) << endl;
    cout<< jogo.adicionaForma(12, 2, 'I', 90) << endl;
    cout<< jogo.adicionaForma(8, 3, 'I', 90) << endl;
    cout<< jogo.adicionaForma(0, 4, 'I', 90) << endl;
    cout<< jogo.adicionaForma(4, 4, 'I', 90) << endl;
    cout<< jogo.adicionaForma(8, 4, 'I', 90) << endl;
    cout<< jogo.adicionaForma(12, 4, 'I', 90) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(10, 5, 'I', 90) << endl;
    cout<< jogo.adicionaForma(1, 5, 'I', 90) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    jogo.removeLinhasCompletas();

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());    

}