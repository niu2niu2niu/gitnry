# Makefile for compiling NSGA-II source code
CC=gcc
LD=gcc
RM=rm -f
#CFLAGS=-Wall -ansi -pedantic -g
CFLAGS=-Wall -pedantic -g

SRC_DIR = src

SOURCES=$(wildcard $(SRC_DIR)/*.c)
OBJS:=$(patsubst %.c,%.o,$(SOURCES))

MAIN=./bin/nsga2r

INCLUDEFLAGS= -I ./include

all:info $(MAIN) clean
$(MAIN):$(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(MAIN) -lm
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDEFLAGS)
clean:
	$(RM) $(OBJS)
	$(RM) $(MAIN)
info:
	@echo "objs: "$(OBJS)
