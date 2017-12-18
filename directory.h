#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#define DIRECTORY_ENTRY_SIZE 128
#define CHAR_SIZE            sizeof(char)
#define INT_SIZE             sizeof(int)
#define MAX_NAME_SIZE        DIRECTORY_ENTRY_SIZE - CHAR_SIZE - INT_SIZE

#define MAX_DIRECTORY_ENTRIES 32

struct directory_entry{
    char name [MAX_NAME_SIZE];
    char type;
    int block;
};

#endif