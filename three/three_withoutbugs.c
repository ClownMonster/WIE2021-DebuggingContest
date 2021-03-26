/*
The following C-program intends to create a linked list of Armstrong Numbers between 1 to 500 in ascending order and print it.
Therafter, the created linked list of Armstrong numbers in ascending should be then reversed to make its order Descending and print it too.
The reversing of the linked list  is implemented using recursive funtion 'reverseUtil'.

An Armstrong number is a n digit number such that the sum of its digits raised to the nth power is equal to the number itself.

For example, 
Let's take a number: 153, which is 3 digit number, 
here 1^3 + 5^3 + 3^3 is 1 + 125 + 27 which is equal to 153, therefore 153 is an Armstrong Number.

Let's take another number: 7, which is 1 digit number, 
here 7^1 is 7 which is equal to 7, therefore 7 is also an Armstrong Number.

HINT : There are 13 Armstrong numbers between 1 to 500.

For co-ordinators use:
CORRECT OUTPUT IS:
The Armstrong numbers in between 1 to 500 are (Ascending Order) :
1       2       3       4       5       6       7       8       9       153     370     371     407
The Armstrong numbers in between 1 to 500 are (Descending Order) :
407     371     370     153     9       8       7       6       5       4       3       2       1

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definition of the linked list
typedef struct armNum
{
    int data;
    struct armNum *next;
} armNum;
armNum *start;

armNum *create(int data, armNum *n);
void create_LL(int data);
void armNum_check(int i);
void reverse(armNum **head);
void reverseUtil(armNum *curr, armNum *prev, armNum **head);
void print_arnNum(armNum *head);

//A function to check whether number i is a Armstrong Number or not
void armNum_check(int i)
{
    int n, sum, t, a, count, num;
    count = 0;
    t = i;
    num = i;
    while (num != 0)
    {
        num /= 10;
        ++count;
    }
    sum = 0;
    while (t != 0)
    {
        a = t % 10;
        sum += pow(a, count);
        t = t / 10;
    }
    if (sum == i)
        create_LL(i);
}

// A utility function to create a new node in the linked list
armNum *create(int data, armNum *n)
{
    armNum *ptr = (armNum *)malloc(sizeof(armNum));
    ptr->data = data;
    ptr->next = n;
    return ptr;
}
// This function mainly calls reverseUtil() with prev as NULL
void reverse(armNum **head)
{
    if (!*head)
        exit(1);
    reverseUtil(*head, NULL, head);
}

/************************************************************************************************/
/*                      DO NOT CHANGE ANYTHING ABOVE THIS LINE                                  */
/*                  DO NOT  CHANGE THE PRINT STATEMENTS IN THE CODE                             */
/************************************************************************************************/

//A utility funtion of add new nodes at the end of the linked list
void create_LL(int data)
{
    /*
    if (start == NULL)
        start = create(data, NULL);
    else
    {
    not present in buggy code
    */

    if (start == NULL)
        start = create(data, NULL);
    else
    {
    armNum *np = start;
    while (np->next != NULL) //np!=NULL in buggy code
        np = np->next;
    np->next = create(data, NULL);
    }
}

// A simple and tail-recursive function to reverse a linked list.  prev is passed as NULL initially.
void reverseUtil(armNum *curr, armNum *prev, armNum **head)
{

    if (!curr->next) // If last armNum mark it head
    {
        *head = curr;
        curr->next = prev; //Update next to prev armNum
        return;
    }

    armNum *next = curr->next; // Save curr->next armNum for recursive call

    curr->next = prev; // and update next ..
    //reverseUtil(head, curr, next) in buggy code
    reverseUtil(next, curr, head);
}

//Utility funtion to print the linked list given head of the list as argument
void print_arnNum(armNum *head)
{
    if (head == NULL)
        return;
    armNum *ptr = head;
    while (ptr != NULL)       //  ptr->next != NULL in buggy code
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//Driver funtion
int main()
{
    //if start = NULL is added, consider to be correct, has no effect to correctness of program
    for (int i = 1; i <= 500; i++)
        armNum_check(i);
    printf("The Armstrong numbers in between 1 to 500 are (Ascending Order) :\n");
    print_arnNum(start);
    reverse(&start);                     // start in buggy code
    printf("The Armstrong numbers in between 1 to 500 are (Descending Order) :\n");
    print_arnNum(start);
    return 0;
}