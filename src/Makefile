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

# 将所有 .c 文件编译成 .o 文件
$(ODIR)/%.o:%.c
	$(CC) ${CCFLAGS} -c -o $@ $<

# 替换函数 - 目前没有用.
# 仅仅用于定义生成目标文件所有的依赖文件.
_OBJ=zmalloc.o adlist.o sds.o dict.o intset.o ziplist.o util.o redis.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

# redis 集成命令 -> 将所有依赖的文件编译成 redis 目标文件.
redis:$(OBJ)
	$(CC) ${CCFLAGS} -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~core $(INCDIR)/*~
	rm -f ./redis