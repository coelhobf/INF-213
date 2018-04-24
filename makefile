debug: Tetris Jogo
	g++ Tetris.o Jogo.o -g -o Tetris.out

compile: Tetris Jogo
	g++ Tetris.o Jogo.o -lncurses -o Tetris.out

Tetris: Tetris.h Tetris.cpp
	g++ -c Tetris.cpp

Jogo: jogoTetris.cpp
	g++ -c -lncurses jogoTetris.cpp

fast:
	g++ *.cpp -lncurses -g -o Tetris.out
