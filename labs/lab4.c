// lab4.c - starter code for Lab 4

/*
 * This program uses 13 hard coded values, in hex format, from a linked lists to compute calculations. 
*/
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_SIZE 3
#define PROGRAM_SIZE 13

uint8_t byte = 1; // byte of type usigned 8 bit value to keep track of the hex values

struct node {
    int line;
    char command[MAX_COMMAND_SIZE + 1];
    unsigned int argument;

    struct node *next;
};

struct node *create_node(int line, char *command, unsigned int argument)
{
    assert(strlen(command) <= MAX_COMMAND_SIZE);

    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__); 
        exit(EXIT_FAILURE);
    }

    new->line = line;
    strcpy(new->command, command);
    new->argument = argument;

    new->next = NULL;

    return new;
}

struct node *append_node(struct node *start, struct node *new)
{
    assert(start != NULL);

    struct node *current = start;
    
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;

    return new;
}

// function to print the current node information
void print_node(struct node *n)
{
    printf("%2d %s %x\n", n->line, n->command, n->argument);
}

// prints the whole list using a while statement
void print_list(struct node *start)
{
    struct node *current = start;

	// while current is not null call to print and move pointer to next. 
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

// creates the list and adds the information 
struct node *create_list(void)
{
    struct node *head, *next;
    int line = 1;

    head = create_node(line++, "set", 0x1);
    next = append_node(head, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "or", 0x1));
    next = append_node(next, create_node(line++, "or", 0x2));
    next = append_node(next, create_node(line++, "shl", 0x2));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "and", 0x4));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "and", 0x3));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "shr", 0x1));

    return head;
}

// print the current, previous and next
void doStep(struct node *start) {

	struct node *current = start;
	// compare the commands and 
    if (strcmp(current->command, "set") == 0) {
        byte = current->argument;
    } 
    else if (strcmp(current->command, "and") == 0) {
        byte &= current->argument;
    } 
    else if (strcmp(current->command, "or") == 0) {
        byte |= current->argument;
    } 
    else if (strcmp(current->command, "xor") == 0) {
        byte ^= current->argument;
    } 
    else if (strcmp(current->command, "shr") == 0) {
        byte >>= current->argument;
    } 
    else if (strcmp(current->command, "shl") == 0) {
        byte <<= current->argument;
    }	
}

void doContinue(struct node *start){
	struct node *current = start;
	// run through each node to accomplish each command
	while (current != NULL) {
		doStep(current);
      //print_node(current);
      current = current->next;
   }
}

void doPrint(){
	printf("%x\n", byte); // %x is unsigned int 
}

// print prev, current and next command
void doList(struct node *start, struct node *behind){
	struct node *current;
	current = start;
	
	if (current->line == 1) { // if at beginning print current and next
	    print_node(current);
	    print_node(current->next);
	}
	else if (current->line == 10){ 
	// counter at end only print current and previous
			print_node(current);
			print_node(behind);
	}
	else { // counter is in the middle print prev, current and next
		    print_node(behind);
			print_node(current);
			print_node(current->next);
	}
}

// free the current list
void free_list(struct node *start)
{
    struct node *prev, *current;

    current = start;
    while (current != NULL) {
        prev = current;    
        current = current->next;
        free(prev);
    }
}

int main(void)
{
    struct node* head = create_list();
    struct node* behind = NULL;
    char command[MAX_COMMAND_SIZE + 1];

	while (scanf("%s", command) != EOF){
		if(strcmp(command, "step") == 0)
		{   //printf("%s\n", "step matched");
			behind = head;
			doStep(head);
			 if(head->next != NULL)
    		{
    				head = head->next;
    		}
    		else head = NULL;
		}
		else if(strcmp(command, "continue") == 0)
		{  // printf("%s\n", "continue matched");
			doContinue(head);
		}
		else if(strcmp(command, "print") == 0)
		{   //printf("%s\n", "print matched");
			doPrint();
		}
		else if(strcmp(command, "list") == 0)
		{   //printf("%s\n", "list matched");
			doList(head, behind);
		}
	}
	free_list(behind);
    free_list(head); 

    return EXIT_SUCCESS;
}
