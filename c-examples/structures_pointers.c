#include <stdint.h>
#include <stdio.h>

typedef struct {
    char d1;
    int d2;
    char d3;
    short d4;
} DataSet_t;

void printData(DataSet_t *pData);


int main() {

    DataSet_t data = {
        .d1 = 0x11,
        .d2 = 0xFFFFEEEE,
        .d3 = 0x22,
        .d4 = 0xABCD   
    };

    uint8_t *ptr;

    ptr = (uint8_t*)&data;

    uint32_t totalSize = sizeof(DataSet_t);

    for (uint32_t i = 0; i < totalSize; i++)
    {
        printf("%p ,    %X\n", ptr,*ptr);
        ptr++;
    }
    

    printData(&data);


    // modify

    DataSet_t *pData = &data;

    pData->d1 = 0x55;

    printf("\n");
    printf("after modification\n");
    
    ptr = (uint8_t*)&data;  // necessary, as ptr is changed due to the ptr++
    for (uint32_t i = 0; i < totalSize; i++)
    {
        printf("%p ,    %X\n", ptr,*ptr);
        ptr++;
    }

    printData(&data);

    

    

    return 0;
}

void printData(DataSet_t *pData) {
    printf("\n");
    printf("after modification: %X\n", pData->d1);
    printf("after modification: %X\n", pData->d2);
    printf("after modification: %X\n", pData->d3);
    printf("after modification: %X\n", pData->d4);
}