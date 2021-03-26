/*
The following C-code aims to print a string (the string input is already handled for you through "help5.h") first
and then its length in Decimal(Base 10). But there's some error in the code due to which desired output is not obtained.
Debug it and help us get the required output. Happy Debugging!!

For example: 
If input is "Hello World",
Output shpuld be:
Hello World
Length of the string: 11
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help5.h"
//Funtion to return the input string from "help5.h"
char ret()
{
    return input();            
}

int main()
{
    printf("\nLength of the string: %c \n",printf(ret()));
}