/* 
    Polynomial Addition and Multiplication implementation 
    using linked lists.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coeff;
    int pow;

    struct Node *link;
};

void readPolynomial (struct Node **polyRef)
{
    float coeffInput;
    int powInput, ans; 
    struct Node *in;

    in = (struct Node *)malloc(sizeof(struct Node));
    *polyRef = in;

    do 
    {
        printf("Coefficient : ");
        scanf("%f", &coeffInput);
        printf("Power : ");
        scanf("%d", &powInput);
        
        in -> coeff = coeffInput;
        in -> pow = powInput;
        in -> link = NULL;

        printf("Have more terms ? (1 or 0) : ");
        scanf("%d", &ans);

        if(ans)
        {
            in -> link = (struct Node *)malloc(sizeof(struct Node));
            in = in -> link;
            in -> link = NULL;
        }

    } while(ans);

    in = NULL;
    free(in);
}

void printPolynomial(struct Node* poly)
{
    printf("Polynomial expression is: \n");

	while(poly != NULL)
	{
		printf("%fX^%d", poly -> coeff, poly -> pow);
		
        poly = poly -> link;
		
        if(poly != NULL)
			printf("+");
	}
    printf("\n");
}

void addPolynomials(struct Node **resultRef, struct Node *firstPoly, struct Node *secondPoly)
{
    struct Node *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> link = NULL;

    *resultRef = temp;

    while(firstPoly && secondPoly)
    {
        if((firstPoly -> pow) > (secondPoly -> pow))
        {
            temp -> coeff = firstPoly -> coeff;
            temp -> pow  = firstPoly -> pow;
            firstPoly = firstPoly -> link;
        }

        else if((firstPoly -> pow) < (secondPoly -> pow))
        {
            temp -> coeff = secondPoly -> coeff;
            temp -> pow  = secondPoly -> pow;
            secondPoly = secondPoly -> link;
        }

        else 
        {
            temp -> coeff = firstPoly -> coeff + secondPoly -> coeff;
            temp -> pow = firstPoly -> pow;

            firstPoly = firstPoly -> link;
            secondPoly = secondPoly -> link;
        }

        if(firstPoly && secondPoly)
        {
            temp -> link = (struct Node *)malloc(sizeof(struct Node));

            temp = temp -> link;
            temp -> link = NULL;
        }
    }

    while (firstPoly || secondPoly)
    {
        temp -> link = (struct Node *)malloc(sizeof(struct Node));
        
        temp = temp -> link;
        temp -> link = NULL;

        if(firstPoly)
        {
            temp -> coeff = firstPoly -> coeff;
            temp -> pow = firstPoly -> pow;

            firstPoly = firstPoly -> link;
        }

        else if(secondPoly)
        {
            temp -> coeff = secondPoly -> coeff;
            temp -> pow = secondPoly -> pow;

            secondPoly = secondPoly -> link;
        }
    }

    temp = NULL;
    free(temp);
}

void insertNode(struct Node **polyRef, float coeffInput, int powInput)
{
    struct Node *start;
    start = (struct Node *)malloc(sizeof(struct Node));

    start -> coeff = coeffInput;
    start -> pow = powInput;

    if(*polyRef)
    {
        struct Node *temp = *polyRef;
        
        while (temp -> link != NULL)
            temp = temp -> link;

        temp -> link = start;
    }

    else 
        *polyRef = start;

}

void multiplyPolynomial(struct Node **result, struct Node *firstPoly, struct Node *secondPoly)
{
    if(!firstPoly || !secondPoly)
        *result = NULL;
    
    else 
    {
        struct Node *firstPtr, *secondPtr, *prev;
        int flag;
        
        // Loop to multiply the two equations
        firstPtr = firstPoly;
        while (firstPtr)
        {
            secondPtr = secondPoly;
            while(secondPtr)
            {
                insertNode(result, (firstPtr -> coeff * secondPtr -> coeff), 
                (firstPtr -> pow + secondPtr -> pow));

                secondPtr = secondPtr -> link;
            }
            firstPtr = firstPtr -> link;
        }

        // Loop to simplifly the results
        firstPtr = *result;
        while(firstPtr)
        {
            secondPtr = firstPtr -> link;
            prev = firstPtr;
            while(secondPtr)
            {
                if(firstPtr -> pow == secondPtr -> pow)
                {
                    firstPtr -> coeff = firstPtr -> coeff + secondPtr -> coeff;
                    prev -> link = secondPtr -> link;
                }
                secondPtr = secondPtr -> link;
                prev = prev -> link;
            }
            firstPtr = firstPtr -> link;
        }
    }

}

int main()
{
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *addResult = NULL;
    struct Node *mulResult = NULL;

    printf("Enter the corresponding data : \n");
	printf("First polynomial\n");
    readPolynomial(&first);
    printPolynomial(first);

    printf("Second polynomial\n");
    readPolynomial(&second);

    addPolynomials(&addResult, first, second);
	printPolynomial(addResult);

    multiplyPolynomial(&mulResult, first, second);
    printPolynomial(mulResult);

    free(first);
    free(second);
    free(addResult);
    free(mulResult);
}