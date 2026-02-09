all: castle

castle: command.o game_actions.o game_loop.o game_reader.o game.o graphic_engine.o object.o player.o space.o 
	gcc -o castle command.o game_actions.o game_loop.o game_reader.o game.o graphic_engine.o object.o player.o space.o

command.o: command.c
	gcc -Wall -ansi -pedantic -c command.c

game_actions.o: game_actions.c
	gcc -Wall -ansi -pedantic -c game_actions.c 

game_loop.o: game_loop.c
	gcc -Wall -ansi -pedantic -c game_loop.c	

game_reader.o: game_reader.c
	gcc -Wall -ansi -pedantic -c game_reader.c 

game.o: game.c 
	gcc -Wall -ansi -pedantic -c game.c 

graphic_engine.o: graphic_engine.c 
	gcc -Wall -ansi -pedantic -c graphic_engine.c 

object.o: object.c
	gcc -Wall -ansi -pedantic -c object.c 

player.o: player.c
	gcc -Wall -ansi -pedantic -c player.c 

space.o: space.c 
	gcc -Wall -ansi -pedantic-c space.c 


	**falta incluir todos los .h que se usan 