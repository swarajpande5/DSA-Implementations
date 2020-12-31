// Binary Search Tree implementation (Recursive functions)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *left, *right;
}Node;

Node *newNode(int value)
{
    Node *in = (Node *)malloc(sizeof(Node));
    in -> info = value;
    in -> left = in -> right = NULL;
    return in;
}

Node *create(Node *node, int value)
{
    if(node == NULL)
        node = newNode(value);
    
    else if(value <= node -> info)
        node -> left = create(node -> left, value);
    
    else 
        node -> right = create(node -> right, value);

    return node;
}

Node *deleteTree(Node *node)
{
    if(node == NULL)
        return NULL;
    
    deleteTree(node -> left);
    deleteTree(node -> right);

    free(node);
    return NULL;
}

Node *delet(Node *node, int value)
{
    if(node == NULL)
        printf("Not found ! \n");
    
    if(node -> info == value)
        node = deleteTree(node);
    
    else if(value < node -> info)
        node -> left = delet(node -> left, value);
    
    else 
        node -> right = delet(node -> right, value);

    return node;
}

void printTree(Node *node)
{
    if(node == NULL)
        return;
    
    printf("%d(", node -> info);
	
    printTree(node -> left);
	
    printf(" , ");
	
    printTree(node -> right);
	
    printf(")");
}

int search(Node *node, int value)
{
    if(node == NULL)
        return 0;
    
    if(node -> info == value)
        return 1;
    
    if(value < node -> info)
        return search(node -> left, value);
    
    else 
        return search(node -> right, value);
}

int height(Node *node)
{
    if(node == NULL)
        return 0;
    
    else 
    {
        int leftHeight = height(node -> left);
        int rightHeight = height(node -> right);

        if(leftHeight > rightHeight)
            return(leftHeight + 1);
        
        else 
            return(rightHeight + 1);
    }
}

int countNodes(Node *node)
{
    if(node == NULL)
        return 0;
    
    return(1 + countNodes(node -> left) + countNodes(node -> right));
}

int isComplete(Node *node, int index, int nodeCount)
{
    if(node == NULL)
        return 1;
    
    if(index >= nodeCount)
        return 0;

    return (isComplete(node -> left, 2*index + 1, nodeCount) &&
            isComplete(node -> right, 2*index + 2, nodeCount));
}

int main()
{
    Node *root = NULL;

    root = create(root, 5);
    root = create(root, 1);
    root = create(root, 7);

    int nodeCount = countNodes(root);
    int index = 0;

    printTree(root);
    printf("\n");

    search(root, 5) ? printf("Found!\n") : printf("Not Found!\n");

    isComplete(root, index, nodeCount) ? printf("Balanced!\n") : printf("Not Balanced!\n");

    printf("Height: %d\n", height(root));

    deleteTree(root);

    return 0;
}