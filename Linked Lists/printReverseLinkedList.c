// Program to print reversed linked list (without changing)
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

void printReverse(Node *head)
{
    if(isListEmpty(head))
        return;
    
    printReverse(head -> link);

    printf("%d ", head -> info);
}

int main()
{
    Node *head = NULL;

    insertAtBegin(&head, 1);
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 3);
    insertAtBegin(&head, 4);

    printList(head);

    printReverse(head);
    printf("\n");

    deleteAtBegin(&head);
    deleteAtBegin(&head);
    deleteAtBegin(&head);
    deleteAtBegin(&head);
    deleteAtBegin(&head);

    return 0;
}