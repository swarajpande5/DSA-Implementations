// Program to sort linked list using Bubble Sort algorithm
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

void swap(Node *a, Node *b)
{
    int temp = a -> info;
    a -> info = b -> info;
    b -> info = temp;
}

void bubbleSortLL(Node *head)
{
    int swappedFlag;
    Node *curr, *lptr;
    
    lptr = NULL;

    if(head == NULL)
        return;
    
    do
    {
        swappedFlag = 0;
        curr = head;
        while(curr -> link != lptr)
        {
            if(curr -> info > curr -> link -> info)
            {
                swap(curr, curr -> link);
                swappedFlag = 1;
            }
            curr = curr -> link;
        }
        lptr = curr;
    }while(swappedFlag);
}

int main()
{
    Node *head = NULL;

    insertAtBegin(&head, 3);
    insertAtBegin(&head, 4);
    insertAtBegin(&head, 1);
    insertAtBegin(&head, 6);
    insertAtBegin(&head, 7);

    printList(head);

    bubbleSortLL(head);
    printList(head);

    return 0;
}