#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertEnd(struct Node ** head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("memory allocation failed!\n");
        return;
    }

    newNode -> data = value;
    newNode -> next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newNode;
}

void deleteBeginning(struct Node **head)
{
    struct Node *temp;

    if(*head == NULL)
    {
        printf("linked list is empty!\n");
        return;
    }

    temp = *head;
    *head = temp->next;

    free(temp);

    printf("first node deleted successfully!\n");
}

void deleteMiddle(struct Node **head, int value)
{
    struct Node *temp, *prev;

    if(*head == NULL)
    {
        printf("linked list is empty!\n");
        return;
    }

    temp = *head;

    if(temp->data == value)
    {
        *head = temp->next;
        free(temp);

        printf("element deleted successfully!\n");
        return;
    }

    prev = NULL;

    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("element not found!\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("element deleted successfully!\n");
}

void deleteEnd(struct Node **head)
{
    struct Node *temp, *prev;

    if(*head == NULL)
    {
        printf("linked list is empty!\n");
        return;
    }

    temp = *head;

    if(temp->next == NULL)
    {
        *head = NULL;
        free(temp);

        printf("last node deleted successfully!\n");
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    printf("last node deleted successfully!\n");
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
    return;
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

    printf("linked list: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    int choice, value, position;

        printf("\n--- operations on singly linked list ---\n");

        printf("1. create linked list\n");
        printf("2. delete first element\n");
        printf("3. delete specified element\n");
        printf("4. delete last element\n");
        printf("5. display linked list\n");
        printf("6. exit\n");

    while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createList(&head);
                break;

            case 2:
                deleteBeginning(&head);
                break;

            case 3:
                printf("enter the element to delete: ");
                scanf("%d", &value);

                deleteMiddle(&head, value);
                break;

            case 4:
                deleteEnd(&head);
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
