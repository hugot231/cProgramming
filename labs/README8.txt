Name: Hugo Trejo
Email: trejo231@csu.fullerton.edu
Assignment: Lab8

For this lab we were asked to read in options and arguments from the command line using getopt(). If the option was -v then we would print the command, argument, and its result. If the option was -d then we would allow debug commands from standard input. I used a while loop with getopt() to get all the options from the command line. I then went through a for loop up until the max argc to go through all the filenames passed from the command line. Using fscanf I was able to read in the characters from the file that I had opened using fopen(). I used plenty code from lab 4(initially lab 2 but it didnt play out like i wanted), to implement the linked list and run through the calculator commands. In order to keep track of which flag was used, I created a boolean variable. I managed to complete the task, but I'm sure I could have done something else with how I implemented the v flag using the boolean. 
