#include <stdio.h>
#include "stdlib.h"

typedef struct QueueNode
{
    int info;
    struct QueueNode *link;
}QueueNode;

QueueNode *front = NULL;
QueueNode *rear = NULL;

void insert(int value)
{
    QueueNode *in = (QueueNode *)malloc(sizeof(QueueNode));

    if(in == NULL)
    {
        printf("Queue Overflow ! \n");
        return;
    }
    else 
    {
        in -> info = value;

        if(front == NULL)
        {
            front = in;
            rear = in;
            in -> link = NULL;
        }
        else 
        {
            rear -> link = in;
            rear = in;
            rear -> link = NULL;
        }
    }
    in = NULL;
    free(in);
}

void delete()
{
    QueueNode *temp;

    if(front == NULL)
    {
        printf("Queue Underflow ! \n");
        return;
    }
    else 
    {
        temp = front;
        front = front -> link;
        temp -> link = NULL;

        free(temp);
    }
}

void printQueue()
{
    QueueNode *curr;

    if(front == NULL)
    {
        printf("Queue Underflow ! \n");
        return;
    }
    else 
    {
        curr = front;

        printf("FRONT ");
        while(curr != NULL)
        {
            printf("%d ", curr -> info);
            curr = curr -> link;
        }
        printf("REAR \n");
    }
    curr = NULL;
    free(curr);
}

int main()
{
    insert(4);
    insert(1);
    insert(3);
    insert(2);
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