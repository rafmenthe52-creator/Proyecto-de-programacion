/**
 * @brief This function reads the data in castle.dat and calls space to create a space. Later it creates a a game with that space
 *
 * @file game_reader.c
 * @author Rafael Velasco-RV
 * @version 1.0
 * @date 04-02-2025
 * @copyright GNU Public License
 */

#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>

/**
   Private functions
*/

Status game_load_spaces(Game *game, char *filename);

Status game_add_space(Game *game, Space *space);

/**
   Implementation of public functions
*/

Status game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  Status status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      if(!atol(toks)){
        bool_object=FALSE;
      }else(){
        bool_object=TRUE;
      }           //para futura implementacion de object
#ifdef DEBUG
      printf("Leido: s:%ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_object(space, bool_object);
        game_reader_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

Status game_reader_add_space(Game *game, Space *space) {
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
} 

Status game_reader_load_objects(Game* game, char* filename){
  FILE *file = NULL;
  char line[WORD_SIZE];
  char name[WORD_SIZE];
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *object = NULL
  Status status = OK;

  if(!(filename)){
    return ERROR;
  }

  if(!(file=fopen(filename, "r"))){
    return ERROR;
  }

  /*get the variables separated | and copy them to temporary placeholders*/
  while(fgets(line, WORD_SIZE, files)){
    if(strncmp("#p:", 3, line)){
      id=atol(strtok(line+3, "|"));
      strcpy(name, strtok(line, "|"));
      location=atol(strtok(line, "|"));
    }
  }

  object=object_create(id);
  if(object){
    object_set_name(name);
    object_set_location(location);
  }
  
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

Status game_reader_add_object(Game* game, Object* object){
  if(!object||(game->n_games>=MAX_GAMES)){
    return ERROR;
  }

  game->objects[game->n_games]=object;
  game->n_games++;

  return OK;
}