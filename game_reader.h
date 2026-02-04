#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include <string.h>


Status game_reader_load_spaces(Game *game, char *filename);

Status game_reader_add_space(Game *game, Space *space);

/*Anotación RV: En un futuro hay que llamar estas funciones desde otro .c, dado que ahora mismo no se están usando*/
#endif