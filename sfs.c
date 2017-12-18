#include "sfs.h"
// ==================================================================================================== XD
// ====================================== AUXILIARY FUNCTIONS    ====================================== XD
// ==================================================================================================== XD

void format () {
	printf("Formatting\n");
	unsigned char zeroBuffer[4096];
	memset(zeroBuffer, 0, 4096);
	//Fill the whole disk with Zeroes
	for (int i = 0; i <= MAX_SECTORS; i++ ) {
		device_write_sector(zeroBuffer, i);
	}

}

void write_bitmap () {
	printf("writing bitmap\n");
	unsigned char sectorBuffer[SECTOR_SIZE];
	for (int i = BITMAP_SECTOR; i < DIRECTORY_SECTOR; i++){
		memcpy(sectorBuffer,bitmap+((i-BITMAP_SECTOR)*SECTOR_SIZE), SECTOR_SIZE);
		device_write_sector(sectorBuffer, i);
	}
}

void load_bitmap () {
	printf("loading bitmap\n");
	unsigned char sectorBuffer[SECTOR_SIZE];
	for (int i = BITMAP_SECTOR; i < DIRECTORY_SECTOR; i++){
		device_read_sector(sectorBuffer, i);
		memcpy(bitmap+((i-BITMAP_SECTOR)*SECTOR_SIZE),sectorBuffer, SECTOR_SIZE);
	}
}

void write_directory () {
	printf("writing directory\n");
	for (int i = DIRECTORY_SECTOR; i < DIRECTORY_SECTOR + 1; i++){
		printf("%u\n", i);
	}
}

void load_directory () {
	printf("loading directory\n");
	for (int i = DIRECTORY_SECTOR; i < DIRECTORY_SECTOR + 1; i++){
		printf("%u\n", i);
	}
}

void setBit (int numberBit,int value) {
    int byte = numberBit / 8;
	int bit = numberBit % 8;
	if(byte < 0 || byte > MAX_BITMAP_BYTE || numberBit > MAX_SECTORS){
		printf("Error numberBit out of bounds! nb: %u byte: %u bit: %u\n", numberBit, byte, bit);
		return;
	}
	(value) ? ( bitmap[byte] |= (1UL << bit)) : (bitmap[byte] &= ~(1UL << bit));
}

int getBit (int numberBit) {
    int byte = numberBit / 8;
	int bit = numberBit % 8;
	if(byte < 0 || byte > MAX_BITMAP_BYTE || numberBit > MAX_SECTORS){
		printf("Error numberBit out of bounds! nb: %u byte: %u bit: %u\n", numberBit, byte, bit);
		return -1;
	}
    return ((bitmap[byte]) & 1 << bit)? 1:0;         
}

void printBitmap () {
	printf("Printing bitmap\n");
	for (int i = 0; i < MAX_BITMAP_BYTE;i++)
		for(int j =0; j < 8;j++)
			if((bitmap[i]) & 1 << j)
				printf("%u ", (i+j));
	printf("\n");
}

// ==================================================================================================== XD
// ====================================== DRIVE API FUNCTIONS    ====================================== XD
// ==================================================================================================== XD

void* do_init (struct fuse_conn_info *conn, struct fuse_config *cfg) {
	format();

	setBit(0, 1);
	setBit(1, 1);
	setBit(2, 1);
	setBit(200, 1);

	printBitmap();

	write_bitmap();
	load_bitmap();

	printBitmap();

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