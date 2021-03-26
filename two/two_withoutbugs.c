/*
The code below aims to print an entire string whose input is alread handled for you.
But the code has some error(s) in it which is not giving the proper output. Debug the given code to get the required output.

The following code implements pointers,increment/decrement operators and goto statement. 
Using any other logic would lead to disqualification.


HINT: The string starts with ASCII equivalent of 87 and ends with the letters "BEST"

*/

#include "helpers.h"
int main()
{
    char *p;
    p = inputString();
    int m = inputStringlength(p);
/*******************************************************************/
    //DO NOT CHANGE ANYTHING ABOVE THIS LINE//
    //INPUT IS HANDLED FOR YOU IN THE ABOVE LINES//
    int i = 0;
label:
    i++;
    printf("%c", *p++);      //++*p in buggy code           
    do
    {
        if (i > m)          //Condition inside if statement is (m > i) in buggy code
        {
            printf("\n");
            break;          // No break statement in buggy code
        }
        else
            goto label;
    } while (1);
    
    return 0;
}