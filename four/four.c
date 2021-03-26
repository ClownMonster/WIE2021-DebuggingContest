/*
Question 4:
The following C-code aims to convert a number in Decimal number system(Base 10) to Binary number system(Base 2) 
using both recursive and iterative method. Input has been handled for you through "fourhelp.h".
For some reason the conversion is not working as desired. Help us out to resolve the issue. Happy Debugging!

For example: 10 in Decimal is equal to 1010 in binary.
10 / 2 = 5 ; 10 % 2 = 0 
5 / 2 = 2  ; 5 % 2 = 1  
2 / 2 = 1  ; 2 % 2 = 0  

Hint: Recursive method to implement conversion is working properly.
*/
#include <stdio.h>
#include <stdlib.h>
#include <lastlog.h>
#include <libio.h>
#include <stdc-predef.h>
#include <stropts.h>
#include <string.h>
#include <stdbool.h>
#include "fourhelp.h"

int binary_rec(int);
int binary(int);

int binary_rec(int num)
{
    if (num == 0)
        return 0;
    else
        return (num % 2 + 10 * binary_rec(num / 2));
}
/*******************************************************************/
//          DON NOT CHANGE ANYTHING ABOVE THIS LINE         //
int main()
{
    printf("Binary Equivalent (Iterative) of %d is %d\n", num_(), binary(num_()));
    printf("Binary Equivalent (Recursive) of %d is\n", num_(), binary_rec(num_()));

    return 0;
}

int binary(int num)
{
    int rem, bin = 0, place = 1;
    while (num)
    {
        rem = num % 2;
        num = num / 2;
        bin = bin + rem * place;
    }
    return (bin);
}