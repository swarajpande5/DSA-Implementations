// Circular Linked list implementation
#include <stdio.h>
#include <stdlib.h>

// Circular linked list
// Node structure
struct Node 
{
    int info;

    struct Node *link;
};

struct Node *head = NULL;

// Function to Check whether the list is Empty or not
int isListEmpty()
{
    if(head == NULL)
        return 1;
    else 
        return 0;
}

//Function to Display the List
void printList()
{
    if(isListEmpty())
    {
        printf("Underflow !! \n");
        return;
    }
    
    struct Node *curr;
    curr = head;
    while(curr -> link != head)
    {
        printf("%d ->", curr -> info);
        curr = curr -> link;
    }
    printf("%d -> HEAD\n", curr -> info);

    curr = NULL;
    free(curr);
}

// Function to insert Node at beginning
void insertBegin()
{
    struct Node *in, *curr;
    in = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new Node info : ");
    scanf("%d", &in -> info);

    if(isListEmpty())
    {
        printf("Empty List ! This is the first Node. \n");
        
        head = in;
        in -> link = head;
    }
    else 
    {
        curr = head;
        while(curr -> link != head)
            curr = curr -> link;
        
        in -> link = head;
        curr -> link = in;
        head = in;
    }

    in = NULL;
    free(in);
}

// Function to insert Node at end
void insertEnd()
{
    struct Node *in, *curr;
    in = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new Node info : ");
    scanf("%d", &in -> info);

    if(isListEmpty())
    {
        printf("Empty List ! This is the first Node. \n");
        
        head = in;
        in -> link = head;
    }
    else 
    {
        curr = head;
        while(curr -> link != head)
        {
            curr = curr -> link;
        }
        curr -> link = in;
        in -> link = head;

    }

    in = curr = NULL;
    free(in);
    free(curr);

}

// Function to delete Node at beginning
void deleteBegin()
{
    struct Node *temp;
    
    if(isListEmpty())
    {
        printf("Underflow !! \n");
    }
    else if(head -> link == head) 
    {
        head = NULL;
        free(head);
    }
    else 
    {
        temp = head;
        while(temp -> link != head)
        {
            temp = temp -> link;
        }
        temp -> link = head -> link;
        
        free(head);

        head = temp -> link;
    }
}

//Function to delete Node at end
void deleteEnd()
{
    struct Node *temp, *prev;

    if(isListEmpty())
    {
        printf("Underflow !! \n");
    }
    else if(head -> link == head) 
    {
        head = NULL;
        free(head);
    }
    else 
    {
        temp = head;
        while(temp -> link != head)
        {
            prev = temp;
            temp = temp -> link;
        }
        prev -> link = temp -> link;

        free(temp);
    }
}

void main()
{
    insertBegin();
    printList();
    insertBegin();
    printList();
    insertEnd();
    printList();
    insertEnd();
    printList();

    deleteBegin();
    deleteBegin();
    deleteEnd();
    deleteEnd();

    deleteBegin();
    deleteEnd();
}