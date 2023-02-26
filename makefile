# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************

# Targets needed to bring the executable up to date

main: main.o Player.o Roulette.o Game.o
	$(CC) $(CFLAGS) -o main main.o player.o roulette.o game.o

main.o:	main.cpp Player.o Roulette.o Game.o
	$(CC) $(CFLAGS) -c main.cpp

Player.o: 
	$(CC) $(CFLAGS) -c Player/player.cpp

Roulette.o:	
	$(CC) $(CFLAGS) -c Roulette/roulette.cpp

Game.o:	
	$(CC) $(CFLAGS) -c game.cpp

clean:
	rm -f main *.o