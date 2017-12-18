#define FUSE_USE_VERSION 30

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
#include "sfs.h"

static struct fuse_operations operations = {
	.init       = do_init,
	.open       = do_open,
	.create     = do_create,
	.getattr    = do_getattr,
	.readdir    = do_readdir,
	.read	    = do_read,
	.write      = do_write,
	.truncate   = do_truncate,
	.mkdir      = do_mkdir,
	.access     = do_access,
	.readlink   = do_readlink,
};

int main( int argc, char *argv[] ){
	const char *path = "./drive";
	printf("Mounting file system...\n");
	if (!device_open(realpath(path, NULL)) ) {
	    printf("Cannot open device file: %s\n", path);
	    return 1;
	}	
	return fuse_main( argc, argv, &operations, NULL );
}