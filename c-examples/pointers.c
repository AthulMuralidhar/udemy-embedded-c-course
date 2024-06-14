
#include <stdio.h>


/*  note about pointers
    - the pointers always have the same amount of memory allocated by the compiler:
    for ex: char is always 1 byte but char* is always 8 bytes in 64bit systems. And
    int* is also 8 bites.

    the thing to note is that: char* only allows a read of 1 byte of data (which is a propery of char)
    while an int* can read 4 bytes of data which is a propery of int
 */

int main() {

    // create a char type variable and initializs it to value
    char someChar = 100;
    printf("value of somechar: %d \n", someChar);
    // printing the address of the above variable
    printf("address of somechar: %p \n", &someChar);

    // create a pointer variable and store the address of the above variable
    char* someCharPtr = &someChar;

    // perform a read operation on the pointer variable and print it
    printf("read of one bite with %d \n", *someCharPtr);

    // perform the write operation on the pointer and store the value 65
    *someCharPtr  = 65;


    // print the value of the variable defined in step 1
    printf("address of somechar: %d \n", someChar);




    return 0;
}