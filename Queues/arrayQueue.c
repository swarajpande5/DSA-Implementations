// Queue Implementation using Array
#include <stdio.h>

#define SIZE 1000

int front = -1;
int rear = -1;
int queue[SIZE];

void insert(int value)
{
    if(rear == SIZE - 1)
    {
        printf("Queue Overflow ! \n");
        return;
    }

    if(front == -1 && rear == -1)
        front = rear = 0;

    else 
        rear++;

    queue[rear] = value;
}

void delete()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow ! \n");
        return;
    }

    if(front == rear)
        front = rear = -1;
    
    else 
        front++;
}

int peekFront()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow ! \n");
        return -1;
    }
    return queue[front];
}

void printQueue()
{
    if(rear == -1)
        printf("Queue Underflow !\n");

    else 
    {
        printf("FRONT ");
        for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("REAR \n");
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    printQueue();

    delete();
    delete();
    delete();
    printQueue();

    delete();
    delete();
    delete();

    return 0;
}