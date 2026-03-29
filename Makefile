CC = gcc
CFLAGS = -Wall
LDFLAGS = 

TARGET = bin/lab2

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(wildcard include/*.h)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

build: all clean