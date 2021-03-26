/*
Question 1: The following C-program intends to print the table of 2 (i.e. from 2*1's to 2*10's).
However, the following code has some issues in it, Catch the anomaly in the code to give the desired output output.

The following code implements increment/decrement operators and goto statement. 
Using any other logic would lead to disqualification.

*/

#include <stdio.h>
int main()
{
    int i = 0, j = 0;
    while (i < 10)
    {
    l1:
        i++;
    l2:
        while (j < 3)
        {
            printf("2 * %d = %d\n", i, i * 2); //Do not alter this line.
            goto l2;
        }
        goto l1;
    }
}

