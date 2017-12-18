COMPILER = gcc
CFLAGS = -g -Wall -DFUSE_USE_VERSION=30 `pkg-config fuse3 --cflags`
LINKFLAGS = -Wall -lm `pkg-config fuse3 --libs`
MOUNTPOINT = drive

all: bin/sfs

clean:
	rm -rf bin obj

run:
	./bin/sfs -f -s $(MOUNTPOINT)

bin: 
	mkdir -p bin

bin/sfs: bin obj/sfs.o obj/device.o obj/main.o
	$(COMPILER) -g -o bin/sfs obj/* $(LINKFLAGS)

obj:
	mkdir -p obj

obj/main.o: obj main.c sfs.h
	$(COMPILER) -g $(CFLAGS) -c main.c -o $@

obj/sfs.o: obj sfs.c sfs.h 
	$(COMPILER) -g $(CFLAGS) -c sfs.c -o $@

obj/device.o: obj device.c device.h
	$(COMPILER) -g $(CFLAGS) -c device.c -o $@