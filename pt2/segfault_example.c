#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));  //NULL is basically a fancy alias for 0
    int * uninitialized_pointer = rand();
    printf("%s", uninitialized_pointer);
    return 0;
}
