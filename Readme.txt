Author: Shiladitya Mandal - 2010C6PS632G

Directory: /Question1

Files:
header.h			- header file for program
driver.c			- driver file( main program) - program starts executing here
implementation.c	- implementation. it contains function to execute the commands in the 2 arrays
execute_single.c	- given a single command in character array format it executes it

HOW TO COMPILE:
make (assume superuser access)

HOW TO RUN:
./exe <filename>

DESCRIPTION OF STRUCTURE:
1. int main() takes in command line argument(file name). It stores the commands in 2 2 dimensional character arrays(command, environment and options) based on the restrictions given
2. executecmds(char **a,char **b,int len1,int len2) is then called with the two 2 dimensinal character arrays and their length as input. This function extracts each command and then sends them for execution to another function.
3. execute_single(char **a,int pos) - this is called by the above function giving the 2dimensional array and a position which is to be executed next. This function decodes each command string into its required components - command, environment, and options. Finally this calls the execv function with the requried arguments. 

ASSIGNMENT STATUS:
Complete

BUGS: 
1. Might not work properly if superuser access not given. 
2. There might be a case where 2 processes executing two execv commands, might produce interleaved output. This rarely happens but I have seen it happen once or twice. This maybe solved by giving some amount of sleep after a command is brought for execution so that the other process can execute without any interruption.

