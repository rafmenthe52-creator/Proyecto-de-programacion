/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "types.h"

#define MAX_SPACES 100
#define MAX_OBJECTS 1
#define MAX_PLAYER 1

typedef struct _Game {
  Id player_location;
  Space *spaces[MAX_SPACES];
  int n_spaces;
  Object *objects[MAX_OBJECTS];
  int n_games;
  player *player;
  Command *last_cmd;
  Bool finished;
} Game;

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
Status game_create(Game *game);

Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It deletes the alocated memory and therefore deletes the struct game
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game, which intends to be deleted
 * @return it returns the Status, either OK or ERROR
 */
Status game_destroy(Game *game);

/**
 * @brief This function gets game data (game and its id) and returns the struct of type space which is saved inside the struct game
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the game
 * @return it returns the Space that is saved inside game;
 */
Space *game_get_space(Game *game, Id id);

Id game_get_player_location(Game *game);

Status game_set_player_location(Game *game, Id id);

Id game_get_object_location(Game *game);

Status game_set_object_location(Game *game, Id id);

Command* game_get_last_command(Game *game);

Status game_set_last_command(Game *game, Command *command);

Bool game_get_finished(Game *game);

Status game_set_finished(Game *game, Bool finished);

void game_print(Game *game);

Status game_add_space(Game *game, Space *space);

Status game_add_object(Game *game, Object *object);

Status game_add_player(Game *game, player *player);

#endif
