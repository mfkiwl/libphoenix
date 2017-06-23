/*
 * Phoenix-RTOS
 *
 * libphoenix
 *
 * stdlib.h
 *
 * Copyright 2017 Phoenix Systems
 * Author: Pawel Pisarczyk
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#ifndef _LIBPHOENIX_STDLIB_H_
#define _LIBPHOENIX_STDLIB_H_

#include ARCH


typedef struct {
  int quot;
  int rem;
} div_t;


typedef struct {
  long int quot;
  long int rem;
} ldiv_t;


typedef s16 wchar_t;


/* Converts the string pointed to, by the argument str to a floating-point number (type double). */
extern double atof(const char *str);


/* Converts the string pointed to, by the argument str to an integer (type int). */
extern int atoi(const char *str);


/* Converts the string pointed to, by the argument str to a long integer (type long int). */ 
extern long int atol(const char *str);


/* Converts the string pointed to, by the argument str to a floating-point number (type double). */ 
extern double strtod(const char *str, char **endptr);


/* Converts the string pointed to, by the argument str to a long integer (type long int). */ 
extern long int strtol(const char *str, char **endptr, int base);


/* Converts the string pointed to, by the argument str to an unsigned long integer (type unsigned long int). */
extern unsigned long int strtoul(const char *str, char **endptr, int base);


/* Allocates the requested memory and returns a pointer to it. */
extern void *calloc(size_t nitems, size_t size);


/* Deallocates the memory previously allocated by a call to calloc, malloc, or realloc. */
extern void free(void *ptr);


/* Allocates the requested memory and returns a pointer to it. */
extern void *malloc(size_t size);


/* Attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc. */ 
extern void *realloc(void *ptr, size_t size);


/* Causes an abnormal program termination. */ 
extern void abort(void);


/* Causes the specified function func to be called when the program terminates normally. */ 
extern int atexit(void (*func)(void));


/* Causes the program to terminate normally.*/ 
extern void exit(int status);


/* Searches for the environment string pointed to by name and returns the associated value to the string. */ 
extern char *getenv(const char *name);


/* The command specified by string is passed to the host environment to be executed by the command processor. */ 
extern int system(const char *string);


/* Performs a binary search.*/ 
extern void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));


/* Sorts an array. */ 
extern void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));


/* Returns the absolute value of x. */ 
extern int abs(int x);


/* Divides numer (numerator) by denom (denominator). */ 
extern div_t div(int numer, int denom);


/* Returns the absolute value of x. */ 
extern long int labs(long int x);


/* Divides numer (numerator) by denom (denominator). */
extern ldiv_t ldiv(long int numer, long int denom);


/* Returns a pseudo-random number in the range of 0 to RAND_MAX. */
extern int rand(void);


/* This function seeds the random number generator used by the function rand. */
extern void srand(unsigned int seed);


/* Returns the length of a multibyte character pointed to by the argument str. */
extern int mblen(const char *str, size_t n);


/* Converts the string of multibyte characters pointed to by the argument str to the array pointed to by pwcs. */
extern size_t mbstowcs(wchar_t *pwcs, const char *str, size_t n);


/* Examines the multibyte character pointed to by the argument str. */
extern int mbtowc(wchar_t *pwc, const char *str, size_t n);


/* Converts the codes stored in the array pwcs to multibyte characters and stores them in the string str. */
extern size_t wcstombs(char *str, const wchar_t *pwcs, size_t n);


/* Examines the code which corresponds to a multibyte character given by the argument wchar. */
extern int wctomb(char *str, wchar_t wchar);


#endif