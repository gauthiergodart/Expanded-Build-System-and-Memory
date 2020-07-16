/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017 
 * @updated Jul 15 2020 by Gauthier Godart
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief Move a value from a source to a destination
 *
 * Given two byte pointers (one source and one destination) 
 * and a length of bytes, move a value from the source location 
 * to the destination.
 * If there is overlap of source and destintation, copy will occur
 * with no data corruption
 *
 * @param src Pointer to the source
 * @param dest Pointer to the destination
 * @param length Length of bytes to move 
 *
 * @return a pointer to the destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy a value from a source to a destination
 *
 * Given two byte pointers (one source and one destination) 
 * and a length of bytes, copy a value from the source location 
 * to the destination.
 * If there is overlap of source and destintation, copy will occur
 * but will likely corrupt the data
 *
 * @param src 		Pointer to the source
 * @param dest 		Pointer to the destination
 * @param length 	Length of bytes to move 
 *
 * @return a pointer to the destination 
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set all locations of a memory to a given value
 *
 * Given a pointer to a memory location, a length in bytes 
 * and a value, set all locations of that memory to that value
 *
 * @param src 		Pointer to the source memory location
 * @param length 	Number of elements to set
 * @param value 	Setting value
 *
 * @return A pointer to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Set all locations of a memory to zero
 *
 * Given a pointer to a memory location and a length, set all
 * the locations of that memory to zero
 *
 * @param src 		Pointer to the source memory location
 * @param length 	Number of elements to set
 *
 * @return A pointer to the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of all the bytes of a memory
 *
 * Given a pointer to a memory location and a length in bytes, 
 * reverse the order of all the bytes
 *
 * @param src 		Pointer to the source memory location
 * @param length 	Number of elements to reverse 
 *
 * @return A pointer to the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserve a number of words in dynamic memory
 *
 * Given a length in bytes, reserve words in dynamic memory
 *
 * @param Length 	Number of words to reserve in dynamic memory
 *
 * @return A pointer to the dynamic memory allocated if successful,
 * a Null Pointer if not
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free dynamic memory allocation
 *
 * Given a pointer to a dynamic memory allocation, free that memory
 *
 * @param src 		Pointer to the memory allocation
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
