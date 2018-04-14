// 
// notes on dynamic allocation

// the heap manager has memory that you can use to store information about what they can do.

// using c++ 
Foo *f = new Foo(); //request a heap block of sizeof(Foo)
// run Foo's constructor to initialize 
// check if f is full


//****  using C 
#include <stdlib.h>

// create a struct function w/ out typedef
struct foo
{
	int a = 2;
	char c = 'b';
};

// malloc is part of stdlib.h so you must use to create dynamic memory
// f is a pointer to a struct named foo

struct foo *f;
// allocating memory to the pointer f
f = malloc(sizeof(struct foo));

// creating a pointer with memory size of choice?? ???????????
// Must find what size to pass
// included in stdlib.h
// void *malloc(size_t size);

// freeing memory that's been allocated
// included in stdlib.h
// void free(void *block)


int *a = malloc(10 *sizeof(int)); 
// increase to 20 
// freeing will not insure memory block f 
int * b = malloc(10 *sizeof(int)); 
 
// for loop to set array a into array b; 
// OR use memcpy(); // essential C section 7! 
free(a); 
a = malloc(20*sizeof(int));   
 
// alternate use using realloc 
// reallocate frees a (DON’T USE a) 
// memory might not be enough if heap manager doesn’t keep enough space 
void *realloc(void *block, size_t size); 
b = realloc(a, sizeof(int)); 

void my_realloc(void *block, size_t size);

// man gdb 
// gcc -g debugging information 
// compile with -g!!!
// gcc -g0 for debugging optimization
// -std=c11 includes c11

