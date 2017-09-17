#********************************#
# alg Makefile                   #
#                                #
#                   author: neeh #
#********************************#

NAME=alg

CC=g++ -O3

CFLAGS=-I./include -W -std=c++11

LFLAGS=

HEADFILES=$(wildcard include/*.h)
SRCFILES=$(wildcard src/*.cc)

OBJFILES=$(patsubst src/%.cc, obj/%.o, $(SRCFILES))
ASMFILES=$(patsubst src/%.cc, asm/%.s, $(SRCFILES))

obj/%.o: src/%.cc $(HEADFILES)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

asm/%.s: src/%.cc $(HEADFILES)
	mkdir -p asm
	$(CC) -S $(CFLAGS) -c $< -o $@

all: $(OBJFILES)
	mkdir -p bin
	$(CC) -o bin/$(NAME) $(OBJFILES) $(LFLAGS)

asm: $(ASMFILES)

clean:
	rm -rf obj
	rm -rf asm
	rm -rf bin
