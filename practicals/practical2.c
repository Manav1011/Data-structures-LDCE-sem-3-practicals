// Implement a program for stack that performs following operations using array. display
// (a) PUSH (b) POP (c) PEEP (d) CHANGE (e) DISPLAY

#include <stdio.h>
#include <stdlib.h>

int a[4];
int n = 4;
int top = -1;

int peep(int index)
{    
    if (((top - index) + 1) <= 0)
    {
        printf("Stack index out of bounds\n");
        return 1;
    }
    return a[(top - index) + 1];
}

int change(int i,int x){    
    if (((top - i) + 1) <= 0)
    {
        printf("Stack index out of bounds\n");
        return 1;
    }
    a[(top - i) + 1] = x;
    return a[(top - i) + 1];
}

int pop()
{
    if (top < 0)
    {
        printf("Stack is empty");
        return 1;
    }
    top --;
    return a[top+1];
}

int display()
{
    printf("Stack is ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d  ", a[i]);
    }
}
int push(int val)
{
    if (top > n)
    {
        printf("The stack is overflowed!\n");        
        return 1;
    }
    else
    {
        top++;
        a[top] = val;
        return val;
    }
}

int main()
{
    printf("The value you pushed is %d\n",push(1));
    printf("The value you pushed is %d\n",push(2));
    printf("The value you pushed is %d\n",push(3));
    printf("The element you popped is %d\n",pop());
    printf("Peeped element is %d\n",peep(1));
    printf("The value you have added is %d\n",change(1,5));
    display(); 
}