// Program to detect if there is any cycle in the linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int info;
    struct Node *link;
}Node;

int isListEmpty(Node *headRef)
{
    if(headRef == NULL)
        return 1;
    else 
        return 0;
}

void printList(Node *headRef)
{
    if(isListEmpty(headRef))
    {
        printf("Underflow !\n");
        return;
    } 

    Node *curr;
    curr = headRef;
    while(curr != NULL)
    {
        printf("%d ->", curr -> info);
        curr = curr -> link;
    }
    printf("NULL\n");
}

void insertAtBegin(Node **headRef, int infoInput)
{
    Node *in;
    in = (Node *)malloc(sizeof(Node));

    in -> info = infoInput;

    if(*headRef == NULL)
    {
        *headRef = in;
        in -> link = NULL;
    }

    else 
    {
        in -> link = *headRef;
        *headRef = in;
    }

    in = NULL;
    free(in);
}

bool cycleDetection(Node *head)
{
    Node *p, *q;
    p = q = head;

    while(1)
    {
        if(p -> link == NULL)
            return false;
        else 
            p = p -> link;
        
        if(q -> link == NULL)
            return false;
        
        else
        {
            if(q -> link -> link == NULL)
                return false;
            else 
                q = q -> link -> link;
        }

        if(p == q)
            return true;
    }
}

int main()
{
    Node *head = NULL;
    insertAtBegin(&head, 4);
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 3);
    insertAtBegin(&head, 1);

    // Creating a loop in this linked list
    head -> link -> link -> link -> link = head;

    if(cycleDetection(head))
        printf("Loop Found!\n");
    else 
        printf("No loop found!\n");

    return 0;
}