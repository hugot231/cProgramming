// Course: CPSC223C
// Lab 3
// By: Hugo Trejo	
// Objective: Create a debug-calculator that calculates hexadecimal and allows you
// 	to step through the commands one at a time. In order to do this, you 
// 	will need to store commands in memory (by hard coding them into an array of type struct, rather than reading them one at a time:
// 	
#include <stdio.h> 
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "bstrlib.h"

#define PROGRAM_SIZE 13

// defines a struct with a command, argument, & lineNumber
struct calculate
{
	int line;
	bstring command;
	unsigned int argument; // why unsigned ?
}; // typedef name


// defines an array of structs to save the commands in memory
struct calculate program[] = {
// use for look in main to bstr = "set"
    [0] = {  .line = 1, .argument = 0x1  },
    [1] = {  .line = 2, .argument = 0x1  },
    [2] = {  .line = 3, .argument = 0x1  },
    [3] = {  .line = 4,  .argument = 0x1  },
    [4] = {  .line = 5,  .argument = 0x2  },
    [5] = {  .line = 6, .argument = 0x2  },
    [6] = {  .line = 7, .argument = 0x10 },
    [7] = {  .line = 8, .argument = 0x10 },
    [8] = {  .line = 9, .argument = 0x4  },
    [9] = {  .line = 10, .argument = 0x1c },
    [10] = { .line = 11, .argument = 0x3  },
    [11] = { .line = 12, .argument = 0x1c },
    [12] = { .line = 13, .argument = 0x1  }    
};
char commands[13][3] = {"set", "shl", "shl", "or", "or","shl", "xor", "xor", "and", "set", "and", "set", "shr"};
int counter = 0; // used to only account for 13 commands
uint8_t byte = 0; 

void doStep()
{
	if (counter >= PROGRAM_SIZE) {
        return;
    }
    
    struct calculate next = program[counter++]; // holds the information of the next item in struct
    
    if (biseqStatic(next.command, "set") == 0) {
        byte = next.argument;
    } 
    else if (biseqStatic(next.command, "and") == 0) {
        byte &= next.argument;
    } 
    else if (biseqStatic(next.command, "or") == 0) {
        byte |= next.argument;
    } 
    else if (biseqStatic(next.command, "xor") == 0) {
        byte ^= next.argument;
    } 
    else if (biseqStatic(next.command, "shr") == 0) {
        byte >>= next.argument;
    } 
    else if (biseqStatic(next.command, "shl") == 0) {
        byte <<= next.argument;
    }
}

void doContinue() { // for loop to go through the rest of the calculator commands
	for (int i = counter; i < PROGRAM_SIZE; i++) {
		doStep();
	}
}

void doPrint() {
	printf("%x\n", byte);
}

void printStatement(int i) {
	printf("%2d %s %x\n", program[i].line, program[i].command->data, program[i].argument);
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
{	// set character array to command of type bstring
    for (int i = 0; i < PROGRAM_SIZE; i++){
        program[i].command = bfromcstr(commands[i]); 
    }
    //bstring is a pointer!
	bstring cmd;
    // for loop to set the values for command for set and or xor shl shr
	
	// use if statement here to get the command using bgets
	while((cmd = bgets((bNgetc) fgetc, stdin, '\n'))  != NULL) {
		if(biseqStatic(cmd, "set\n") == 1)
		{
			doStep();
		}
		else if(biseqStatic(cmd, "continued\n") == 1)
		{
			doContinue();
		}
		else if(biseqStatic(cmd, "print\n") == 1)
		{
			doPrint();
		}
		else if(biseqStatic(cmd, "list\n") == 1)
		{
			doList();
		}
		bdestroy(cmd);
    }
    for (int i = 0; i < PROGRAM_SIZE; i++){
        bdestroy(program[i].command);
    }
	return 0;
}
