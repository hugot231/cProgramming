// Notes From Book
gcc -g -Og -std=c11 -Wall -Wextra -Wpedantic Lab5.c -o lab5.out
valgrind "stuff" lab1

// parsing command line arguments

// Used for Sizes
%d //  "signed" digit
%.02f //"float" has precision of 6 decimals)
%u // "unsigned" 
bool stands for "unsigned" #include stdbool.h
%s //  "string"
%c //  "char"
%p //  "pointer"
%zu //  "size_t" (unsigned int, & added for c99, c11)
%g//  "get floating"
%i //   integer 
%x // "unsigned int"

#include <stdint.h> 
size_t SIZE_MAX;
The value of SIZE_MAX is quite large, depending on the platform it should be one of
2^16 − 1 = 65535
2^32 − 1 = 4294967295
2^64 − 1 = 18446744073709551615

#include <tgmath.h>
// example of using fabs
void getAbsolute(double a)
{
	fabs(a - 10):
	printf("Double: %d\n", a);
}
// example of using sqrt
# ifdef __STDC_NO_COMPLEX__
 # error "we need complex arithmetic "
# endif

double complex sqrt_real ( double x) {
	return (x < 0) ? CMPLX (0 , sqrt ( -x) ) : CMPLX ( sqrt (x) , 0) ;
}

//************************** start function

void do_something()
{
	printf("Do Something Function.\n");{{{
	fabs(a - 10):
	fabs(a - 10):
	fabs(a - 10):
}

// functions that are needed to interpret unsigned values as signed one
bool is_negative(unsigned a)
{
	unsigned const int_max = UINT_MAX/2;
	return a > int_max;
}

// function that compares two numbers and returns if smaller or signed
bool isSignedLess(unsigned a, unsigned b)
{
	if(is_negative(b) && !is_negative(a)) 
		return false;
	else 
		return a < b;
}
	
printf("Dealing with overflow\n");
// Unsigned values wrap around
// Signed values overflow undefined when doing arithmetic
for (unsigned i = 1; i; ++i) do_something();

//  signed arithmeticoptimized to an infinite loop
for (signed i = 1; i; ++i) do_something();
while(true) do_something();

// size_t type are never negative!
for (size_t i = 0; i < 10; i++)
{
	do_something();
}

// do{} while(); ends with semicolon!

// for loop as while loop
for(;;){}; 
while(true){}


// switch statement instead of if else iteration 
switch (arg ) // instead of if (arg == "")
	{
 case ’m’: puts (" this ␣is␣a␣ magpie ") ;
 break ;
 case ’r’: puts (" this ␣is␣a␣ raven ") ;
 break ;
 case ’j’: puts (" this ␣is␣a␣jay ") ;
 break ;
 case ’c’: puts (" this ␣is␣a␣ chough ") ;
 break ;
 default : puts (" this ␣is␣an␣ unknown ␣ corvid ") ;
 }

// Better string library ******************************
// Header which wraps a pointer to a char buffer.

struct tabstring { 
	int mlen; // for memory of data @ low bound
	int slen; // for exact length for Bstring
	unsigned char *data; 
}

bstrcat (p = bfromcstr ("Hello,"), q = bfromcstr (" Worsld"));
        bdestroy (q);
// is well defined, because if either p or q are assigned NULL (indicating a failure to allocate memory) both bstrcat and bdestroy will recognize it and perform no detrimental action.

// Core C files (required for C)
bstrlib.c       - C implementaion of bstring functions.
bstrlib.h       - C header file for bstring functions.



	
