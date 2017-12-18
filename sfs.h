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

#include "device.h"
#include "bitmap.h"
#include "directory.h"

#define DRIVE_SIZE_B          1073741824
#define BITMAP_MAX_ENTRIES    4096
#define DIRECTORY_MAX_ENTRIES 32

unsigned char bitmap[BITMAP_MAX_ENTRIES];
unsigned char direcotry[DIRECTORY_MAX_ENTRIES];

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