#include <stdio.h>


int main() {

    int input;

    printf("enter a number:");
    scanf("%d", &input);


    if (input & 1)  
    // the 1 here is the "masked" test value which is used to test the least significant bit:
    // assuming input is 4, in binary:
    // 100 & 001   -> 0 (the above condition is 0, which is the else case)                
    {
        printf("%x\n",(input & 1) );
        printf("given number is odd\n");
    } else {
        printf("%x\n",(input & 1) );
        printf("given number is even\n");
    }
    


    return 0;
}