targets = main.bin 
CC = g++
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/Basic_bird.cpp src/Migratory_bird.cpp src/Exotic_bird.cpp src/Birds.cpp

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist

compile: main.bin 

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
	
test.bin: test/test.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

