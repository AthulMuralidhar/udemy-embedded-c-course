
#include <stdint.h>
#include <stdio.h>


typedef union  {
    uint32_t packetValue;
    struct {
        uint32_t CRC        :2;  // :2 means - tell the compiler to just use the two bits from the 32 bit memory
        uint32_t status     :1;
        uint32_t payload    :12;
        uint32_t bat        :3;
        uint32_t sensor     :3;
        uint32_t longAddr   :8;
        uint32_t shortAddr  :2;
        uint32_t addrMode   :1;
    } packetFields;
} Packet ;

void printPacket(const Packet *packet);

int main() {
    
    Packet packet;
    printf("please enter the 32 bit backet value:");
    scanf("%x", &packet.packetValue);

    
    printPacket(&packet);
    
    printf("size of struct Packet: %lu bytes\n", sizeof(packet));
    
    return 0;
}


void printPacket(const Packet *packet) {
    printf("packt.crc: %#x\n", packet->packetFields.CRC);
    printf("packt.payload: %#x\n", packet->packetFields.payload);
    printf("packt.bat: %#x\n", packet->packetFields.bat);
    printf("packt.sensor: %#x\n", packet-> packetFields.sensor);
    printf("packt.longAddr: %#x\n", packet-> packetFields.longAddr);
    printf("packt.shortAddr: %#x\n", packet-> packetFields.shortAddr);
    printf("packt.addrMode: %#x\n", packet-> packetFields.addrMode);
}