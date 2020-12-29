/* Array of Stacks
    Each element of this array is a Stack.
*/
#include <stdio.h>
#define SIZE 100

int stack[SIZE][SIZE];
int size;
int top[SIZE];

void init(int n)
{
    size = n;
    for(int i = 0; i < n; i++)
        top[i] = -1;
}

void push(int index, int value)
{
    if(top[index] == SIZE - 1)
        printf("Stack Overflow !\n");
    else
    {
        top[index]++;
        stack[index][top[index]] = value;
    }
}

void pop(int index)
{
    if(top[index] == -1)
        printf("Stack Underflow !\n");
    else
        top[index]--;
}

void printStackAtIndex(int index)
{
    int curr;
    curr = top[index];
    printf("TOP ->");
    while(curr > -1)
    {
        printf("%d ", stack[index][curr]);
        curr--;
    }
    printf("END\n");
}

void printArray(int size)
{
    int i, curr;
    for(i = 0 ; i < size; i++)
    {
        printf("Stack at index %d: \n", i);
        curr = top[i];
        printf("TOP ->");
        while(curr > -1)
        {
            printf("%d ", stack[i][curr]);
            curr--;
        }
        printf("END\n");
        //printStackAtIndex(i);
    }
}

int main()
{
    int arraySize, op, index, value, flag;
    printf("Enter array size: ");
    scanf("%d", &arraySize);

    init(arraySize);

    flag = 0;
    while(1)
    {
        printf("Enter option: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: printf("Enter Index and value: ");
                    scanf("%d%d", &index, &value);
                    push(index, value);
                    break;

            case 2: printf("Enter Index: ");
                    scanf("%d", &index);
                    pop(index);
                    break;

            case 3: printf("Enter Index: ");
                    scanf("%d", &index);
                    printStackAtIndex(index);
                    break;

            case 4: printArray(arraySize);
                    break;
                
            case 5: flag = 1;
        }
        if(flag)
            break;
    }

}