// Program to calculate length of a String
#include <stdio.h>
#define MAX 255

int stringLength(char str[])
{
    int l = 0;
    for(int i = 0; str[i] != '\0'; i++)
        l++;
    
    return l;
}

int main()
{
    char str[MAX];
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);

    printf("Length : %d\n", stringLength(str));
    return 0;
}