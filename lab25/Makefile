targets = main.bin test.bin
CC = g++
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/lib.cpp

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist

compile: main.bin test.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
	
test.bin: test/test.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/main.bin
	./dist/test.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

