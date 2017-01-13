#include <stdio.h>
#include "ex5-header.h"

extern char* ENTRANCE_STATEMENT;

int main(){
    //welcome the user
    printf(ENTRANCE_STATEMENT);

    instantiate_library();
    draw_disc();
    set_disc_size(17,17); //high-resolution disc
    draw_disc();

    return 0;
}

