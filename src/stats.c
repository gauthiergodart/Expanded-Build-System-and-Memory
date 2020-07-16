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
 * @file stats.c 
 * @brief stats.c is a set of statistical functions that can be used with an array.
 *
 * stats.c is a set of statistical functions that can be used with an array. 
 * Each function takes two inputs: an array of unsigned char, and its length. 
 * Most of the functions return a unsigned char (max, min, med, mean). Some of 
 * them returns nothing, but print statistical informations on the screen. 
 *
 * @author Gauthier Godart
 * @date July 2 2020
 *
 */

#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main2() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,  45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90 };

  /** 
   * NOTE FOR MY PEER-REVIEWER
   * The specs didn't specifically asked for keeping statistical data in memory
   * So, in order to keep the code as light as possible, it is possible not 
   * to use any data structure, by directly printing these information.
   * That's the idea here. print_statistics print all these information, 
   * by calling the subsidiary functions.
   * It would have been quite easy to keep these datas in memory, by calling
   * the subsidiary functions from main and assigning the return values to a 
   * bunch of variables, or any data structure. But our code would have been 
   * less efficient.
  */
  print_statistics(test, SIZE);
                               
}

void print_statistics ( unsigned char a[], int n ) {
	
	// First, print the array

	printf("Array:\n");
	print_array(a, n);
	
	// Then, sort the array and re-print it
	printf("Sorted array:\n");
	sort_array(a, n);
	print_array(a, n);
	
	// Finally, print all the statistics, rounded to the nearest integer
	printf(" _____________________\n");
	printf("|                     |\n");
	printf("|  Median:  %3i       |\n", find_median(a, n));
	printf("|  Mean:    %3i       |\n", find_mean(a, n));
	printf("|  Maximum: %3i       |\n", find_maximum(a, n));	
	printf("|  Minimum: %3i       |\n", find_minimum(a, n)); 
	/**	
	 * NOTE FOR MY PEER-REVIEWER
	 * find_maximum and find_minimum calls are quite useless, 
	 * as we may have directly given a[0] and a[n-1] here, 
	 * the array being sorted... 
	 * But, it is what the specs asked for. 
	 */

	printf("|_____________________|\n\n");
}

void print_array ( unsigned char a[], int n ) {
	#ifdef VERBOSE
	int i;
	PRINTF(" _____________________\n");
	PRINTF("|                     |\n");
	PRINTF("|  %3i", a[0]);
	for ( i = 1; i < n; i++ ) {
		if ( i%4 == 0)
			PRINTF(" |\n|  %3i", a[i]);
		else 
			PRINTF(", %3i", a[i]);
	}
	if ( n%4 != 0) {
		for ( i=0; i<(4-(n%4)); i++)
			PRINTF("     ");
	}
	PRINTF(" |\n");
	PRINTF("|_____________________|\n\n");
	#endif
}

unsigned char find_median ( unsigned char a[], int n ) {
	if ( n%2 == 0 )
		return ( a[n/2] + a[ (n-1)/2 ] ) /2;
	else 
		return a[n/2];
}

unsigned char find_mean ( unsigned char a[], int n ) {
	int sum = 0;
	for ( int i=0; i<n; i++ )
		sum += a[i];

	return sum/n;
}

// Purely useless function
unsigned char find_maximum ( unsigned char a[], int n ) { return a[0]; }

// Purely useless function
unsigned char find_minimum ( unsigned char a[], int n ) { return a[n-1]; }

void sort_array ( unsigned char a[], int n ) {
	for ( int i=n/2-1; i>=0; i-- )
		heapify ( a, n, i );

	for ( int i = n-1; i>0; i--) {
		/** 
		 * Take the root (the smallest element). Swap it with the last element 
		 * of the subtree. a[i..n-1] is now correctly sorted. Heapify the 
		 * subtree a[0..i-1], and so on. 
		 */
		unsigned char tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		heapify(a, i, 0);
	}
}

void heapify ( unsigned char a[], int n, int i ) {
	int smallest = i; // Initialize smallest as root 
	int l = 2*i + 1;  // Left child
	int r = 2*i + 2;  // Right child

	// If left child is smaller than root 
	if ( l < n && a[l] < a[smallest] ) 
		smallest = l; 

	// If right child is smaller than smallest so far 
	if ( r < n && a[r] < a[smallest] ) 
		smallest = r; 

	// If root is not smallest 
	if ( smallest != i ) { 
		// Swap
		unsigned char tmp = a[i];
		a[i] = a[smallest];
		a[smallest] = tmp;
		// Recursively heapify the affected sub-tree 
		heapify ( a, n, smallest ); 
	}
}