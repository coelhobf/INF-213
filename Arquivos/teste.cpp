#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include "Tetris.h"

using namespace std;

bool imprime = true;

void exibeJogo(const Tetris &jogoComPecaCaindo,int larguraJogo,int alturaMaximaJogo)
{
	for(int i=0;i<alturaMaximaJogo;i++)
	{
		mvprintw(i, 0, "|");
		for(int j=0;j<larguraJogo;j++)
		{   
            mvprintw(i, j+1, "%c",jogoComPecaCaindo.get(j,alturaMaximaJogo-i-1));
		}
		mvprintw(i, larguraJogo+1, "|");
	}
	for(int j=0;j<larguraJogo;j++)
	{
			mvprintw(alturaMaximaJogo, j+1, "-");
			mvprintw(alturaMaximaJogo+1, j+1, "%d", jogoComPecaCaindo.getAltura(j)/10);
			mvprintw(alturaMaximaJogo+2, j+1, "%d", jogoComPecaCaindo.getAltura(j)%10);
	}
    imprime = false;
}

int main()
{
    Tetris jogo(16);

    initscr(); 
	noecho(); 
	curs_set(false);
	keypad(stdscr,true);
	cbreak();

    int l =4;
    bool t[l];

    t[0] = jogo.adicionaForma(4, 19, 'J', 0);
    t[1] = jogo.adicionaForma(0, 0, 'I', 90);
    t[2] = jogo.adicionaForma(7, 7, 'S', 90);
    t[3] = jogo.adicionaForma(1, 3, 'Z', 0);

    for(int i=0; i<l; i++)
    {
        cerr<< t[i] << endl;
    }

    halfdelay(5);

    while(true)
    {
        exibeJogo(jogo,16,20);

        refresh();
    }

    endwin();
}