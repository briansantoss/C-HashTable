CC = gcc
CFLAGS = -Wall -I./include

OBJSDIR = obj/
BINDIR = bin/

# Handle files removing in Windows
ifeq ($(OS), Windows_NT)
	RM = powershell Remove-Item $(OBJSDIR)*
else
	RM = rm -f $(OBJSDIR)*
endif

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

clean:
	$(RM)
