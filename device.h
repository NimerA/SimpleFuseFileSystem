#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <stdlib.h>
#include <stdio.h>

#define SECTOR_SIZE 4096

int device_open(const char *path);
void device_close();
int device_read_sector(unsigned char buffer[], int sector);
int device_write_sector(unsigned char buffer[], int sector);
void device_flush();

#endif