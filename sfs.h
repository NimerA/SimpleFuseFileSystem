#ifndef _SFS_H_
#define _SFS_H_

#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <libgen.h>
#include <limits.h>
#include <math.h>

#include "device.h"
 
#define DIRECTORY_ENTRY_SIZE  128
#define CHAR_SIZE             sizeof(char)
#define INT_SIZE              sizeof(int)
#define MAX_NAME_SIZE         (DIRECTORY_ENTRY_SIZE - CHAR_SIZE - INT_SIZE)

#define MAX_SECTORS           (DEVICE_SIZE_B / SECTOR_SIZE )
#define MAX_BITMAP_BYTE       ((MAX_SECTORS % 8 == 0) ? (MAX_SECTORS/8) : ((MAX_SECTORS/8) + 1))
#define BITMAP_SECTOR_SIZE    ((MAX_BITMAP_BYTE % SECTOR_SIZE == 0) ? (MAX_BITMAP_BYTE/SECTOR_SIZE) : ((MAX_BITMAP_BYTE/SECTOR_SIZE) + 1))
#define MAX_DIRECTORY_ENTRIES (SECTOR_SIZE / DIRECTORY_ENTRY_SIZE)
#define REAL_BITMAP_SIZE      (BITMAP_SECTOR_SIZE * SECTOR_SIZE)

#define SUPERBLOCK_SECTOR     1
#define BITMAP_SECTOR         2
#define DIRECTORY_SECTOR      (BITMAP_SECTOR + BITMAP_SECTOR_SIZE)

struct Directory_entry {
    unsigned char name [MAX_NAME_SIZE];
    unsigned char type;
    unsigned int  block;
};

struct File {
    unsigned char name [MAX_NAME_SIZE];
    unsigned int  head;
    unsigned char size;
    unsigned int  block;
};

unsigned int sectorsFree;
unsigned char bitmap[REAL_BITMAP_SIZE];
unsigned char direcotry[MAX_DIRECTORY_ENTRIES];

// ======== AUXILIARY FUNCTIONS ========

void format ();

void write_bitmap();
void load_bitmap ();

void write_directory();
void load_directory ();

void setBit (int numberBit, int value);
int  getBit (int numberBit);
void printBitmap ();

// ======== DRIVE API FUNCTIONS ========

void* do_init (struct fuse_conn_info *conn, struct fuse_config *cfg);
int do_create (const char *path, mode_t mode, struct fuse_file_info *fi);
int do_getattr (const char *path, struct stat *st, struct fuse_file_info *fi);
int do_access (const char *path, int mask);
int do_readlink (const char *path, char *link, size_t size);

// ======== DIRECTORY API FUNCTIONS ========

//creates a directory
int do_mkdir (const char *path, mode_t mode);
//deletes a directory
int do_rmdir (const char *path);
//reads a directory
int do_readdir (const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi, enum fuse_readdir_flags flags);

// ======== FILE API FUNCTIONS ========

//creates a file
int do_mknod (const char *path, mode_t mode, dev_t dev);
//removes file
int do_unlink (const char *path);
//reads a file
int do_read (const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi );
//writes a file
int do_write (const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info * fi);
//opens a file
int do_open (const char* path, struct fuse_file_info* fi);
//deletes a file
int do_truncate (const char *path, off_t size, struct fuse_file_info *fi);


#endif