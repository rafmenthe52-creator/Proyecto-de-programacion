#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 1

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Player {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the player */
  id location;
  Bool object;              /*!< Whether the player has an object or not */
  id objects[MAX_OBJECTS];
  int n_objects_player;
};

/** player_create allocates memory for a new player
 *  and initializes its members
 */
Player* player_create(Id id) {
  Player* newPlayer = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newPlayer = (Player*)calloc(1, sizeof(Player));
  if (newPlayer == NULL) {
    return NULL;
  }

  /* Initialization of an empty player*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location;
  newPlayer->object = FALSE;
  for(i=0, i<MAX_OBJECTS, i++){
    newPlayer->objects[i] =NO_ID;
  }
  
  return newPlayer;
}

Status player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  return OK;
}

Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

Status player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

Status player_set_player_location(Player* player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->location = id;
  return OK;
}

Id player_get_player_location(Player* player){
  if(!player){
    return NO_ID;
  }
  return player->location;
}

Status player_set_object(Player* player, Bool value) {
  if (!player) {
    return ERROR;
  }
  player->object = value;
  return OK;
}

Bool player_get_object(Player* player) {
  if (!player) {
    return FALSE;
  }
  return player->object;
}

Status player_set_objects(Player* player, Id id){
  if(!player || id == NO_ID){
    return ERROR;
  }
  player->objects[n_objects_player] = id;
  n_objects_player++; 

  return OK; 
}

Id player_get_objects(Player* player){
  if(!player){
    return NO_ID;
  }

  return player->objects[n_objects_player-1];
}

Status player_print(Player* player) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the player */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  /* 2. Print the location of the player */
  idaux = player_get_player_location(player);
  if(idaux 1= NO_ID){
    fprintf(stdout, "Location id is: %ld",idaux )
  }else{
    fprintf(stdout, "No location id found", idaux)
  }

  /* 3. Print if the player has an object or not */
  if (player_get_object(player)) {
    fprintf(stdout, "---> Player have the object.\n");
  } else {
    fprintf(stdout, "---> Player not have the object.\n");
  }

  return OK;
}
