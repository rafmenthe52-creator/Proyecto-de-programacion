#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include <string.h>

/**
 * @brief This function reads the space data from the file, adds the data to a struct of type space and then adds a pointer to that struct to the game(struct)
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to the struct in which the spaces will be saved
 * @param filename a pointer to the name of the data file
 * @return the Status of the function, either OK or ERROR
 */
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief This function reads the object data from the file, adds that data to a struct of type object and then adds a pointer to that struct to the game(struct)
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to the struct in which the spaces will be saved
 * @param filename a pointer to the name of the data file
 * @return the Status of the function, either OK or ERROR
 */
Status game_reader_load_objects(Game* game, char* filename);

/**
 * @brief This function reads the player data from the file, adds that data to a struct of type player and then adds a pointer to that struct to the game(struct)
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to the struct in which the spaces will be saved
 * @param filename a pointer to the name of the data file
 * @return the Status of the function, either OK or ERROR
 */
Status game_reader_load_player(Game* game, char* filename);

/*Anotación RV: En un futuro hay que llamar estas funciones desde otro .c, dado que ahora mismo no se están usando*/
#endif