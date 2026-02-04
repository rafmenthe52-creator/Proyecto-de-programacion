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

Status object_set_name(Object* object; char* name);

char* object_get_name(Object* object);

Status object_set_location(Object* object, Id id);

Id object_get_location(Object* object);

#endif