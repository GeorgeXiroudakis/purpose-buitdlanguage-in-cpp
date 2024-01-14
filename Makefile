CC = g++


all: test

test: test.cpp PokemonLeague.h
	@$(CC) test.cpp -o test


clean:
	@-rm -f test
