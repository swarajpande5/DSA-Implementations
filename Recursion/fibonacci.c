// Fibonacci using recursion
#include <stdio.h>

int fib(int n)
{
    if(n <= 1)
        return n;
    else 
        return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("nth Fibonacci: %d\n", fib(n));

    return 0;
}