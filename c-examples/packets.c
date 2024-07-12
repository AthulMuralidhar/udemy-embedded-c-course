#include <stdint.h>
#include <stdio.h>


typedef struct  {
    uint8_t CRC;
    uint8_t status;
    uint16_t payload;
    uint8_t bat;
    uint8_t sensor;
    uint8_t longAddr;
    uint8_t shortAddr;
    uint8_t addrMode;
} Packet ;

void printPacket(const Packet *packet);

int main() {
    uint32_t packetValue;
    
    printf("please enter the 32 bit backet value:");
    scanf("%x", &packetValue);
    
    Packet packet;
    
    // crc is first 2 bits of the input data
    // packet.CRC = (uint8_t) packetValue & 0x3; // 0x3 == (11 in the last two bits in binary)
    packet.CRC = (uint8_t) ( packetValue & 0x3); // 0x3 == (11 in the last two bits in binary)
    
    // status is 1 bit after the crc, so bit position is 3
    // the bit shift to 2 clears the crc data out and pushes the status data to bit pos 0
    // so a 0x1 is used to extract that value
    packet.status = (uint8_t) (packetValue  >> 2 ) & 0x1;
    
    // payload is 12 bits
    packet.payload =(uint16_t) (packetValue >> 3) & 0xFFF;
    
    // bat is 3 bits
    packet.bat = (uint8_t)(packetValue >> 15) & 0x7;
    
    // sensor is also 3 bits
    packet.sensor = (uint8_t)(packetValue >> 18) & 0x7;

    // long addr is 8 bits
    packet.longAddr =(uint8_t) (packetValue >> 21) & 0xFF;

    // short addr is 2 bits
    packet.shortAddr = (uint8_t)(packetValue >> 29) & 0x3;
    
    // addr mode is 1 byte
    packet.addrMode = (uint8_t)(packetValue >> 31) & 0x1;
    
    printPacket(&packet);
    
    return 0;
}


void printPacket(const Packet *packet) {
    printf("packt.crc: %x\n", packet-> CRC);
    printf("packt.payload: %x\n", packet-> payload);
    printf("packt.bat: %x\n", packet-> bat);
    printf("packt.sensor: %x\n", packet-> sensor);
    printf("packt.longAddr: %x\n", packet-> longAddr);
    printf("packt.longAddr: %x\n", packet-> shortAddr);
    printf("packt.longAddr: %x\n", packet-> addrMode);
}