// Circular queue implementation using linked lists
#include <stdio.h>
#include <stdlib.h>

typedef struct CQueueNode
{
    int info;
    struct CQueueNode *link;
}CQueueNode;

CQueueNode *front = NULL;
CQueueNode *rear = NULL;

void insert(int value)
{
    CQueueNode *in;
    in = (CQueueNode *)malloc(sizeof(CQueueNode));

    if(in == NULL)
    {
        printf("Queue Overflow ! \n");
        return;
    }

    in -> info = value;
    in -> link = NULL;

    if(front == NULL && rear == NULL)
    {
        front = rear = in;
        rear -> link = front; 
    }
    else
    {
        rear -> link = in;
        rear = in;
        in -> link = front;
    }
}

void delet()
{
    CQueueNode *temp;
    temp = front;

    if(front == NULL && rear == NULL)
        printf("Queue Underflow ! \n");

    else if(front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front -> link;
        rear -> link = front;
        free(temp);
    }
}

void print()
{
    CQueueNode *curr;
    
    if(front == NULL && rear == NULL)
        printf("Queue Underflow ! \n");

    else 
    {
        printf("FRONT ");
        curr = front;
        do
        {
            printf("%d ", curr -> info);
            curr = curr -> link;
        }while(curr != front);
        printf("REAR \n");
    }
}

void main()
{
    insert(3);
    insert(2);
    insert(1);
    insert(5);
    insert(4);

    print();

    delet();
    delet();
    delet();

    print();

    delet();
    delet();
    delet();
}