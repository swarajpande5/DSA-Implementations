// Double linked list implementation
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;

    struct Node *next;
    struct Node *prev;
};

struct Node *head =  NULL;

//Function to check whether the list is empty or not
int isListEmpty()
{
    if(head == NULL)
        return 1;
    else 
        return 0;
}

// Function for printing Doubly Linked List
void printList()
{
    if(isListEmpty())
    {
        printf("Underflow !! \n");
        return;
    }
    
    struct Node *curr = head;
    while(curr != NULL)
    {
        printf("%d -> ", curr -> info);
        curr = curr -> next;
    }
    printf("NULL \n");

    curr = NULL;
    free(curr);
}

// Function to insert Node at Beginning
void insertBegin()
{
    struct Node *in;
    in = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new Node info : ");
    scanf("%d", &in -> info);
    
    if(isListEmpty())
    {
        in -> next = NULL;
        in -> prev = NULL;

        head = in;
    }

    else 
    {
        head -> prev = in;
        in -> next = head;
        in -> prev = NULL;
        head = in;
    }

    in = NULL;
    free(in);   
}


// Function to insert Node at End
void insertEnd()
{
    struct Node *in, *curr;
    in = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new Node info : ");
    scanf("%d", &in -> info);

    if(isListEmpty())
    {
        in -> next = NULL;
        in -> prev = NULL;
        
        head = in;
    }
    else
    {
        curr = head;
        while(curr -> next != NULL)
            curr = curr -> next;

        curr -> next = in;
        in -> prev = curr;
        in -> next = NULL;

    }
    
    in = curr = NULL;
    free(in);
    free(curr);
}

//Function to insert before a value
void insertBefore()
{
    struct Node *in, *curr;
    int val;

    in = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new Node info : ");
    scanf("%d", &in -> info);

    printf("Enter the value before which the info is to be inserted : ");
    scanf("%d", &val);

    if(isListEmpty())
    {
        in -> next = NULL;
        in -> prev = NULL;

        head = in;
        return;
    }

    curr = head;
    while(curr -> next != NULL && curr -> info != val)
    {
        curr = curr -> next;
    }
    in -> next = curr;
    in -> prev = curr -> prev;
    curr -> prev -> next = in;
    curr -> prev = in;

    in = curr = NULL;
    free(in);
    free(curr);
}

//Function to insert after a value
void insertAfter()
{
    struct Node *in, *curr;
    int value;

    in = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new Node info : ");
    scanf("%d", &in -> info);

    printf("Enter the value after which the info is to be inserted : ");
    scanf("%d", &value);

    if(isListEmpty())
    {
        in -> next = NULL;
        in -> prev = NULL;

        head = in;
        return;
    }

    curr = head;
    while(curr -> next != NULL && curr -> info != value)
    {
        curr = curr -> next;
    }
    in -> prev = curr;
    in -> next = curr -> next;
    curr -> next -> prev = in;
    curr -> next = in;

    in = curr = NULL;
    free(in);
    free(curr);
}


// Function to Delete Node at Beginning
void deleteBegin()
{
    if(isListEmpty())
    {
        printf("Underflow !! \n");
        return;
    }

    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);

        return;
    }

    struct Node *temp = head;
    head = head -> next;
    head -> prev = NULL;

    free(temp);
}

//Function to Delete Node at End
void deleteEnd()
{
    if(isListEmpty())
    {
        printf("Underflow !! \n");
        return;
    }

    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        return;
    }

    struct Node *temp = head;
    while(temp -> next != NULL)
        temp = temp -> next;
    
    temp -> prev -> next = NULL;

    free(temp);
}

// Function to Delete any value
void deleteValue()
{
    if(isListEmpty())
    {
        printf("Underflow !! \n");
        return;
    }

    int value; 
    printf("Enter the value to be deleted : ");
    scanf("%d", &value);

    if(head -> info == value)
    {
        deleteBegin();
    }

    struct Node *temp = head;
    while(temp != NULL && temp -> info != value)
    {
        temp = temp -> next;
    }
    if(temp == NULL)
    {
        printf("The value is not in List. \n");
    }
    else 
    {
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;

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
    insertBefore();
    printList();
    insertAfter();
    printList();

    deleteValue();
    printList();
    deleteBegin();
    deleteBegin();
    deleteEnd();
    deleteValue();
    printList();
    deleteEnd();
    deleteBegin();
    deleteEnd();
    deleteBegin();

}