// Program to sort strings in Dictionary Order
#include <stdio.h>
#include <string.h>
#define MAX 255

int main()
{
    int size;
    char str[MAX][MAX], temp[25];

    printf("Enter number of strings: ");
    scanf("%d", &size);

    printf("Enter the strings: \n");
    for(int i = 0; i < size; i++)
        scanf(" %[^\n]%*c", str[i]);
    
    // Sorting
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("Order of Sorted Strings are: \n");
    for(int i = 0; i < size; i++)
        printf("%s\n", str[i]);
    printf("\n");

    return 0;
}
