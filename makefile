debug: Tetris Jogo
	g++ Tetris.o Jogo.o -g -o Tetris.out

compile: Tetris Jogo
	g++ Tetris.o Jogo.o -o Tetris.out

Tetris: Tetris.h Tetris.cpp
	g++ -c Tetris.cpp

Jogo: jogoTetris.cpp
	g++ -c jogoTetris.cpp
