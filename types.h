/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

/**
 * @brief Id
 *
 * Data type for identifiers. They are actually type long
 */
typedef long Id;

/**
 * @brief Bool
 *
 * Data type that shows wheter something is true or false. FALSE=0; TRUE=1
 */
typedef enum { FALSE, TRUE } Bool;

/**
 * @brief Status
 *
 * Data type for errorproofing. ERROR=0 ; OK=1
 */
typedef enum { ERROR, OK } Status;

/**
 * @brief Direction
 *
 * Data type that indicates the direction. N=0 ; S=1 ; E=2 ; W=3
 */
typedef enum { N, S, E, W } Direction;

#endif

