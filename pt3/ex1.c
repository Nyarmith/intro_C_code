#include <ncurses.h>

int main(){
    initscr();
    for (int i=0; i<10; i++){
        mvprintw(i*2, i, "I current : %d", i);
    }
    refresh();
    getch();
    endwin();
}

