CC = gcc
CFLAGS = -Wall
LDFLAGS = 

TARGET = lab2

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(wildcard *.h)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

build: all clean