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
  Id location;
  Id objects[MAX_OBJECTS];  /*!< The id's of the objects the player carries*/
  int n_objects_player;     /*!< The number of objects the the player carries in its "inventory"*/
};

/** player_create allocates memory for a new player
 *  and initializes its members
 */
Player* player_create(Id id) {
  Player* newPlayer = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newPlayer = (Player*)malloc(1*sizeof(Player));
  if (newPlayer == NULL) {
    return NULL;
  }

  /* Initialization of an empty player*/
  int i = 0;
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  for(i = 0; i < MAX_OBJECTS; i++){
    newPlayer->objects[i] = NO_ID;
  }
  newPlayer->n_objects_player = 0;
  
  
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

Status player_set_objects(Player* player, Id id){
  if(!player || id == NO_ID){
    return ERROR;
  }if(player->n_objects_player >= MAX_OBJECTS){
    return ERROR;
  }
  player->objects[player->n_objects_player] = id;
  
  player->n_objects_player++; 

  return OK; 
} 


Id player_get_objects(Player* player){
  if(!player||player->n_objects_player<=0){
    return NO_ID;
  }

  /*returns the last object in "inventory"*/
  return player->objects[(player->n_objects_player)];
}

Status player_delete_object_from_inventory(Player *player){
  if(!playe||!id){
    return ERROR;
  }

  player->objects[player->n_objects]=NO_ID
  player->n_objects--;

  return OK;
}

int player_get_n_objects(Player* player){
  if(!player){
    return 0;
  }

  return player->n_objects_player;
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
  if(idaux =! NO_ID){
    fprintf(stdout, "Location id is: %ld",idaux )
  }else{
    fprintf(stdout, "No location id found", idaux)
  }

  /* 3. Print if the player has any objects or not */
  if (player_get_n_objects(player) > 0) {
    fprintf(stdout, "---> Player have object(s).\n");
  }else {
    fprintf(stdout, "---> Player has no objects")
  }

  return OK;
}
