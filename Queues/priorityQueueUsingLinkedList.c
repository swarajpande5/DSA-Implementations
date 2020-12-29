// Priority queue implementation using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct PQNode
{
    int info;
    int priority;

    struct PQNode *link;
}PQNode;

PQNode *head = NULL;

void insert(int value, int rank)
{
    PQNode *curr = head;
    PQNode *in = (PQNode *)malloc(sizeof(PQNode));
    in -> link = NULL;

    if(in == NULL)
    {
        printf("Queue Overflow ! \n");
    }
    else
    {
        in -> info = value;
        in -> priority = rank;

        if(head == NULL)
        {
            head = in;
            head -> link = NULL;
        }
        else if(head -> priority > rank)
        {
            in -> link = head;
            head = in;
        }
        else
        {
            while(curr -> link != NULL && curr -> link -> priority < rank)
                curr = curr -> link;

            in -> link = curr -> link;
            curr -> link = in;
        }
    }
}

void delet()
{
    if(head == NULL)
    {
        printf("Queue Underflow ! \n");
    }
    else 
    {
        PQNode *temp = head;
        head = head -> link;
        free(temp);
    }
}


void printQueue()
{
    PQNode *curr;

    if(head == NULL)
    {
        printf("Queue Underflow ! \n");
        return;
    }
    else 
    {
        curr = head;

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
    insert(4, 1);
    insert(5, 3);
    insert(6, 2);
    insert(7, 0);
    insert(10, 4);

    printQueue();

    delet();
    delet();
    delet();
    printQueue();
    delet();
    delet();
    delet();

    return 0;
}