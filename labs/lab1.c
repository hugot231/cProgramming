// Course: CPSC223C
// Assignment: Lab 1
// Name: Hugo Trejo
// Email: trejo231@csu.fullerton.edu
//
// Objective: Covert lab1.cpp to lab1.c using C11
// Program Description: This program takes in no inputs. Some simple doubling of a number is the product of one function. The other function appends to a character array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>

#define MaxLen 10 /* Max length = 1000*/

// #include <string> no such thing?

// bump function
// c does not support reference parameters
void bump(int* i, int *amount)
{

    assert(i != NULL);// check to see if value is NULL
    
	if (amount == NULL)
	{
		*i += 1; // multiply i by 1 if amount == NULL
	}
	else
	{
		*i += *amount; // add amount and i and set to i
	}
}

// function to append a character to a character string
void bumpString(char *s, char *c)
{
    assert(s != NULL); // make sure s is not NULL
	int len = strlen(s); // get the string.h length of the char
	if (len + 1 <= MaxLen){ // check that there is enough space to append to memory
	    s[len] = *c;
    	s[len+1] = '\0';
	}
}

// main function
int main(void)
{
	int i = 1;
	printf("%d\n", i); // printf 1 
	bump(&i, NULL);
	printf("%i\n", i); // printf 2 
	
	int amount = 2;
	bump(&i, &amount); // referenced value of i, bump by 2
	printf("%i\n", i); // printf 4

	// initialize array of size MaxLen
	char s[MaxLen] = "foo";
	
	char a = 'o';
	printf("%s\n", s); // print "foo"
	bumpString(s, &a); // append an o to "foo"
	printf("%s\n", s); // prints fooo
	
	a = 'x';
	bumpString(s, &a); // append an x to "fooo"
	printf("%s\n", s); // prints fooox
	return 0;
}
