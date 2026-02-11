/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

Id game_get_space_id_at(Game *game, int position);

/**
   Game interface implementation
*/

Status game_create(Game *game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }

  game->n_spaces = 0;
  game->n_objects = 0;
  game->player = NULL;
  game->last_cmd = command_create();
  game->finished = FALSE;

  return OK;
}

Status game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_reader_load_spaces(game, filename)) {
    return ERROR;
  }

  if(game_reader_load_objects(game, filename)){
    return ERROR
  }
  
if(game_reader_load_player(game, filename)){
  return ERROR;
}
  
  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

Status game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < game->n_objects; i++) {
    object_destroy(game->objects[i]);
  }

  if (game->player) {
    player_destroy(game->player);
  }

  command_destroy(game->last_cmd);

  return OK;
}

Space* game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_spaces; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}

Player* game_get_player(Game *game) {
  if (!game) {
    return NULL;
  }
  return game->player;
}

Object* game_get_object(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_objects; i++) {
    if (id == object_get_id(game->objects[i])) {
      return game->objects[i];
    }
  }

  return NULL;
}

Id game_get_player_location(Game *game) {
  if (!game || !game->player) {
    return NO_ID;
  }
  return player_get_player_location(game->player);
}

Status game_set_player_location(Game *game, Id id) {
  if (!game || !game->player || id == NO_ID) {
    return ERROR;
  }

  return player_set_player_location(game->player, id);
}

Id game_get_object_location(Game *game) {
  if (!game || game->n_objects == 0 || !game->objects[0]) {
    return NO_ID;
  }
  return object_get_location(game->objects[0]);
}

Status game_set_object_location(Game *game, Id id) {
  if (!game || id == NO_ID || game->n_objects == 0) {
    return ERROR;
  }

  object_set_location(game->objects[0], id);
  space_set_objects(game_get_space(game, id), object_get_id(game->objects[0]));

  return OK;
}

Command* game_get_last_command(Game *game) { return game->last_cmd; }

Status game_set_last_command(Game *game, Command *command) {
  game->last_cmd = command;

  return OK;
}

Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}

void game_print(Game *game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < game->n_spaces; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Player: \n");
  if (game->player) {
    player_print(game->player);
  }

  printf("=> Objects: \n");
  for (i = 0; i < game->n_objects; i++) {
    object_print(game->objects[i]);
  }
}

Status game_add_space(Game *game, Space *space) {                                           
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}

Status game_add_object(Game* game, Object* object){
  if(!object || !game || game->n_objects >= MAX_OBJECTS){
    return ERROR;
  }

  game->objects[game->n_objects] = object;
  game->n_objects++;

  return OK;
} 

Status game_add_player(Game* game, Player* player){
  if((!game)||(!player)){
    return ERROR;
  }

  game->player=player;

  return OK;
}

Id game_get_space_id_at(Game *game, int position) {
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}
