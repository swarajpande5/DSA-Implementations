// Factorial using recursion
#include <stdio.h>

int factorial(int n)
{
    if(n <= 1)
        return 1;
    
    else 
        return n * factorial(n-1);
}

int main()
{
    int n;
    
    printf("Enter number: ");
    scanf("%d", &n);
    printf("The factorial is: %d\n", factorial(n));

    return 0;
}