CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iincludes
LDFLAGS = -lsqlite3

SRCS = src/main.c src/auth.c src/database.c src/country.c src/region.c

OBJS = $(SRCS:src/%.c=build/%.o)

BIN = bin/app

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*.o $(BIN)