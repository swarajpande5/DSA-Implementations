// Stack of Arrays
/*
    Each element in this stack is an array.
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct StackNode 
{
    int size, arr[SIZE];
}StackNode;

int top = -1;
StackNode stack[SIZE];

void push()
{
    if(top == SIZE -1)
        printf("Stack Overflow !! \n");

    else
    {
        top++;
        printf("Enter Size: ");
        scanf("%d", &stack[top].size);

        printf("Enter Array elements: ");
        for(int i = 0; i < stack[top].size; i++)
            scanf("%d", &stack[top].arr[i]);
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow !! \n");
    
    else 
    {
        top--;
    }  
}

void printStack()
{
    int curr = top;
    printf("TOP\n");
    while(curr > -1)
    {
        for(int i = 0; i < stack[curr].size; i++)
            printf("%d ", stack[curr].arr[i]);

        printf("\n");
        curr--;
    }
}

int main()
{

    int op, flag = 0;
    while(1)
    {
        printf("Enter option: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: printStack();
                    break;
            case 4: flag = 1;
        }
        if(flag == 1)
            break;
    }
    return 0;
}