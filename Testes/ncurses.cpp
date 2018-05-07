#include <curses.h>

int main(void) {
    initscr();
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);

    WINDOW *win = newwin(3,20,0,0);

    wattron(win, COLOR_PAIR(1));
    wprintw(win, "This should be printed in black with a red background!\n");

    wprintw(win, "And this in a green background!\n");
    wrefresh(win);

    getch();

    endwin();
}