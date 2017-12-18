#include "bitmap.h"

void setBit (unsigned char* bitmap, int numberBit,int value) {
    int byte = numberBit / 8;
    int bit = numberBit % 8;

    if(value != 0){
        bitmap[byte] |= (value<<bit);
    }else{ 
        bitmap[byte] ^= (1<<bit);
    }
}

int getBit (unsigned char* bitmap, int numberBit) {
    int bytes = numberBit / 8;
    int bit = numberBit % 8;
    return ((bitmap[bytes]) & 1 << bit)? 1:0;
         
}

int getFreeBlock (unsigned char* bitmap) {
    //TO-DO
    return 0;
}

void printBitmap (unsigned char* bitmap) {
    //TO-DO
}