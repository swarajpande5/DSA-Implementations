// Program to check whether the string is palindrome or not
#include <stdio.h>
#define MAX 255

int isStringPalindrome(char str[])
{
    int length, flag;

    length = 0;
    flag = 1;

    for(int i = 0; str[i] != '\0'; i++)
        length++;
    
    for(int i = 0; i < length/2; i++)
    {
        if(str[i] != str[length - 1 - i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    char str[MAX];
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);

    if(isStringPalindrome(str))
        printf("Palindrome!\n");
    else 
        printf("Not Palindrome!\n");
    
    return 0;
}