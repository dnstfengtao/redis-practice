# 增加 make 入参 - 支持外部开启 debug 模式.
CCFLAGS = ${CFLAG}
# 增加编译告警信息
CCFLAGS += -Wall 
# 默认编译命令变量
CC=gcc

# Object directory 目标目录
ODIR=obj
LDIR=../lib

LIBS=-lm

# All dependencies.
_DEPS=*.h
DEPS=$(_DEPS)
# 替换函数 - 目前没有用
_OBJ=zmalloc.o adlist.o sds.o dict.o intset.o redis.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o:%.c $(DEPS)
	$(CC) ${CCFLAGS} -c -o $@ $<

redis:$(OBJ)
	$(CC) ${CCFLAGS} -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~core $(INCDIR)/*~
	rm -f ./redis