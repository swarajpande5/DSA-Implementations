// Program to reverse a given strings
#include <stdio.h>
#include <string.h>
#define MAX 255

char* reverseString(char str[])
{
    static char rev[MAX];
    int i, length = strlen(str);

    for(i = 0; i < length; i++)
    {
        rev[i] = str[length - 1 - i];
    }
    rev[i] = '\0';

    return rev;
}
int main()
{
    char str[MAX];
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);

    printf("Reverse : %s\n", reverseString(str));
    return 0;
}