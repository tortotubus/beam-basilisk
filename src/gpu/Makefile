.PHONY: all clean

CFLAGS += -I..

all: libgpu.a

# uncomment if errors.lex is modified
# errors.c: errors.lex
#	flex -P gpu_errors -o errors.c errors.lex

libgpu.a: errors.o glad.o
	ar cr libgpu.a errors.o glad.o

clean:
	rm -f *.o *.a

check:
