// Reversing a number using recursion
#include <stdio.h>

int reverseNumber(int n)
{
    static int revNum = 0; 
    static int basePos = 1;

    if(n > 0)
    {
        reverseNumber(n / 10);
        revNum += (n%10)*basePos;
        basePos *= 10;
    }
    return revNum;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Reverse: %d\n", reverseNumber(n));

    return 0;
}