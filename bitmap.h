#ifndef _BITMAP_H_
#define _BITMAP_H_

void setBit (unsigned char* bitmap, int numberBit,int value);
int  getBit (unsigned char* bitmap, int numberBit);
int getFreeBlock (unsigned char* bitmap);
void printBitmap (unsigned char* bitmap);

#endif