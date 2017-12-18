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

void* do_init(struct fuse_conn_info *conn, struct fuse_config *cfg);
int do_open(const char* path, struct fuse_file_info* fi);
int do_create (const char *path, mode_t mode, struct fuse_file_info *fi);
int do_getattr(const char *path, struct stat *st, struct fuse_file_info *fi);
int do_readdir( const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi, enum fuse_readdir_flags flags);
int do_read( const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi );
int do_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info * fi);
int do_truncate(const char *path, off_t size, struct fuse_file_info *fi);
int do_mkdir (const char *path, mode_t mode);
int do_access(const char *path, int mask);
int do_readlink(const char *path, char *link, size_t size);

#endif