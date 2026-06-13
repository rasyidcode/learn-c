CC := gcc

DEBUG_CFLAGS := -std=c99 -Wall -Wextra -pedantic -g -O0
LDFLAGS := -lm

SRC ?=
TARGET := $(basename $(notdir $(SRC)))

.PHONY: build clean

build: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(DEBUG_CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	find . -maxdepth 1 -type f ! -name '*.c' ! -name 'Makefile' -delete
