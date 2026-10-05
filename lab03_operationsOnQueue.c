#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) 
{
    if (rear >= MAX - 1) 
    {
        printf("queue is full!\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("%d enqueued successfully!\n", data);
}

void dequeue() 
{
    int data; 
    if (front == -1 || front > rear) 
    {
        printf("queue is empty!");
        return;
    }
    data = queue[front];
    front++;
    printf("%d dequeued successfully!\n", data);
}

void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("queue is empty!\n");
    }
    else 
    {
        printf("queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int choice, data;

    while (1) 
    {
        printf("\n--- operations on queue ---\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. display\n");
        printf("4. exit\n");

        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("\nenter number to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2: 
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4: 
                exit(0);
            default:
                printf("invalid input!\n");
        }
    }

    return 0;
}