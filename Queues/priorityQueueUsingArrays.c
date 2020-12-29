// Priority queue implementation using arrays
#include <stdio.h>
#include <stdbool.h>
#define MAX 255

int pQueue[MAX];
int itemCount = 0;

bool isEmpty()
{
    return itemCount == 0;
}

bool isFull()
{
    return itemCount == MAX;
}

int peek()
{
    return pQueue[itemCount - 1];
}

void insert(int value)
{
    int i = 0;

    if(!isFull())
    {
        if(itemCount == 0)
        {
            pQueue[itemCount] = value;
            itemCount++;
        }

        else 
        {
            for(i = itemCount - 1; i >= 0; i--)
            {
                if(value > pQueue[i])
                    pQueue[i+1] = pQueue[i];
                
                else 
                    break;
            }
        }
        pQueue[i+1] = value;
        itemCount++;
    }
}

int delete()
{
    return pQueue[--itemCount];
}

int main()
{
    insert(3);
    insert(5);
    insert(9);
    insert(1);
    insert(12);

    printf("Index:\t5\t4\t3\t2\t1\t0\n");
    printf("Queue:");
	
    while(!isEmpty()){
        int n = delete();           
        printf("\t%d", n);
    }   
    printf("\n");

    return 0;
}