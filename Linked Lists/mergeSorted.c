// Program to inplace merge 2 sorted linked lists
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

void insertAtEnd(Node **headRef, int infoInput)
{
    Node *in, *curr;
    in = (Node *)malloc(sizeof(Node));

    in -> info = infoInput;

    if(*headRef == NULL)
    {
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
}

Node* merge(Node *h1, Node *h2)
{
    Node *currH1, *currH2, *res;
    
    res = NULL;
    currH1 = h1;
    currH2 = h2;

    while(currH1 != NULL && currH2 != NULL)
    {
        if(currH1 -> info < currH2 -> info)
        {
            insertAtEnd(&res, currH1 -> info);
            currH1 = currH1 -> link;
        }
        else 
        {
            insertAtEnd(&res, currH2 -> info);
            currH2 = currH2 -> link;
        }
    }
    
    while(currH1 != NULL)
    {
        insertAtEnd(&res, currH1 -> info);
        currH1 = currH1 -> link;
    }

    while(currH2 != NULL)
    {
        insertAtEnd(&res, currH2 -> info);
        currH2 = currH2 -> link;
    }

    return res;
}

int main()
{
    Node *h1, *h2, *res;

    h1 = h2 = res = NULL;

    insertAtEnd(&h1, 1);
    insertAtEnd(&h1, 3);
    insertAtEnd(&h1, 5);
    insertAtEnd(&h1, 7);
    insertAtEnd(&h1, 9);

    printList(h1);

    insertAtEnd(&h2, 2);
    insertAtEnd(&h2, 4);
    insertAtEnd(&h2, 6);
    insertAtEnd(&h2, 8);

    printList(h2);

    res = merge(h1, h2);

    printList(res);

    return 0;
}