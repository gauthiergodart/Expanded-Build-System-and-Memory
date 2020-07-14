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
 * @file STATS 
 * @brief STATS is a set of statistical functions that can be used with an array.
 *
 * STATS is a set of statistical functions that can be used with an array. 
 * Each function takes two inputs: an array of unsigned char, and its length. 
 * Most of the functions return a unsigned char (max, min, med, mean). Some of 
 * it returns nothing, but print statistical informations on the screen. 
 *
 * @author Gauthier Godart
 * @date July 2 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Print all the statistical informations about the array
 *
 * This function calls the others functions in order to : sort the array, 
 * get the median, mean, max and min of its elements, and print all the
 * informations on the screen.
 *
 * @param a an array of char
 * @param n the lenght of array a
 *
 * @return nothing
 */
void print_statistics ( unsigned char a[], int n );

/**
 * @brief Print an array in a fancy way
 *
 * Takes a, an array of char of size n, and print it in a fancy way.
 *
 * @param a an array of char
 * @param n the lenght of array a
 *
 * @return nothing
 */
void print_array ( unsigned char a[], int n );

/**
 * @brief Return the median of an array
 *
 * Takes a, a sorted array of char of size n, and return its median
 *
 * @param a an array of char, sorted from largest to smaller
 * @param n the lenght of array a
 *
 * @return the median of a
 */
unsigned char find_median ( unsigned char a[], int n );

/**
 * @brief Return the mean of an array
 *
 * Takes a, a sorted array of char of size n, and return its mean
 *
 * @param a an array of char, sorted from largest to smaller
 * @param n the lenght of array a
 *
 * @return the mean of a
 */
unsigned char find_mean ( unsigned char a[], int n );

/**
 * @brief Return the maximum of an array
 *
 * Takes a, an sorted array of char of size n, and return its maximum
 *
 * @param a an array of char, sorted from largest to smaller
 * @param n the lenght of array a
 *
 * @return the maximum of a
 */
unsigned char find_maximum ( unsigned char a[], int n );

/**
 * @brief Return the minimum of an array
 *
 * Takes a, a sorted array of char of size n, and return its minimum
 *
 * @param a an array of char, sorted from largest to smaller
 * @param n the lenght of array a
 *
 * @return the minimum of a
 */
unsigned char find_minimum ( unsigned char a[], int n );

/**
 * @brief Sort an array form largest to smaller
 *
 * Takes a, an array of char of size n, and sort it from largest to smaller.
 * For efficiency, using an heap sort algorithm.
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 *
 * @param a an unsorted array of char
 * @param n the lenght of array a
 *
 * @modify a
 * @effects a is sorted from largest to smaller
 *
 * @return nothing
 */
void sort_array ( unsigned char a[], int n );

/**
 * @brief Auxiliary function used to heapify an tree
 *
 * @param a an array of char
 * @param n the limit index of the subarray
 * @param i the root index of the subarray
 *
 * @modify a
 * @effects a[i..n-1] is recursively transformed as a min-heap.
 * 
 * @return nothing
 */
void heapify ( unsigned char a[], int n, int i );

#endif /* __STATS_H__ */