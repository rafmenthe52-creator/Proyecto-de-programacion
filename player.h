/**
 * @brief It defines the player module interface
 *
 * @file player.h
 * @author Adrian Covarrubias-AC
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
 * @brief It creates a new player, allocating memory and initializing its members
 * @author Adrian Covarrubias-AC
 *
 * @param id the identification number for the new player
 * @return a new player, initialized
 */
Player* player_create(Id id);

/**
 * @brief It destroys a player, freeing the allocated memory
 * @author Adrian Covarrubias-AC
 *
 * @param player a pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_destroy(Player* player);

/**
 * @brief It gets the id of a player
 * @author Adrian Covarrubias-AC
 *
 * @param player a pointer to the player
 * @return the id of player
 */
Id player_get_id(Player* player);

/**
 * @brief It sets the name of a player
 * @author Adrian Covarrubias-AC
 *
 * @param player a pointer to the player
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name(Player* player, char* name);

/**
 * @brief It gets the name of a player
 * @author Adrian Covarrubias-AC
 *
 * @param player a pointer to the player
 * @return  a string with the name of the player
 */
const char* player_get_name(Player* player);

/**
* @brief It sets the location of the player
* @author Adrian Covarrubias-AC
*
* @param player a pointer to the player
* @return OK, if everything goes well or ERROR if there was some mistake
*/
Status player_set_player_location(Player* player, Id id);

/**
* @brief It gets the location of the player
* @author Adrian Covarrubias-AC
* 
* @param player a pointer to the player
* @return a string with the location of the player
*/
Id player_get_player_location(Player* player);

/**
 * @brief It gets the number of objects the player carries
 * @author Adrian Covarrubias-AC
 * 
 * @param player a pointer to the player
 * @return the number of objects in the player's inventory
 */
int player_get_n_objects(Player* player);

/**
* @brief It adds an object to the player's "inventory" and updates n_objects accordingly
* @author Adrian Covarrubias-AC
* 
* @param player a pointer to the player
* @return OK, if everything goes well or ERROR if there was some mistake
*/
Status player_set_objects(Player* player, Id id);

/**
* @brief It gets the last objects id in the "inventory"
* @author Adrian Covarrubias-AC 
* 
* @param player a pointer to the player
* @return the players inventory
*/
Id player_get_objects(Player* player);

/**
* @brief It deletes the last object in the players "inventory"
* @author Rafael Velasco-RV
* 
* @param player a pointer to the player
* @return The status, either ERROR or OK;
*/
Status player_delete_object_from_inventory(Player *player);

/**
 * @brief It prints the player information
 * @author Adrian Covarrubias-AC
 *
 * This fucntion shows the id and name of the player, the spaces that surrounds it and wheter it has an object or not.
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player* player);

#endif
