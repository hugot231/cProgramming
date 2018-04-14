// Course: CPSC223C
// Lab 7 (similar to lab 2) takes commands from a file and acts accordingly.
// This lab will use the Standard C input/output function and getopt()
// Commands: set, and, or, shl, shr
// By: Hugo Trejo	
// Objective: Create a calculator that calculates hexadecimal 
// $ gcc -g -std=c11 -Wall -Wextra -Wpedantic -D_POSIX_C_SOURCE=200801L  lab7.c -o lab7
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#define MaxLen 3 // define max value of 3 bytes
#define LengthFileName 1024
#define MAX_BYTE_COMMAND_SIZE 3
#define MAX_DEBUG_COMMAND_SIZE 8
#define PROGRAM_SIZE 13

// global variable, pointer
struct node *head;
struct node *current;
uint8_t byte = 0; // byte value to perform apperations on 
bool vflag = false;
bool dflag = false;

struct node {
    int line;
    char command[MAX_BYTE_COMMAND_SIZE + 1];
    unsigned int argument;

    struct node *next;
};

struct node *create_node(int line, char *command, unsigned int argument)
{
    assert(strlen(command) <= MAX_BYTE_COMMAND_SIZE);

	// allocate memory for the struct node *new 
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__); 
        exit(EXIT_FAILURE);
    }

    new->line = line;
    strcpy(new->command, command);
    new->argument = argument;

    new->next = NULL;

	// returnt the struct node *new because that is the type for the function
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

void print_node(struct node *n)
{
    printf("%2d %s %x\n", n->line, n->command, n->argument);
}

void print_list(struct node *start)
{
    struct node *current = start;

    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

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

void do_step()
{
    if (current == NULL) {
        return;
    }
    if (strcmp(current->command, "set") == 0) {
        byte = current->argument;
    } else if (strcmp(current->command, "and") == 0) {
        byte &= current->argument;
    } else if (strcmp(current->command, "or") == 0) {
        byte |= current->argument;
    } else if (strcmp(current->command, "xor") == 0) {
        byte ^= current->argument;
    } else if (strcmp(current->command, "shr") == 0) {
        byte >>= current->argument;
    } else if (strcmp(current->command, "shl") == 0) {
        byte <<= current->argument;
    }
	if (vflag)
	{
		printf("%s %x => %x\n", current->command, current->argument, byte);
    }
    current = current->next;
}

void do_continue()
{
    while (current != NULL) {
        do_step();
    }
}

void do_print()
{
    printf("%x\n", byte);
}

struct node *find_prev(struct node *start)
{
    struct node *prev = head;
	// go through list until next value is the start and set the pointer to the currents previous value
    while (prev->next != start) {
    	// keep pointer at previous value
        prev = prev->next;
    }
    return prev;
}

void do_list(struct node *head)
{
    if (current == head) {// at the front
        print_node(current);
        print_node(current->next);
    } else if (current == NULL) { // at the end
        struct node *prev = find_prev(current);
        struct node *prevprev = find_prev(prev);

        print_node(prevprev);
        print_node(prev);
    } else {
        struct node *prev = find_prev(current);

        print_node(prev);
        print_node(current);
        print_node(current->next);
    } 
}
	
int main(int argc, char *argv[])
{
	unsigned int argument = 0; 
	char fileName[LengthFileName + 1];
	char command[MaxLen +1];
	int inputs;
	FILE *fp;

	// read in the argument fileName
	// set it to the *input to FILE
		
	while((inputs = getopt(argc, argv, "vd")) != -1)
	{
		// case statement for -v and -d
		switch (inputs)
		{
			case 'v': // print  each byte command and it's result
				// call function to print byte and command 
				vflag = true;
				break;
			case 'd': // accept debug commands from standard input
				dflag = true;
				break;
			case '?':
				printf("%s \n", "Not a option.");
				break;
			default:
				
				break;
		}
	}
	for(; optind < argc; optind++)
	{
		strcpy(fileName, argv[optind]);
		//printf("File name is: %s\n", fileName); // test for fileName
		fp = fopen(fileName, "r"); // open file 
		while (fscanf(fp, "%s %x", command, &argument) != EOF) 
		{
			do_step();
		
			if (strcmp(command, "set") == 0) {
				byte = argument;
			} else if (strcmp(command, "and") == 0) {
				byte &= argument;
			} else if (strcmp(command, "or") == 0) {
				byte |= argument;
			} else if (strcmp(command, "xor") == 0) {
				byte ^= argument;
			} else if (strcmp(command, "shr") == 0) {
				byte >>= argument;
			} else if (strcmp(command, "shl") == 0) {
				byte <<= argument;
			}
			if(vflag && !dflag)
			{
				printf("%s %x => %x\n", command, argument, byte);
			}
		}
		fclose(fp);
		if (dflag)
		{
			head = create_list();
			current = head;

			char command[MAX_DEBUG_COMMAND_SIZE + 1];

			while (scanf("%s", command) != EOF) {
				if (strcmp(command, "step") == 0) {
					do_step();
				} else if (strcmp(command, "continue") == 0) {
					do_continue();
				} else if (strcmp(command, "print") == 0) {
					do_print();
				} else if (strcmp(command, "list") == 0) {
					do_list(head);
				}
			}
			free_list(head);
		}
	}
	
	return 0;
}
