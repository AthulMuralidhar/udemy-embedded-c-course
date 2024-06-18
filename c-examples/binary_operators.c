
#include <stdio.h>


int main() {

    int input1, input2;

    printf("please enter input 1 (int):");
    scanf("%d", &input1);

    printf("please enter input 2 (int):");
    scanf("%d", &input2);

    printf("\n bitwise &: %d", (input1 & input2)); 
    printf("\n bitwise | %d", (input1 | input2)); 
    printf("\n bitwise ^: %d", (input1 ^ input2)); 
    printf("\n bitwise ~: %d on input1", (~input1)); 
    printf("\n bitwise ~: %d on input2", (~input2)); 

    printf("\nsame values in hex\n");

    printf("\n bitwise &: %x", (input1 & input2)); 
    printf("\n bitwise | %x", (input1 | input2)); 
    printf("\n bitwise ~: %x on input1", (~input1)); 
    printf("\n bitwise ~: %x on input2", (~input2)); 

    
    return 0;
}