#include "sfs.h"

// ==================================================================================================== XD
// ====================================== DRIVE API FUNCTIONS    ====================================== XD
// ==================================================================================================== XD

void* do_init (struct fuse_conn_info *conn, struct fuse_config *cfg) {
    printf("Loading file system map ...\n");
	device_read_sector(bitmap, 1);
	return NULL;
}

int do_create (const char *path, mode_t mode, struct fuse_file_info *fi) {
	return 0;
}

int do_getattr (const char *path, struct stat *st, struct fuse_file_info *fi) {
	printf( "[getattr] Called\n" );
	printf( "\tAttributes of %s requested\n", path );

	return 0;
}

int do_access (const char *path, int mask) {
	printf( "[access] Called\n" );
	printf( "\tpath %s\n", path );
    return 0;
}

int do_readlink (const char *path, char *link, size_t size) {
    return -EPERM;
}


// ===================================================================================================== XD
// ====================================== DIRECTORY API FUNCTIONS ====================================== XD
// ===================================================================================================== XD

int do_mkdir (const char *path, mode_t mode) {
	printf( "[MKDIR] %s\n", path );
	return 0;
}

int do_rmdir (const char *path) {
	printf( "[RMDIR] %s\n", path );
	return 0;
}

int do_readdir (const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi, enum fuse_readdir_flags flags) {
	printf( "[READDIR] %s\n", path );
	return 0;
}

// ===================================================================================================== XD
// ====================================== FILES API FUNCTIONS     ====================================== XD
// ===================================================================================================== XD

int do_mknod (const char *path, mode_t mode, dev_t dev) {
	printf( "[MKNOD] %s\n", path );
	return 0;
}

int do_unlink (const char *path) {
	printf( "[UNLINK] %s\n", path );
	return 0;
}

int do_read (const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi ) {
	printf( "[READ] %s\n", path );
	return 0;
}

int do_write (const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info * fi) {
	printf("[WRITE] %s\n", path);
  	return 0;
}

int do_open (const char* path, struct fuse_file_info* fi) {
  	printf("[OPEN] %s\n", path);
  	return 0;
}

int do_truncate (const char *path, off_t size, struct fuse_file_info *fi) {
	printf("[TRUNCATE] %s\n", path);
	return 0;
}