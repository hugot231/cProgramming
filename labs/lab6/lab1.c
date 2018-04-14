// Course: CPSC223C
// Assignment: Lab 1 used for Lab 6
// Name: Hugo Trejo
// Email: trejo231@csu.fullerton.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstrlib.h"

#define MaxLen 3 /* Max length = 1000*/

// bump function
void bump(int* i, int amount)
{
	if (amount)
	{
	    *i += amount;
	}
}

// main function
int main(void)
{
// calls to bump
	int i = 1;
	printf("%i\n", i); // print a 32 bit integer
	bump(&i, 1); // calling to function bump using a referenced value of i to be returned
	
	printf("%i\n", i); // printf of int i;
	bump(&i,2); // calling to function bump using a referenced value of i to be returned
	printf("%i\n", i); // printf of int i;

    char s[Maxlen] = "foo"; //used for standard c library "array of char"
    //bstring is a pointer!
	bstring theString = bfromcstr(s);

    if (!theString) {
        fprintf (stderr, "Out of memory");
    } else {
        puts ((char *) theString->data); // prints theString->data
        printf("%s\n", theString->data); // print string
    }
	// funtion to append a char to a bstring
    bcatStatic (theString, "o"); //pass only the object and not the object data!
    printf("%s\n", theString->data); // print "fooo"

    bcatStatic (theString, "x"); // pass only the object and not the object data!
    printf("%s\n", theString->data); // print "foox"

    bdestroy(theString);
	return 0;
}
