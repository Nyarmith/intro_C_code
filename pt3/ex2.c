#include <ncurses.h>

int main(){
    unsigned long c;
    initscr();
    noecho(); //by default ncurses writes your typing to the screen
             //this disables that
    while( (c = getch()) != 'q')  //q for quit
        addch(c | A_BOLD | A_ITALIC);
    
    endwin();
}
