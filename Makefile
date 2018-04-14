

#//  a simple program for makefile
#// set a variable for your compiler type
#// set a variable for your compiler flags
#// set a variable for your linker flags
#// set a variable for your output program
#// set a ariable for .c  .h files
#// .c files produce .o files (main.c does not have .h file)

#// variable declerations
CC = gcc
CFLAGS = -g -I/usr/class/cs107/include
LDFLAGS = -L/usr/class/cs107/lib -lgraph
#// program names and 
PROG = program
HDRS = binky.h akbar.h defs.h
SRCS = main.c binky.c akbar.c

// variable decleration of OBJS as .o from .c
//## This incantation says that the object files have the same name as the .c files, but with .o
OBJS = $(SRCS:.c=.o)

//## first rule (rules have dependency line and command line)
//## This is the first rule (the default)
//## Build the program from the three .o's 
$(PROG) : $(OBJS)
    $(CC) $(LDFLAGS) $(OBJS) -o $(PROG)

//## Rules for the source files
// these do not have second build rule lines, so they will use the default build rule to compile X.c to make X.o
// outputFile: sourceFiles
main.o : main.c binky.h akbar.h defs.h
binky.o : binky.c binky.h
akbar.o : akbar.c akbar.h defs.h

//## Remove all the compilation and debugging files
clean :
    rm -f core $(PROG) $(OBJS)
//## Build tags for these sources
TAGS : $(SRCS) $(HDRS)
    etags -t $(SRCS) $(HDRS)





//Basic POSIX Signal Handling
// First part of the signal handling
// Ch.10!!
#include <signal.h> 
// you get
typedef void (*sighandler_t) (int); // points to a function that returns type void 
// signal handlers are re-entrant
signal(int signo, sighandler_t handler) exit(EXIT_SUCCESS);
// declaring a variable of 
sighandler_t s; // s is a function pointer
// 
void my_int_handler(int signo){
    fprintf(stderr, "you pressed ^c\n");
}
// fprintf not safe
// in order to handle this safely you need to do 2 things
Don't touch global data
Only call functions that are re-entrant
