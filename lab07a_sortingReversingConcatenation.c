#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* creatList()
{
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    int n, i;

    printf("enter the number of nodes: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("memory allocation failed!\n");
            return head;
        }

        printf("enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

void sortList(struct Node *head)
{
    struct Node *temp, *curr;
    int swap;

    if (head == NULL)
    {
        printf("list is empty!\n");
        return;
    }

    for (temp = head; temp != NULL; temp = temp->next)
    {
        for (curr = temp->next; curr != NULL; curr = curr->next)
        {
            if (temp->data > curr->data)
            {
                swap = temp->data;
                temp->data = curr->data;
                curr->data = swap;
            }
        }
    }
}

void reverseList(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;

    return;
}

void concatenateList(struct Node *head1, struct Node *head2)
{
    struct Node *temp = head1;

    if (head1 == NULL)
    {
        printf("list is empty!\n");
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
    }

    return;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("list is empty!\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void)
{
    struct Node *head = NULL;
    struct Node *head2 = NULL;
    int choice;

    do
    {
        printf("--- linked list operations ---\n");
        printf("1. create list\n");
        printf("2. sort list\n");
        printf("3. reverse list\n");
        printf("4. concatenate with another list\n");
        printf("5. display list\n");
        printf("6. exit\n");

        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = creatList();
                break;

            case 2:
                sortList(head);
                printf("sorted list: ");
                display(head);
                break;

            case 3:
                reverseList(&head);
                printf("reversed list: ");
                display(head);
                break;

            case 4:
                printf("create the second list:\n");
                head2 = creatList();
                concatenateList(head, head2);
                printf("concatenated list: ");
                display(head);
                break;

            case 5:
                printf("current list: ");
                display(head);
                break;

            case 6:
                printf("exiting... \n");
                break;

            default:
                printf("invalid input!\n");
        }
    } while (choice != 6);

    return 0;
}
