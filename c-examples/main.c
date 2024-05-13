#include <stdio.h>

// run with gcc main.c --save-temps

/*
* so main.c-> pre processing (compiler) -> main.i  (intermediate representation)
* the main.i has the stdio.h file in it
*
* so main.i -> main.s (assembly)
*/

int main() {
    printf("hw");
    return 0l;
}