
.PHONY: all clean

all: bin bin/main

_OBJS = functions.o

#OBJS = bin/functions.o
OBJS = $(patsubst %,bin/%,$(_OBJS))

bin/main: bin/main.o $(OBJS)
	gcc $+ -o $@

bin/main.o: src/main.c $(OBJS)
	gcc -c $< -o $@

bin/%.o: src/%.c src/%.h
	gcc -c $< -o $@

bin: 
	mkdir -p bin

clean: 
	rm -r bin



