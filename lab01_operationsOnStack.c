#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int data)
{
    if (top >= MAX - 1)
    {
        printf("stack overflow!\n");
        return;
    }
    else
    {
        top++;
        stack[top] = data;
        printf("%d pushed successfully!\n", data);
    }
}

void pop()
{
    int data;

    if (top == -1)
    {
        printf("stack underflow!\n");
        return;
    }
    else
    {
        data = stack[top];
        top--;
        printf("%d popped successfully!\n", data);
    }
}

void print()
{
    int i;

    if (top >= 0) 
    {   for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    else 
    {
        printf("stack empty!\n");
    }

    return;
}

int main()
{
    while (1)
    {

        int choice, data;

        printf("\n--- operations on stack ---\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print\n");
        printf("4. exit\n");

        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nenter data to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            print();
            break;

        case 4:
            exit(0);

        default:
            printf("\ninvalid input!\n");
        }
    }

    return 0;
}