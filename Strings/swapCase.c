// Program to swap cases of alphbets in a string
#include <stdio.h>
#define MAX 255

void swapCase(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a' && str[i]<= 'z')
            str[i] -= 32;
        
        else if(str[i] >= 'A' && str[i]<= 'Z')
            str[i] += 32;
    }
}

int main()
{
    char str[MAX];
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);

    swapCase(str);
    printf("String after swapping cases: %s\n", str);
    
    return 0;
}