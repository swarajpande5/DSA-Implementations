// Recursive Solution to Tower of Hanoi Problem
#include <stdio.h>

void toh(int n, char from, char aux, char to)
{
    if(n == 1)
    {
        printf("Move 1 from %c to %c\n", from, to);
        return;
    }
    toh(n - 1, from, to, aux);
    
    printf("Move %d from %c to %c\n", n, from , to);

    toh(n - 1, aux, from, to);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    toh(n, 'A', 'B', 'C');
    return 0;
}