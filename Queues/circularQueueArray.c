// Circular queue implementation using array
#include <stdio.h>
#define SIZE 100

int cqueue[SIZE];
int front = -1, rear = -1;

void insert(int value)
{
    if((rear + 1)%SIZE == front)
    {
        printf("Queue Overflow ! \n");
        return;
    }

    else if(front == -1 && rear == -1)
        front = rear = 0;

    else if(rear == SIZE - 1 && front != 0)
        rear = 0;
    
    else 
        rear = (rear + 1)%SIZE;

    cqueue[rear] = value;
    
}

void delete()
{
    if(front == -1 && rear == -1)
        printf("Queue Underflow ! \n");

    else if(front == rear)
        front = rear = -1;

    else if(front == SIZE - 1)
        front = 0;

    else 
        front++;
}

void display()
{
    int i;

    if(front == -1)
        printf("Queue Underflow ! \n");

    else 
    {
        printf("Queue Elements are: \n");
        printf("FRONT ");
        i = front;
        if(front <= rear)
        {
            while(i <= rear)
            {
                printf("%d ", cqueue[i]);
                i++;
            }
        }
        else 
        {
            while(i <= SIZE - 1)
            {
                printf("%d ", cqueue[i]);
                i++;
            }

            i = 0;
            while(i <= rear)
            {
                printf("%d", cqueue[i]);
                i++;
            }
        }
        printf("REAR \n");
    }
}

void main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    display();

    delete();
    delete();
    delete();

    display();

    delete();
    delete();
    delete();
}