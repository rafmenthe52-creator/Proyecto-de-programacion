#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Object
 *
 * This struct stores all the information of an object
 */

struct Object {
  Id id;                    /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id object_location        /*!< Id of the space the object is located at*/
};


/**
   Implementation of public functions
*/


/** space_create allocates memory for a new space
 *  and initializes its members
 */
Object* object_create(Id id) {
  Object* newObject = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  if (!(newObject = (Object*)calloc(1, sizeof(Object));)) {         /*allocates memory and proofs for Null value*/
    return NULL;
  }

  /* Initialization of an empty space*/
  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->object_location=NO_ID

  return newObject;
}

Status object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);          /*Clears memory*/
  return OK;
}

Id object_get_id(Object* object){
  if(!object){
    return NO_ID;
  }

  return object->id;
}

Status object_set_name(Object* object; char* name){
  if(!object|!name){
    return ERROR
  }

  if(!(strcpy(object->name, name))){
    return ERROR;
  }

  return OK;
}

char* object_get_name(Object* object){
  if(!object){
    return NULL;
  }

  return object->name;
}

Status object_set_location(Object* object, Id id){
  if (!object||!id){
    return ERROR;
  }

  if(!(object->object_location=id)){        /*copies id of the location to the struct object and insidew the struct into object_location*/  
    return ERROR;
  }

  return OK;
}

Id object_get_location(Object* object){
  if(!object){
    return NO_ID;
  }

  return object->object_location;
}

Status object_print(Object* object) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!object) {
    return ERROR;
  }

  /* 1. Print the id and the name of the object */
  fprintf(stdout, "--> object (Id: %ld; Name: %s)\n", object, object->name);

  /* 2. Print the objects location */
  idaux = object_get_location(object);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> Object location: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No object location.\n");
  }
  

  return OK;
}