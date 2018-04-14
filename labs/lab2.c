// Course: CPSC223C
// Lab 2
// By: Hugo Trejo	
// Objective: Create a calculator that calculates hexadecimal 
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <assert.h>

#define MaxLen 3 // define max value of 3 bytes

// why use uint_t and not int? 
// int = 32 bits depending
// uin8_t = 8 bits unsigned
int byte = 0; // byte value to perform apperations on 

int main(void)
{
	unsigned int argument = 0; 
	char command[MaxLen];

	// while it still reads in two values
	// scanf reads in what is passed to it
	while(scanf("%s %x", command, &argument) == 2)
	{   
	    bool output = true;// bool for testing if command is read in matches
		if(strcmp(command, "set") == 0)
		{
			byte = argument;
		} else if(strcmp(command, "and") == 0)
		{// and function
			byte &= argument;
		} else if(strcmp(command, "or") == 0)
		{// or function
			byte |= argument;
		} else if(strcmp(command, "xor") == 0)
		{// xor function
			byte ^= argument;
		} else if(strcmp(command, "shr") == 0)
		{// shift right function
			byte >>= argument;
		}
		else if(strcmp(command, "shl") == 0)
		{// shift left function
			byte <<= argument;
		} else 
		{   output = false;
			printf("Command Not Recognized\n");
		} 
		if (output){
		    printf("%s %x => %x\n", command, argument, byte);
	    }
	}
	return 0;
}
