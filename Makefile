CC = g++


all: test

test: test.cpp
	@$(CC) test.cpp -o test


clean:
	@-rm -f test
