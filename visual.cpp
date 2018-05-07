#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include "Tetris.h"

using namespace std;

void exibeJogo(WINDOW *win, const Tetris &jogo, int largura, int altura)
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            switch (jogo.get(j, altura - i - 1))
            {
            case 'I':
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(1));

            case 'J':
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(2));

            case 'L':
                wattron(win, COLOR_PAIR(3));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(3));

            case 'O':
                wattron(win, COLOR_PAIR(4));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(4));

            case 'S':
                wattron(win, COLOR_PAIR(5));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(5));

            case 'T':
                wattron(win, COLOR_PAIR(6));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(6));

            case 'Z':
                wattron(win, COLOR_PAIR(7));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(7));

            case ' ':
                wattron(win, COLOR_PAIR(8));
                mvwprintw(win, i + 1, j + 1, "%c", jogo.get(j, altura - i - 1));
                wattroff(win, COLOR_PAIR(8));
            }
        }
    }
}

void exibeHigh(WINDOW *win, int &atual, int &max)
{
    if (atual > max)
    {
        max = atual;
    }
    int oM = max, oA = atual;

    mvwprintw(win, 1, 2, "TETRIS");
    mvwprintw(win, 3, 2, "S:");
    mvwprintw(win, 4, 2, "H:");
    
    if(atual > 0)
    {
        mvwprintw(win, 3, 4, "%c", ' ');    
    }
    else
    {
        mvwprintw(win, 3, 4, "%c", '-');
        atual *= -1;
    }

    mvwprintw(win, 3, 5, "%d", (atual / 100));
    mvwprintw(win, 3, 6, "%d", ((atual % 100) / 10));
    mvwprintw(win, 3, 7, "%d", ((atual % 100) % 10));

    mvwprintw(win, 4, 5, "%d", (max / 100));
    mvwprintw(win, 4, 6, "%d", ((max % 100) / 10));
    mvwprintw(win, 4, 7, "%d", ((max % 100) % 10));

    max = oM; atual = oA;
}

void exibeProx(WINDOW *win, char id)
{
    Peca p = Tetris(0).getPeca(id);

    mvwprintw(win, 1, 3, "PROX");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i < p.getAltura() && j < p.getLargura())
            {
                mvwprintw(win, 3 + i, 3 + j, "%c", p.get(i, j));
            }
            else
            {
                mvwprintw(win, 3 + i, 3 + j, "%c", ' ');
            }
        }
    }
}

int main()
{
    // Pontuação:
    int atual = 0, max = 0;

    initscr();
    start_color();

    // Cores das pecas
    init_pair(1, 0, 6);
    init_pair(2, 1, 7);
    init_pair(3, 2, 0);
    init_pair(4, 3, 1);
    init_pair(5, 4, 2);
    init_pair(6, 5, 3);
    init_pair(7, 6, 4);
    init_pair(8, 7, 5); //preto

    init_pair(9, 7, 0);

    cbreak();

    WINDOW *wJogo = newwin(22, 12, 0, 0);
    WINDOW *wHigh = newwin(12, 10, 0, 12);
    WINDOW *wProx = newwin(10, 10, 12, 12);
    refresh();

    box(wJogo, 0, 0);
    box(wHigh, 0, 0);
    box(wProx, 0, 0);

    wrefresh(wJogo);
    wrefresh(wHigh);
    wrefresh(wProx);


    srand(time(0));

    const int possiveisRotacoes[] = {0, 90, 180, 270};
    const int larguraJogo = 10;
    const int alturaMaximaJogo = 20;
    Tetris jogo(larguraJogo);
    Tetris jogoComPecaCaindo(larguraJogo);

    int alturaPecaAtual = alturaMaximaJogo;
    int posicaoPecaAtual, rotacaoPecaAtual;

    int ultimaTecla = -1;

    char idPecaAtual = "IJLOSTZ"[rand() % 7];
    char idProxPeca = "IJLOSTZ"[rand() % 7];

    posicaoPecaAtual = larguraJogo / 2 - 2;
    alturaPecaAtual = alturaMaximaJogo;
    rotacaoPecaAtual = 0;

    noecho();
    curs_set(false);
    keypad(stdscr, true);
    cbreak();

    int tecla;

    while (true)
    {
        jogoComPecaCaindo = jogo;

        if (ultimaTecla == KEY_LEFT)
        {
            Tetris jogoTeste = jogoComPecaCaindo;
            if (jogoTeste.adicionaForma(posicaoPecaAtual - 1, alturaPecaAtual, idPecaAtual, possiveisRotacoes[rotacaoPecaAtual]))
            {
                posicaoPecaAtual--;
            }
        }
        else if (ultimaTecla == KEY_RIGHT)
        {
            Tetris jogoTeste = jogoComPecaCaindo;
            if (jogoTeste.adicionaForma(posicaoPecaAtual + 1, alturaPecaAtual, idPecaAtual, possiveisRotacoes[rotacaoPecaAtual]))
            {
                posicaoPecaAtual++;
            }
        }
        else if (ultimaTecla == ' ')
        {
            Tetris jogoTeste = jogoComPecaCaindo;
            if (jogoTeste.adicionaForma(posicaoPecaAtual, alturaPecaAtual, idPecaAtual, possiveisRotacoes[(rotacaoPecaAtual + 1) % 4]))
            {
                rotacaoPecaAtual = (rotacaoPecaAtual + 1) % 4;
            }
        }

        if (jogoComPecaCaindo.adicionaForma(posicaoPecaAtual, alturaPecaAtual - 1, idPecaAtual, possiveisRotacoes[rotacaoPecaAtual]))
        {
            alturaPecaAtual--;
        }
        else
        {
            jogo.adicionaForma(posicaoPecaAtual, alturaPecaAtual, idPecaAtual, possiveisRotacoes[rotacaoPecaAtual]);
            jogoComPecaCaindo = jogo;

            idPecaAtual = idProxPeca;
            idProxPeca = "IJLOSTZ"[rand() % 7];

            posicaoPecaAtual = larguraJogo / 2 - 2;
            alturaPecaAtual = alturaMaximaJogo;
            rotacaoPecaAtual = 0;
            atual += 10 * jogoComPecaCaindo.removeLinhasCompletas();
            atual -= 1;
            jogo = jogoComPecaCaindo;
        }

        exibeJogo(wJogo, jogoComPecaCaindo, larguraJogo, alturaMaximaJogo);
        exibeHigh(wHigh, atual, max);
        exibeProx(wProx, idProxPeca);

        wrefresh(wJogo);
        wrefresh(wHigh);
        wrefresh(wProx);

        ultimaTecla = getch();
        halfdelay(5);
    }
    endwin();
    return 0;
}