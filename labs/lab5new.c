// lab5.c - starter code for Lab 5

/*
 * Complete the definitions for the stack_*() functions so that main()
 * prints the reverse of its command-line arguments. For example:
 *
 *  $ ./reverse foo bar baz
 *  zab rab oof
 *
 * Be sure that your code passes "--leak-check=full" with Valgrind.
 *
 */
// run with -g -Og -Wall 
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    struct stack_element *top;
    int element_count;
};

struct stack_element {
    unsigned char c;
    struct stack_element *next;
};

struct stack *stack_create(void)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    
    // INSERT CODE HERE
    s->top=NULL;
    s->element_count = 0; // set element count to 0

    return s;
}

int stack_pop(struct stack *s)
{
    assert(s != NULL);
    unsigned char c = EOF;
    
    // INSERT CODE HERE
    if(s->element_count > 0){
        struct stack_element *temp = s->top;// point temp to top
        c = temp->c;
    	s->element_count--;// decrease the count
    	s->top = temp->next;
    	
        free(temp);
     }

    return c;
}

void stack_push(struct stack *s, unsigned char c)
{
    assert(s != NULL);
		
    	struct stack_element *temp = malloc(sizeof(struct stack_element)); // creating a new node
		if (s == NULL) {
			fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
	    }
    	temp->c=c;
    	temp->next = s->top;		
    	
    	s->element_count++;
    	s->top=temp;
}

void stack_destroy(struct stack *s)
{
    assert(s != NULL);

    while (s->element_count > 0) {
        stack_pop(s);
    }

    free(s);
}

int main(int argc, char *argv[]) // count arg, vector arg
{   
	// print 
    for (int i = 0 ; i < argc; i++) {
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
    }
    
    // create the stack pointer 
    struct stack *s = stack_create();

    for (int i = argc - 1; i > 0; i--) {
        char *arg = argv[i];

        for (size_t j = 0; j < strlen(arg); j++) {
            stack_push(s, arg[j]);
        }

        char c;
        while ((c = stack_pop(s)) != EOF) {
            printf("%c", c);
        }

        printf(" ");
    }
    printf("\n");
    free(s);

    return EXIT_SUCCESS;
}
