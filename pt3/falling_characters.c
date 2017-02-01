#include <ncurses.h>
#include <unistd.h>
//unistd.h == unix std library

#define DELAY 35000

int main(){

    int c, x, y;

    initscr();
    noecho();
    nodelay(stdscr, TRUE); //our getch is no longer blocking
    getmaxyx(stdscr, y, x);

    while ((c=getch()) !='q'){  //q for quit
        //get input
        if (c != ERR){ //default result when we don't input anything in a loop
            if (c == '1')
                addch('1'); //just dump a 1 where the cursor is when the user hits 1
        }
        //display
        refresh();

        //update all 1's on the screen
        for(int i=x-1; i>=0; i--){
            for(int j=y-1; j>=0; j--){
                char bb = mvinch(j,i) & A_CHARTEXT; //eliminates formatting
                if (bb == '1'){
                    mvaddch(j,   i,   ' ');
                    mvaddch(j+1, i,   '1');
                }
            }
        }
        
        usleep(DELAY);
    }
    endwin();
    //returns 0 by default if you no return statement present
}
