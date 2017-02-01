#include <ncurses.h>


// ---- GLOBALS ---- 
int max_x, max_y;    //screen dimensions
int x, y;            //cursor location
unsigned long text_settings; //bit settings
int fg_color, bg_color; //foreground and background colors


int  query_color();  //when you hit ctrl+c it calls this function 
void apply_colors(); //applies global color values to terminal


int main(){

    //ncurses initialization
    initscr();
    keypad(stdscr, TRUE);
    raw();
    getmaxyx(stdscr, y, x);
    noecho();

    printw("Just Start Typing Buddy, Hit <ESC> to Exit\n"
            "F5 saves to saved_session and F6 loads from it\n"
            "Hotkeys Enable Attributes\n"
            "ctrl+b : A_BOLD\n"
            "ctrl+i : A_ITALIC\n"
            "ctrl+r : A_REVERSE\n"
            "ctrl+d : A_DIM\n"
            "ctrl+p : A_PROTECT\n"
            "ctrl+n : A_INVIS\n"
            "ctrl+a : A_ALTCHARSET\n"
            "ctrl+t : A_CHARTEXT\n"
            "ctrl+s : A_STANDOUT\n");
    if (has_colors() == TRUE){
        start_color();
        printw(
            "\n"
            "COLORS\n"
            "ctrl+c => number  selects a color for the text\n"
            "ctrl+x => number  selects a color for the background\n"
            "0 : COLOR_BLACK\n"
            "1 : COLOR_RED\n"
            "2 : COLOR_GREEN\n"
            "3 : COLOR_YELLOW\n"
            "4 : COLOR_BLUE\n"
            "5 : COLOR_MAGENTA\n"
            "6 : COLOR_CYAN\n"
            "7 : COLOR_WHITE\n");
    }
    refresh();

    int c, qc;
    text_settings = 0;
    fg_color = COLOR_WHITE;
    bg_color = COLOR_BLACK;
    while(1){
        getyx(stdscr, y, x);  /*gets initial x,y coordinates, resets our x,y values if they're out of bounds*/
        c = getch();
        switch(c) {
            /* #### Navigation Section ####*/
            case KEY_UP:
                y=y-1;
                move(y,x);
                break;
            case KEY_LEFT:
                x=x-1;
                move(y,x);
                break;
            case KEY_RIGHT:
                x=x+1;
                move(y,x);
                break;
            case KEY_DOWN:
                y=y+1;
                move(y,x);
                break;
            /* #### Toggling Attributes with Ctrl+key ####*/
            case 'b'-96:
                text_settings ^= A_BOLD;   //note: ctrl+key is just 'key'-96
                break;
            case 'i'-96:
                text_settings ^= A_ITALIC;
                break;
            case 'r'-96:
                text_settings ^= A_REVERSE;
                break;
            case 'd'-96:
                text_settings ^= A_DIM;
                break;
            case 'p'-96:
                text_settings ^= A_PROTECT;
                break;
            case 'n'-96:
                text_settings ^= A_INVIS;
                break;
            case 'a'-96:
                text_settings ^= A_ALTCHARSET;
                break;
            case 't'-96:
                text_settings ^= A_CHARTEXT;
                break;
            case 's'-96: 
                text_settings ^= A_STANDOUT;
                break;
            case 'c'-96:  //foreground color
                qc = query_color();
                if (qc >= 0){
                    fg_color = qc;
                    apply_colors();
                }
                break;
            case 'x'-96: //background color
                qc = query_color();
                if (qc >= 0){
                    bg_color = qc;
                    apply_colors();
                }
                break;
            /* #### Normal Editor Inputs #### */
            case KEY_BACKSPACE:
                x=x-1;
                mvdelch(y,x);
                break;
            default:  /* User Typing */
                mvaddch(y,x,c | text_settings);
                getyx(stdscr,y,x);
                break;
            case 27:  /* EXIT program with escape key(or alt key)*/
                endwin();
                return 0;
            case KEY_F(5): /*saves to   ./saved_session */
                scr_dump("saved_session");
                break;
            case KEY_F(6): /*loads from ./saved_session */
                scr_restore("saved_session");
                break;
        }
        refresh();
    }
    endwin();
}

int query_color(){
    int i=getch();
    //the colors, e.g. COLOR_RED are enumerated so they're just values from 0 to 7
    if ('0'<=i && i<='7'){
        return (i-'0');  
    } else {
        mvaddch(y,x, i | text_settings);
        return -1;
    }
}

void apply_colors(){
    static int pair_num = 1;
    init_pair(pair_num, fg_color, bg_color);
    attron(COLOR_PAIR(pair_num));
    pair_num++;
}
