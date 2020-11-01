all: main.o pokemon.o
		gcc -o pokemon main.o pokemon.o

main.o: main.c pokemon.h
		gcc -c main.c

pokemon.o: pokemon.c pokemon.c
		gcc -c pokemon.c

clean:
		rm *.o

run:
		./pokemon.exe
