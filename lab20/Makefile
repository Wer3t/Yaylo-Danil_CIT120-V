targets = main.bin test.bin
CC = gcc 
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/list.c src/data.c

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist

compile: main.bin test.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
	
test.bin: test/test.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/main.bin
	./dist/test.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

