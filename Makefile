CFLAGS= -Wall -ansi -pedantic -c
CC=gcc

all: castle

castle: command.o game_actions.o game_loop.o game_reader.o game.o graphic_engine.o object.o player.o space.o
	$(CC) -o $@ $^

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c $<

game_actions.o: game_actions.c game_actions.h player.h space.h command.h game.h types.h object.h
	$(CC) $(CFLAGS) -c $<

game_loop.o: game_loop.c command.h types.h game.h space.h object.h player.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c game_reader.h game.h command.h space.h object.h player.h types.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h command.h space.h object.h player.h types.h game_reader.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h object.h player.h types.h
	$(CC) $(CFLAGS) -c $<

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c $<

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c $<