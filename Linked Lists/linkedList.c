// Linked list implementation
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
    printf("Element Inserted at Beginning. \n");
}

void insertAtEnd(Node **headRef, int infoInput)
{
    Node *in, *curr;
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
        curr = *headRef;
        while(curr -> link != NULL)
        {
            curr = curr -> link;
        }
        curr -> link = in;
        in -> link = NULL;
    }

    in = curr = NULL;
    free(in);
    free(curr);
    printf("Element Inserted at End. \n");
}

void insertAfterValue(Node **headRef, int value)
{
    Node *in, *curr;
    in = (Node *)malloc(sizeof(Node));

    printf("Enter New Node Info : ");
    scanf("%d", &in -> info);

    if(*headRef ==  NULL)
    {
        printf("Empty List ! This is first Node. \n");
        *headRef = in;
        in -> link = NULL;
    }

    else 
    {
        curr = *headRef;
        while(curr -> link != NULL && curr -> info != value)
        {
            curr = curr -> link;
        }

        in -> link = curr -> link;
        curr -> link = in;
    }

    in = curr = NULL;
    free(in);
    free(curr);

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
        printf("Element Deleted at Beginning. \n");
    }
}

void deleteAtEnd(Node **headRef)
{
    if(isListEmpty(*headRef))
    {
        printf("Underflow ! \n");
        return; 
    }

    Node *temp, *prev;
    
    temp = *headRef;

    if(temp -> link == NULL)
    {
        *headRef = NULL;
        free(temp);
        return;
    }

    while(temp -> link != NULL)
    {
        prev = temp;
        temp = temp -> link;
    }

    prev -> link = temp -> link;
    temp -> link = NULL;
    free(temp);
    printf("Element Deleted at End. \n");

    prev = NULL;
    free(prev);
}

void deleteValue(Node **headRef, int value)
{
    if(isListEmpty(*headRef))
    {
        printf("Underflow ! \n");
        return; 
    }

    Node *temp, *prev;

    temp = *headRef;

    if(temp -> info == value)
    {
        *headRef = temp -> link;
        temp -> link = NULL;
        free(temp);
        return;
    }

    while(temp != NULL && temp -> info != value)
    {
        prev = temp;
        temp = temp -> link;
    }

    if(temp == NULL)
        printf("Value is not in the List. \n");
    
    else 
    {
        prev -> link = temp -> link;
        temp -> link = NULL;
        free(temp);
        printf("Element Deleted. \n");
    }

    prev = NULL;
    free(prev);

}


void main()
{
    Node *h1 = NULL;
    int input;

    int op = 1;

    while(op != 8)
    {
        printf("Enter Option (1-8) : ");
        scanf("%d", &op);

        switch(op)
        {
            case 1: // Insert a Node at beginning
                    printf("Enter New Node Info : ");
                    scanf("%d", &input);
                    insertAtBegin(&h1, input);
                    break;

            case 2: // Insert a Node at End
                    printf("Enter New Node Info : ");
                    scanf("%d", &input);
                    insertAtEnd(&h1, input);
                    break;

            case 3: // Insert Note after a Value
                    printf("Enter Value after which Node is to be inserted : ");
                    scanf("%d", &input);
                    insertAfterValue(&h1, input);
                    break;

            case 4: // Delete at Beginning 
                    deleteAtBegin(&h1);
                    break;

            case 5: // Delete at End
                    deleteAtEnd(&h1);
                    break;

            case 6: // Delete a Value
                    printf("Enter Value to be Deleted : ");
                    scanf("%d", &input);
                    deleteValue(&h1, input);
                    break;
            
            case 7: // Print List
                    printList(h1);
                    break;
        }
    }

    free(h1);
    
}