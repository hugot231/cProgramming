// Course: CPSC223C
// Lab 3
// By: Hugo Trejo	
// Objective: Create a debug-calculator that calculates hexadecimal and allows you
// 	to step through the commands one at a time. In order to do this, you 
// 	will need to store commands in memory, rather than reading them one at a time:
// 	
#include <stdio.h> 
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_SIZE 3
#define PROGRAM_SIZE 13

// defines a struct with a command, argument, & lineNumber
typedef struct calculate
{
	int line;
	char command[MAX_COMMAND_SIZE +1];
	unsigned int argument; // why unsigned ?
} CALC; // typedef name


// defines an array of structs to save the commands in memory
CALC program[] = {
    [0] = {  .line = 1,  .command = "set", .argument = 0x1  },
    [1] = {  .line = 2,  .command = "shl", .argument = 0x1  },
    [2] = {  .line = 3,  .command = "shl", .argument = 0x1  },
    [3] = {  .line = 4,  .command = "or",  .argument = 0x1  },
    [4] = {  .line = 5,  .command = "or",  .argument = 0x2  },
    [5] = {  .line = 6,  .command = "shl", .argument = 0x2  },
    [6] = {  .line = 7,  .command = "xor", .argument = 0x10 },
    [7] = {  .line = 8,  .command = "xor", .argument = 0x10 },
    [8] = {  .line = 9,  .command = "and", .argument = 0x4  },
    [9] = {  .line = 10, .command = "set", .argument = 0x1c },
    [10] = { .line = 11, .command = "and", .argument = 0x3  },
    [11] = { .line = 12, .command = "set", .argument = 0x1c },
    [12] = { .line = 13, .command = "shr", .argument = 0x1  },
};

int counter = 0; // used to only account for 13 commands
uint8_t byte = 0; // used as argument to alter

void doStep()
{
	if (counter >= PROGRAM_SIZE) {
        return;
    }
    
    CALC next = program[counter++]; // holds the information of the next item in struct program array
    
    if (strcmp(next.command, "set") == 0) {
        byte = next.argument;
    } 
    else if (strcmp(next.command, "and") == 0) {
        byte &= next.argument;
    } 
    else if (strcmp(next.command, "or") == 0) {
        byte |= next.argument;
    } 
    else if (strcmp(next.command, "xor") == 0) {
        byte ^= next.argument;
    } 
    else if (strcmp(next.command, "shr") == 0) {
        byte >>= next.argument;
    } 
    else if (strcmp(next.command, "shl") == 0) {
        byte <<= next.argument;
    }
}

void doContinue() { // for loop to go throught the rest of the calculator commands
	for (int i = counter; i < PROGRAM_SIZE; i++) {
		doStep();
	}
}

void doPrint() {
	printf("%x\n", byte);
}

void printStatement(int i) {
	printf("%2d %s %x\n", program[i].line, program[i].command, program[i].argument);
}

void doList() {
	if (counter == 0) { // counter is at the beginning
        printStatement(counter);
        printStatement(counter + 1);		
	}
	else if (counter >= PROGRAM_SIZE - 1) { // counter is at the end
        printStatement(PROGRAM_SIZE - 2);
        printStatement(PROGRAM_SIZE - 1);
   } 
   else { // counter is in between
        printStatement(counter - 1);
        printStatement(counter);
        printStatement(counter + 1);
   }
}

int main(void)
{	
	char command[MAX_COMMAND_SIZE + 1];

	while(scanf("%s", command) != EOF) 
	{
		if(strcmp(command, "set") == 0)
		{
			doStep();
		}
		else if(strcmp(command, "continue") == 0)
		{
			doContinue();
		}
		else if(strcmp(command, "print") == 0)
		{
			doPrint();
		}
		else if(strcmp(command, "list") == 0)
		{
			doList();
		}
	}
	return 0;
}

