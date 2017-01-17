#include <ncurses.h>

//definition-only = promising this function will exist
int draw_the_rest(); 

//basic ncurses program
int main(){
    initscr(); //initializes the screen
    draw_the_rest();
}
