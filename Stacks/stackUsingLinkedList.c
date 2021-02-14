// Stack implementation using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode 
{
    int info;

    struct StackNode *link;
}StackNode;

void push(StackNode **topRef, int value)
{
    StackNode *in = (StackNode *)malloc(sizeof(StackNode));

    if(in == NULL)
    {
        printf("Stack Overflow ! \n");
        return;
    }

    in -> info = value;
    if(*topRef == NULL)
    {
        in -> link = NULL;

        *topRef = in;
    }
    else 
    {
        in -> link = *topRef;
        *topRef = in;
    }

    in = NULL;
    free(in);
}

void pop(StackNode **topRef)
{
    StackNode *temp;
    
    if(*topRef == NULL)
    {
        printf("Underflow ! \n");
    }
    else 
    {
        temp = *topRef;
        *topRef = (*topRef) -> link;
        temp -> link = NULL;

        free(temp);
    }
}

void display(StackNode *top)
{
    StackNode *curr;
    
    if(top == NULL)
    {
        printf("Stack Underflow ! \n");
    }
    else 
    {
        printf("TOP ");
        curr = top;

        while(curr != NULL)
        {
            printf(" -> %d ", curr -> info);
            curr = curr -> link;
        }
        printf("\n");
        
        curr = NULL;
        free(curr);
    }
}

int peek(StackNode *top)
{
    if(top == NULL)
    {
        printf("Stack Underflow ! \n");
    }
    else 
    {
        return top -> info;
    }

    return -1;
}

void main()
{
    StackNode *top = NULL;

    push(&top, 20);
    push(&top, 10);
    push(&top, 24);
    push(&top, 50);
    push(&top, 22);

    display(top);

    pop(&top);
    pop(&top);
    pop(&top);

    display(top);

    pop(&top);
    pop(&top);
    pop(&top);
}