// Segmentation fault (core dumbed)
gcc -g -Og -std=c11 -Wall -Wextra -Wpedantic Lab5.c -o lab5.out

$ulimit -a // "shows all flags and descriptions	
 (segmentation fault core dumped) 
// Chromebook-specific
echo core | sudo tee /proc/sys/kewhat irnel/core_pattern
$./a.out "inputs if needed" // enter your executable
// if you get a.out
// run
"user limit"
$ ulimit -c unlimited
// you should get a.out core 
(assuming gcc -g) was used
$ gdb ./a.out core // enter your executablesugbak

// ************** using GDB
file lab.out // specifies which executable you want to debug
run // specifies to run the debugger
break #
/*A ``breakpoint'' is a spot in your program where you would like to temporarily stop execution in order to check the values of variables, or to try to find out where the program is crashing, etc. To set a breakpoint you use the break command.
break function sets the breakpoint at the beginning of function. If your code is in multiple files, you might need to specify filename:function.

break linenumber or break filename:linenumber sets the breakpoint to the given line number in the source file. Execution will stop before that line has been executed.*/


// Valgrind
// -checks for memory leaks

int main(void)

int main( int argc, char *argv[]) // count, vector
// in main include the top two
// the shell separates on spaces
// running
$ ./a.out
argv[0] = "./a.out"

// running
$./a.out foo
argc = 2
argv[0] = "./a.out"
argv[1] = "foo"
