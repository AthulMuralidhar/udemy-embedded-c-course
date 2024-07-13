
#include <stdint.h>
#include <stdio.h>


typedef struct  {
    uint32_t CRC        :2;  // :2 means - tell the compiler to just use the two bits from the 32 bit memory
    uint32_t status     :1;
    uint32_t payload    :12;
    uint32_t bat        :3;
    uint32_t sensor     :3;
    uint32_t longAddr   :8;
    uint32_t shortAddr  :2;
    uint32_t addrMode   :1;
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
    
    printf("size of struct Packet: %lu bytes\n", sizeof(packet));
    
    return 0;
}


void printPacket(const Packet *packet) {
    printf("packt.crc: %#x\n", packet-> CRC);
    printf("packt.payload: %#x\n", packet-> payload);
    printf("packt.bat: %#x\n", packet-> bat);
    printf("packt.sensor: %#x\n", packet-> sensor);
    printf("packt.longAddr: %#x\n", packet-> longAddr);
    printf("packt.shortAddr: %#x\n", packet-> shortAddr);
    printf("packt.addrMode: %#x\n", packet-> addrMode);
}