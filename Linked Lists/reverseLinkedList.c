// Program to reverse a linked list (changing the linked list)
#include <stdio.h>
#include <stdlib.h>

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
        printf("Empty List ! This is first Node. \n");

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

void deleteAtBegin(Node **headRef)
{
    if(isListEmpty(*headRef))
        printf("Underflow !\n");
    
    else 
    {
        Node *temp = *headRef;
        *headRef = temp -> link;
        temp -> link = NULL;
        free(temp);
    }
}

void reverseList(Node **headRef)
{
    Node *next, *prev, *curr;
    
    next = prev = NULL;
    curr = *headRef;

    while(curr != NULL)
    {
        next = curr -> link;
        curr -> link = prev;

        prev = curr;
        curr = next;
    }
    *headRef = prev;
}

int main()
{
    Node *head = NULL;

    insertAtBegin(&head, 1);
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 3);
    insertAtBegin(&head, 4);

    printList(head);

    reverseList(&head);
    printList(head);

    deleteAtBegin(&head);
    deleteAtBegin(&head);
    deleteAtBegin(&head);
    deleteAtBegin(&head);
    deleteAtBegin(&head);

    return 0;
}
