
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int circularQueue[MAX];
int front = -1;
int rear = -1;

void enqueue(int element);
void dequeue(void);
void display(void);

int main(void)
{
    int choice, element;

    printf("--- Operations on Circular Queue ---\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter element to enqueue: ");

                if (scanf("%d", &element) != 1)
                {
                    printf("Invalid input!\n");
                    return 1;
                }

                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid input!\n");
        }
    }

    return 0;
}

void enqueue(int element)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    circularQueue[rear] = element;

    printf("%d enqueued successfully!\n", element);
}

void dequeue(void)
{
    int element;

    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    element = circularQueue[front];
    printf("%d dequeued successfully!\n", element);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display(void)
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");

    i = front;

    while (1)
    {
        printf("%d ", circularQueue[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}
