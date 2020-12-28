// Circular doubly linked list implementation
#include <stdio.h>
#include <stdlib.h>

// Circular Doubly Linked List
// Node structure
struct Node 
{
    int info;

    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Function to check whether the given list is Empty
int isListEmpty()
{
    if(head == NULL)
        return 1;
    else 
        return 0;
}

void printList()
{
    if(isListEmpty())
    {
        printf("Underflow !! \n");
        return;
    }
    
    struct Node *curr = head;
    while(curr -> next != head)
    {
        printf("%d -> ", curr -> info);
        curr = curr -> next;
    }
    printf("%d -> HEAD \n", curr->info);

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
        head = in;
        in -> next = head;
        in -> prev = head;
    }
    else 
    {
        curr = head;
        while(curr -> next != head)
        {
            curr = curr -> next;
        }
        curr -> next = in;
        in -> prev = curr;
        head -> prev = in;
        in -> next = head;

        head = in;
    }

    in = curr = NULL;
    free(in);
    free(curr);
}

//Function to insert Node at End
void insertEnd()
{
    struct Node *in, *curr;
    in = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new Node info : ");
    scanf("%d", &in -> info);

    if(isListEmpty())
    {
        head = in;
        in -> next = head;
        in -> prev = head;
    }
    else 
    {
        curr = head;
        while(curr -> next != head)
        {
            curr = curr -> next;
        }
        curr -> next = in;
        in -> prev = curr;
        head -> prev = in;
        in -> next = head;
    }

    in = curr = NULL;
    free(in);
    free(curr);
}

// Function to delete Node at Begin
void deleteBegin()
{
    struct Node *temp;
    if(isListEmpty())
        printf("Underflow !! \n");
    
    else if(head -> next == head)
    {
        head = NULL;
        free(head);
    }

    else 
    {
        temp = head;
        while(temp -> next != head)
        {
            temp = temp -> next;
        }
        temp -> next = head -> next;
        head -> next -> prev = temp;

        free(head);
        head = temp -> next;
    }

    temp = NULL;
    free(temp);
}

// Function to delete Node at End
void deleteEnd()
{
    struct Node *temp;
    if(isListEmpty())
        printf("Underflow !! \n");
    
    else if(head -> next == head)
    {
        head = NULL;
        free(head);
    }

    else 
    {
        temp = head;
        if(temp -> next != head)
        {
            temp = temp -> next;
        }
        temp -> prev -> next = head;
        head -> prev = temp -> prev;

        free(temp);
    }
}

