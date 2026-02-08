#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Player {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id north;                 /*!< Id of the space at the north */
  Id south;                 /*!< Id of the space at the south */
  Id east;                  /*!< Id of the space at the east */
  Id west;                  /*!< Id of the space at the west */
  Bool object;              /*!< Whether the space has an object or not */
};

/** space_create allocates memory for a new space
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

  /* Initialization of an empty space*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->north = NO_ID;
  newPlayer->south = NO_ID;
  newPlayer->east = NO_ID;
  newPlayer->west = NO_ID;
  newPlayer->object = FALSE;

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

Status player_set_north(Player* player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->north = id;
  return OK;
}

Id player_get_north(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->north;
}

Status player_set_south(Player* player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->south = id;
  return OK;
}

Id player_get_south(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->south;
}

Status player_set_east(Player* player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->east = id;
  return OK;
}

Id player_get_east(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->east;
}

Status player_set_west(Player* player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->west = id;
  return OK;
}

Id player_get_west(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->west;
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

Status player_print(Player* player) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  /* 2. For each direction, print its link */
  idaux = player_get_north(player);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = player_get_south(player);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = player_get_east(player);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = player_get_west(player);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 3. Print if there is an object in the space or not */
  if (player_get_object(player)) {
    fprintf(stdout, "---> Player have the object.\n");
  } else {
    fprintf(stdout, "---> Player not have the object.\n");
  }

  return OK;
}
