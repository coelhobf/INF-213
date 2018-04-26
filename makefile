debug: Tetris.o jogoTetris.o
	g++ Tetris.o jogoTetris.o -g -o Tetris.out

compile: Tetris.o jogoTetris.o
	g++ Tetris.o jogoTetris.o -lncurses -o Tetris.out

Tetris.o: Tetris.h Tetris.cpp
	g++ -c Tetris.cpp

jogoTetris.o: jogoTetris.cpp
	g++ -c -lncurses jogoTetris.cpp

fast:
	g++ *.cpp -lncurses -g -o Tetris.out

clear:
	rm *.out *.o out.txt
