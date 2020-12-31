// Binary Tree implementation
#include<bits/stdc++.h>
using namespace std;

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
    {
        node = newNode(value);
        return node;
    }
    
    queue<Node *> q;
    q.push(node);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp -> left != NULL)
            q.push(temp -> left);
        else
        {
            temp -> left = newNode(value);
            return node;
        }

        if(temp -> right != NULL)
            q.push(temp -> right);
        else
        {
            temp -> right = newNode(value);
            return node;
        }
    }
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
    
    int resultLeft = search(node -> left, value);
    if(resultLeft)
        return 1;
    
    int resultRight = search(node -> right, value);
    if(resultRight)
        return 1;
    
    return 0;
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

int isComplete(Node *node)
{
    if(node == NULL)
        return 1;

    queue<Node *> q;
    q.push(node);

    Node *temp = NULL;
    int flag = 0;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(flag && (temp -> left || temp -> right))
            return 0;
        
        if(temp -> left == NULL && temp -> right)
            return 0;
        
        if(temp -> left)
            q.push(temp -> left);
        else 
            flag = 1;

        if(temp -> right)
            q.push(temp -> right);
        else 
            flag = 1;
    }
    return 1;
}

int main()
{
    Node *root = NULL;

    root = create(root, 1);
    root = create(root, 2);
    root = create(root, 3);
    root = create(root, 4);
    root = create(root, 5);
    printTree(root);
    printf("\n");

    search(root, 5) ? printf("Found!\n") : printf("Not Found!\n");

    if(isComplete(root))
        printf("Complete Binary Tree!\n");
    else 
        printf("Incomplete Binary Tree!\n");

    printf("Height: %d\n", height(root));

    deleteTree(root);

    return 0;
}