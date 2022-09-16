#include <stdio.h>
#include <stdlib.h>

int a[4];
int n = 4;
int top = -1;

void peep()
{
    int i;
    printf("Enter the index of the element you want to access\n");
    scanf("%d", &i);
    if (((top - i) + 1) <= 0)
    {
        printf("Stack index out of bounds\n");
        exit(0);
    }
    printf("%d", a[(top - i) + 1]);
}

void change(){
    int x,i;
    printf("Enter the index of the element you want to change\n");
    scanf("%d", &i);
    printf("Enter the value you want to add\n");
    scanf("%d", &x);
    if (((top - i) + 1) <= 0)
    {
        printf("Stack index out of bounds\n");
        exit(0);
    }
    a[(top - i) + 1] = x;
}

void pop()
{
    if (top < 0)
    {
        printf("Stack is empty");
        exit(0);
    }
    printf("%d\n", a[top]);
    top--;
}

int print()
{
    for (int i = 5; i >= 0; i--)
    {
        printf("%d\n", a[i]);
    }
}
int push()
{
    if (top > n)
    {
        printf("The stack is overflowed!\n");
        print();
        exit(0);
    }
    else
    {
        int value;
        printf("Enter the value you wanna push\n");
        scanf("%d", &value);
        top++;
        a[top] = value;
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n");
        printf("1: PUSH\n2: POP\n3:PEEP\n4:CHANGE\n5:print\n6:EXIT\n");
        printf("Enter Your choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            push();
            printf("Current top element is %d\n", top);
        }
        else if (choice == 2)
        {
            pop();
            printf("Current top element is %d\n", top);
        }
        else if (choice == 3)
        {
            peep();
            printf("Current top element is %d\n", top);
        }
        else if (choice == 4)
        {
            change();
            printf("Current top element is %d\n", top);
        }
        else if (choice == 5)
        {
            print();
        }
        else if (choice == 6)
        {
            return 0;
        }
    } while (choice != 6);
}