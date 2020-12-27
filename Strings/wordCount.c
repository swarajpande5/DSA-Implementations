// Program to count total number of words present in a string.
#include <stdio.h>
#define MAX 255

int wordCount(char str[])
{
    int spaceCount = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            spaceCount++;
    }
    return spaceCount+1;
}

int main()
{
    char str[MAX];
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);

    printf("Word Count: %d\n", wordCount(str));
    
    return 0;
}