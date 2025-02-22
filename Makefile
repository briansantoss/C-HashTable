CC = gcc
CFLAGS = -Wall -I./include

OBJSDIR = obj/
BINDIR = bin/

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, $(OBJSDIR)%.o, $(SRCS))

run: example
	.\$(BINDIR)example

example: $(OBJS)
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $^

$(OBJSDIR)%.o: src/%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
