# Variables
CC = gcc
CFLAGS = -std=c89 -Wall -g -O2 `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`
TARGET = nide
SRC = nide.c

# Default target
all: $(TARGET)

# Compile and link
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
