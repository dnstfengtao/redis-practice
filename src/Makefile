CC=gcc
DEPS=zmalloc.h linklist.h
OBJ=zmalloc.o linklist.o

%.o:%.c $(DEPS)
	$(CC) -c -o $@ 


redis:$(OBJ)
	$(CC) -o $@ $^
