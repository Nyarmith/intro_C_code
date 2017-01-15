#include <stdio.h>
#include <math.h>

void printstr(char* in, int i){
    printf("argument %d :  %s\n", i, in);
}

// prints what you input to it
int main(int argc, char** argv){
    int i=0;
    while (i<argc){
        printstr(argv[i], i);
        i++;
    }
    printf("%d\n",sizeof(char));
    return 0;
}
