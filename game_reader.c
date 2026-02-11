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

Status game_reader_load_spaces(Game *game, char *filename);

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
      if (!space_create(id)) {
        return ERROR;
      }else{  
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_object(space, bool_object);
        status=game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
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
    if(strncmp("#o:", 3, line)){
      id=atol(strtok(line+3, "|"));
      strcpy(name, strtok(line, "|"));
      location=atol(strtok(line, "|"));
    }
  }

  if(!object=object_create(id)){
    return ERROR;
  }else{
    object_set_name(name);
    object_set_location(location);
    status=game_add_object(game, object)
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

Status game_reader_load_player(Game* game, char* filename){
  FILE *file = NULL;
  char line[WORD_SIZE];
  char name[WORD_SIZE];
  char *toks = NULL;      /*Tokens separated by strtok*/
  Id id = NO_ID, location = NO_ID;
  id objects;
  Status = OK;

  /*Checking if filename is not NULL*/
  if(!(filename)){
    return ERROR
  }

  /*Opening the data file in read mode and checking for errors*/
  if(!(file=fopen(filename , "r"))){
    return ERROR
  }

  /*Look for #p: which indicates the data is of type player*/
  while(fgets(line, WORD_SIZE, files)){
    if(strncmp("#:", 3 , line)){
      id = atol(strtok(line+3 , "|"));
      strcpy(name , strtok(line , "|"));
      objects = atol(strtok(line , "|"));
    }
  }  

  if(!player=player_create(id)){
    return ERROR;
  }else{
    player_set_name(name , player);
    player_set_objects(objects , player);
    status==game_add_player(player))
  }
  
  if(ferror(file)){
    status = ERROR;
  }

  fclose(file);

  return status;
}