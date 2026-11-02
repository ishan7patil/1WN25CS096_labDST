#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertBeginning(struct Node **head, int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node **head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertMiddle(struct Node **head, int value, int position)
{
    struct Node *newNode, *temp;
    int i;

    if(position < 1)
    {
        printf("invalid position!\n");
        return;
    }

    // Position 1 means beginning
    if(position == 1)
    {
        insertBeginning(head, value);
        return;
    }

    temp = *head;

    for(i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void createList(struct Node **head)
{
    int n, i, value;

    printf("enter the number of nodes: ");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("invalid number of nodes!\n");
        return;
    }

    for(i = 0; i < n; i++)
    {
        printf("enter data: ");
        scanf("%d", &value);

        insertEnd(head, value);
    }
}

void display(struct Node *head)
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("linked list is empty!\n");
        return;
    }

    temp = head;

    printf("linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;

    int choice, value, position;

    printf("\n--- operations on singly linked list ---\n");
    printf("1. create linked list\n");
    printf("2. insert at beginning\n");
    printf("3. insert at end\n");
    printf("4. insert at position\n");
    printf("5. display linked list\n");
    printf("6. exit\n");


    while(1)
    {
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createList(&head);
                break;

            case 2:
                printf("enter the value: ");
                scanf("%d", &value);

                insertBeginning(&head, value);
                break;

            case 3:
                printf("enter the value: ");
                scanf("%d", &value);

                insertEnd(&head, value);
                break;

            case 4:
                printf("enter the position: ");
                scanf("%d", &position);

                printf("enter the value: ");
                scanf("%d", &value);

                insertMiddle(&head, value, position);
                break;

            case 5:
                display(head);
                break;

            case 6:
                exit(0);

            default:
                printf("invalid choice!\n");
        }
    }

    return 0;
}
