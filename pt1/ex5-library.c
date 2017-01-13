//--------------------------------------------------
// Disclib - The library that draws discs
// Author : Sergey Ivanov
// Copyright vapor-waves c.1997
//--------------------------------------------------

#include "ex5-header.h"
#include <stdio.h>
#include <math.h>

static char* ENTRANCE_STATEMENT = "welcome... to discworld\n"; //restrict scpoe to this file

extern DISC_HEIGHT;
extern DISC_WIDTH;

//helper functions
static float axis_x(float x); //static limits their visibility to this file during compliation, in-case an extern function with the same name is declared
static float axis_y(float x);

//proprietary functionality -- DO NOT LOOK
void instantiate_library(){
    printf(ENTRANCE_STATEMENT);
}

//using this function adds a couple hundred to the base license cost
void set_disc_size(int width, int height){
    DISC_HEIGHT = height;
    DISC_WIDTH  = width;
}

//draws a fucking disc
void draw_disc(){
    float x, y;
    for (x=0; x< DISC_WIDTH; x++){
        for (y=0; y<DISC_HEIGHT; y++){
            double x_n = axis_x(x);
            double y_n = axis_y(y);
            double len=sqrt(x_n*x_n + y_n*y_n);
            if (len > 1){
                putchar('#');
            } else {
                putchar(' ');
            }

            //printf("  -- len %f", len);
        }
        putchar('\n');
    }

    putchar('\n');
}

float axis_x(float x){
    float midpoint = DISC_WIDTH/2;
    float result = (x-midpoint) / midpoint;
    return result;
}

float axis_y(float y){
    float midpoint = DISC_HEIGHT/2;
    float result = (y-midpoint) / midpoint;
    return result;
}
