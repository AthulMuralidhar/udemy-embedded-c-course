

#include <stdio.h>

void someFunc();

int main() {
     someFunc();
     someFunc();
     someFunc();
     someFunc();

    return 0;
}


void someFunc() {
    // the static keyword effectively makes the below variable global
    // thus holding state until the program terminates.
    // it is still scoped private, cause no one else can modify it 
    static int c = 0;
    c += 1;

    printf("value of c is: %d\n",c);
}