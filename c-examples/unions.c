#include <stdio.h>
#include <stdint.h>

typedef union {
    uint16_t shortAddr;
    uint32_t longAddr;
    
} Address;

int main() {
    Address address;
    
    address.shortAddr = 0xABCD;
    address.longAddr = 0xEEEECCCC;
    
    printf("lonaddr: %#x\n", address.longAddr);
    printf("shortAddr: %#x\n", address.shortAddr);
    
    // prints:
    // lonaddr: 0xeeeecccc
    // shortAddr: 0xcccc 
    // this is because the short address value is overwriten by setting the long addr,
    // basically same memory
    // 
    // so in unions:
    // the size is the size of the max attribute in the union - here its uint32
    // its an either or struct, so either shortAddr must be filled or the longAddr must 
    // have data. 
    
    return 0;
}