#include <stdio.h>
#include <math.h>

int main(){
    //get the number of possible values in a char
    int bits_in_char=8*sizeof(char);
    int max=pow(2,bits_in_char-1);
    char i=0;
    putchar(i);
    while (i<(max-1)){
        //printf("max : %d ", max);
        i++;
        putchar(i);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}
