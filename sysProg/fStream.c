// this is a program used to test in/out from files
#include <stdio.h>
#include <stdlib.h>

int 
main(int argc, char *argv[])
{
	int c;
	FILE *in, *out;
	
	if (argc!=3) {
		fprintf(stderr, "Usage: append-char file1 file2\n");
		exit(1);
	}	 
	// open the first file for reading and do a check	
	// if pointer to stream is NULL, exit
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		perror(argv[1]);
		exit(1);
	}
	// open the second file for writing
	// if pointer to stream is NULL, exit
	if ((out = fopen(argv[2], "w")) == NULL)
	{
		perror(argv[2]);
		exit(1);
	}
	// copy data from first file to second a character at a time
	// putc(c,out); does not append, it puts to the first location in the file!!!
	while((c = getc(in)) != EOF){ // gets character from pointer to stream 
		putc(c, out); // appends the char to out pointer stream
	}
	fclose(out);
	fclose(in);
	
	exit(0);
}
