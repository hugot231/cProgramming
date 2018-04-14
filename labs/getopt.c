#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
* Sub-options.
*/
char *subopts[] = {
#define COLOR 0
 "color",
#define SOLID 1
 "solid",
 NULL
};
int main(int argc, char **argv)
{
	int c;
	char fileName[1024]; // used to store fileName	

	/*
	* Process the arguments.
	*/
	while ((c = getopt(argc, argv, "cf:o:st")) != -1) 
 	{
	 	switch (c) 
	 	{
		 	case 'c':
		 		printf("circle\n");
		 		break;
		 	case 'f':
		 			strcpy(fileName, "filename: ");
		 			strcat(fileName, optarg);
		 			printf("%s \n", fileName);
				break;
		 	case 's':
		 		printf("square\n");
		 		break;
		 	case 't':
		 		printf("triangle\n");
		 		break;
		 	case '?':
		 		printf("command line error\n");
		 		break;
		 	case 'o':
		 		options = optarg;
		 }
	}
	/* Process extra arguments.
 	*/
	 for (; optind < argc; optind++) 
	 {
	 	strcpy(fileName, "extra argument: ");
	 	strcat(fileName, argv[optind]);
	 	printf("this is the fileName:%s \n", fileName);
	 }
 exit(0);
}
