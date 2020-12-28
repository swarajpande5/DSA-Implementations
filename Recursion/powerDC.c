// Calculating Power using Recursion (Divide and Conquer)
#include <stdio.h>

int power(int base, int exp)
{
    if(exp == 0)
        return 1;
    
    else if(exp % 2 == 0)
        return power(base, exp/2) * power(base, exp/2);
    
    else 
        return base * power(base, exp/2) * power(base, exp / 2);
}

int main()
{
    int base, exp;
    printf("Enter base and exp: ");
    scanf("%d%d", &base, &exp);

    printf("Result: %d\n", power(base, exp));

    return 0;
}