// Power using recursion
#include <stdio.h>

int power(int base, int exp)
{
    if(exp == 0)
        return 1;
    else 
        return base * power(base, exp-1);
}

int main()
{
    int base, exp;
    printf("Enter base and exp: ");
    scanf("%d%d", &base, &exp);

    printf("Result: %d\n", power(base, exp));

    return 0;
}