#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("queue is full!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("element %d enqueued\n", newNode->data);
    return;
}

void dequeue(void)
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("queue is empty!\n");
        return;
    }

    temp = front;
    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    printf("element %d dequeued\n", temp->data);
    free(temp);

    return;
}

void display(struct Node *front)
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("queue is empty!\n");
        return;
    }

    printf("queue elements (front to rear):\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return;
}

int main(void)
{
    int choice, data;

    do
    {
        printf("--- queue operations ---\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. display queue\n");
        printf("4. exit\n");

        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display(front);
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
