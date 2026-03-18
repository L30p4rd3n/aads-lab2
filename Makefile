CC = gcc
CFLAGS = -Wall -Wextra -g

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE = lab2

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

