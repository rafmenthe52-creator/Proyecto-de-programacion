/**
 * @brief It defines the object module interface
 *
 * @file object.h
 * @author Rafael Velasco-RV
 * @version 0
 * @date 04-02-2025
 * @copyright GNU Public License
 */
#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#define MAX_OBJECTS 1

/**
 * @brief It creates a new object, allocating memory and initializing its variables
 * @author Rafael Velasco-RV
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object* object_create(Id id);

/**
 * @brief The function frees the memory allocated in the function object_create, therefore it deletes the object
 * @author Rafael Velasco-RV
 *
 * @param object a pointer to the allocated memory where the object is located
 * @return it returns the Status, either OK or ERROR
 */
Status object_destroy(Object* object);

/**
 * @brief The function acceses the data structure to return the id of the object
 * @author Rafael Velasco-RV
 *
 * @param object a pointer to the allocated memory where the object is located
 * @return it returns the either NO_ID or the id saved in the object data structure 
 */
Id object_get_id(Object* object);

/**
 * @brief The funtion acceses the data structure and sets the value of the name to the one given in the parameter name
 * @author Rafael Velasco-RV
 *
 * @param object a pointer to the allocated memory where the object is located
 * @param name a string which contains the name which is intended to be copied to the objects structure
 * @return it returns the Status, either OK or ERROR
 */
Status object_set_name(Object* object, char* name);

/**
 * @brief The function acceses the data structure to return the name of the object
 * @author Rafael Velasco-RV
 *
 * @param object a pointer to the allocated memory where the object is located
 * @return it returns the name of the object
 */
char* object_get_name(Object* object);

/**
 * @brief The funtion acceses the data structure and sets the value of the location to the one given in the parameter id
 * @author Rafael Velasco-RV
 *
 * @param object a pointer to the allocated memory where the object is located
 * @param id the identification number of the space where the object is located
 * @return it returns the Status, either OK or ERROR
 */
Status object_set_location(Object* object, Id id);

/**
 * @brief The function acceses the data structure to return the location of the object
 * @author Rafael Velasco-RV
 *
 * @param object a pointer to the allocated memory where the object is located
 * @return it returns the name of the identification number of the space where the object is located
 */
Id object_get_location(Object* object);

/**
 * @brief This function prints the values of the object (id, name, location). It is used for depuration
 * @author Rafael Velasco-RV
 *
 * @param object a pointer to the allocated memory where the object is located
 * @return it returns the Status, either OK or ERROR
 */
Status object_print(Object* object);

#endif 
