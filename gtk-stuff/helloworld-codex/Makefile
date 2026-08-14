CC := gcc
CFLAGS := -Wall -Wextra
GTK_CFLAGS := $(shell pkg-config --cflags gtk4)
GTK_LIBS := $(shell pkg-config --libs gtk4)

TARGET := hello
SOURCE := hello.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(GTK_CFLAGS) $< -o $@ $(GTK_LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
