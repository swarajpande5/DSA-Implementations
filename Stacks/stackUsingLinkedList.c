// Stack implementation using linked list
#include <stdio.h>
#include <stdlib.h>

struct StackNode 
{
    int info;

    struct StackNode *link;
};

void push(struct StackNode **topRef, int value)
{
    struct StackNode *in = (struct StackNode *)malloc(sizeof(struct StackNode));

    if(in == NULL)
    {
        printf("Stack Overflow ! \n");
        return;
    }

    if(*topRef == NULL)
    {
        in -> info = value;
        in -> link = NULL;

        *topRef = in;
    }
    else 
    {
        in -> info = value;
        in -> link = *topRef;
        *topRef = in;
    }
}

void pop(struct StackNode **topRef)
{
    struct StackNode *temp;
    
    if(*topRef == NULL)
    {
        printf("Underflow ! \n");
    }
    else 
    {
        temp = *topRef;
        *topRef = (*topRef) -> link;

        free(temp);
    }
}

void display(struct StackNode **topRef)
{
    struct StackNode *curr;
    
    if(*topRef == NULL)
    {
        printf("Stack Underflow ! \n");
    }
    else 
    {
        printf("TOP ");
        curr = *topRef;

        while(curr != NULL)
        {
            printf(" -> %d ", curr -> info);
            curr = curr -> link;
        }
        printf("\n");
    }
}

int peek(struct StackNode *top)
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
    struct StackNode *top = NULL;

    push(&top, 20);
    push(&top, 10);
    push(&top, 24);
    push(&top, 50);
    push(&top, 22);

    display(&top);

    pop(&top);
    pop(&top);
    pop(&top);

    display(&top);

    pop(&top);
    pop(&top);
    pop(&top);
}