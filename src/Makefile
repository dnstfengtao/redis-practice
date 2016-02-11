CC=gcc

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS=zmalloc.h linklist.h
DEPS=$(_DEPS)

_OBJ=zmalloc.o linklist.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o:%.c $(DEPS)
	$(CC) -c -o $@ $<

redis:$(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~core $(INCDIR)/*~
	rm -f ./redis
