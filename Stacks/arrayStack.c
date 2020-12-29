// Stack implementation using array
#include <stdio.h>
#define SIZE 100

int top = -1;
int stack[SIZE];

void push(int value)
{
    if(top == SIZE -1)
        printf("Stack Overflow !! \n");
    
    else 
    {
        top++;
        stack[top] = value;
    }
}
void pop()
{
    if(top == -1)
        printf("Stack Underflow !! \n");
    
    else 
        top--;  
}

void printStack()
{
    int curr = top;
    printf("TOP ->");
    while(curr > -1)
    {
        printf("%d ", stack[curr]);
        curr--;
    }
    printf("\n");
}

int peep()
{
    return stack[top];
}

void main()
{
    push(5);
    push(2);
    push(1);
    push(9);

    printStack();

    pop();
    pop();

    printStack();

    pop();
    pop();
    pop();
}