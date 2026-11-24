#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("stack overflow!\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    printf("element %d has been pushed into stack\n", newNode->data);
    return;
}

void pop(void)
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("stack underflow!\n");
        return;
    }

    temp = top;
    top = top->next;

    printf("element %d has been popped from stack\n", temp->data);
    free(temp);
}

void display(struct Node *top)
{
    struct Node *temp = top;

    if (top == NULL)
    {
        printf("stack is empty!\n");
        return;
    }

    printf("stack elements (top to bottom):\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return;
}

int main(void)
{
    int choice, data;

    do
    {
        printf("--- stack operations ---\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. display stack\n");
        printf("4. exit\n");

        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("enter data: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                display(top);
                break;

            case 4:
                printf("exiting... \n");
                break;

            default:
                printf("invalid input!\n");
        }
    } while (choice != 4);

    return 0;
}
