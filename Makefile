CC = gcc
CFLAGS = -Wall -Werror
LDFLAGS =

SOURCES = $(shell find . -name '*.c')
OBJECTS = $(SOURCES:%.c=%.o)
HEADERS = $(shell find . -name '*.h')

TARGET = penguin

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
