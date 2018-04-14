// Week 7 Notes
gcc -g -std=c11 -Wall -Wextra -Wpedantic Lab5.c -o lab5.out
// Class Covers Systems Programming!
//scientific / floating point
-lm // used when math.h is included "libm" 

// C Pre-processor directives
#include <tgmath.h> // will work with abs of type fabslong, fabsfloat, and fabs

#include // # is from the preprocessor.c from the C compiler (which tells the precompiler to fetch the library)

#define CUBE(I) (I) * (I) * (I) // use more parenthesis if need be

#if define(SYM)
#ifdef SYM
#ifndef 
// 3 above may take a 
#else, #elsif
// close with this code
#endif


// a vector is a one dimentional array
// argv is a one dimentional array of strings

//random numbers
rand() // not really random if you don't feed srand
RAND_MAX
srand()

// algorithms 
qsort() // void sqsort(void *base, size_t nmemb, size_t size, int(*compar), (const void*, const void*));
qsort(a,5,sizeof(int),copmare_ints));

// using a fuction to compare ints use void* because quicksort 
// can compare multiple types
int compare_ints(void *pi1, void*pi2){
int *p1 = pi1;
int i1 = *pi1;
//cast option
int i2 = *(int*)pi2); // i2 is int so can't set to void*pi2
// (int*)pi2 casts as point
// can't set to i2 because int = pointer no good!
// add cast again to be able to set =
if (i1 < i2){
    return -1;
}
else if(i1>i2){
    return +1;
}
else {
    return();
}

// Lab 7
// find by email should return -1 if can't find
// will have to change commands.c and main.c in order to "searching for stuff" using binary search 
// call qsort()bsearch() in faculty array that is sorted 
// and write a makefile

// pointers are dynamically allocated data of different kinds

