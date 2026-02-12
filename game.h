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
  Player *player;
  Space *spaces[MAX_SPACES];
  int n_spaces;
  Object *objects[MAX_OBJECTS];
  int n_objects;
  Command *last_cmd;
  Bool finished;
} Game;

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Profesores PPROG
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
Status game_create(Game *game);

Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It deletes the alocated memory and therefore deletes the struct game
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game, which intends to be deleted
 * @return it returns the Status, either OK or ERROR
 */
Status game_destroy(Game *game);

/**
 * @brief This function gets game data (game and its id) and returns the struct of type space which is saved inside the struct game
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the game
 * @return it returns the Space that is saved inside game;
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief It gets the player from the game
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game
 * @return the Player pointer stored in the game
 */
Player* game_get_player(Game *game);

/**
 * @brief It gets an object from the game by its id
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the object
 * @return the Object pointer with the specified id, or NULL if not found
 */
Object* game_get_object(Game *game, Id id);

/**
 * @brief It gets the id of the space where the player is located
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game
 * @return The id of the space the player is located at
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the id of the location where the player is located at
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the space 
 * @return The status, either ERROR or OK
 */
Status game_set_player_location(Game *game, Id id);

/*Note: we could eliminate these functions and just use player_get and player_set location. But i prefer to keep them for now. -RV*/

/**
 * @brief It gets the id of the space where the object is located
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game
 * @return The id of the space the object is located at
 */
Id game_get_object_location(Game *game);

/**
 * @brief It sets the id of the location where the object is located at
 * @author Profesores PPROG
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the space 
 * @return The status, either ERROR or OK
 */
Status game_set_object_location(Game *game, Id id);

/*Note: we could eliminate these functions and just use object_get and object_set location. But i prefer to keep them for now. -RV*/

Command* game_get_last_command(Game *game);

Status game_set_last_command(Game *game, Command *command);

Bool game_get_finished(Game *game);

Status game_set_finished(Game *game, Bool finished);

void game_print(Game *game);

Status game_add_space(Game *game, Space *space);

Status game_add_object(Game *game, Object *object);

Status game_add_player(Game *game, player *player);

#endif
