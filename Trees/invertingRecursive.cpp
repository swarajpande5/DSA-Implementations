// Inverting a Binary tree using recursion
#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    struct Node *left, *right;
}Node;

Node* newNode(int value)
{
    Node *in = (Node *)malloc(sizeof(Node));
    in -> info = value;
    in -> left = in -> right = NULL;
    return in;
}

Node* create(Node *node, int value)
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

Node* deleteTree(Node *node)
{
    if(node == NULL)
        return NULL;
    
    deleteTree(node -> left);
    deleteTree(node -> right);

    free(node);
    return NULL;
}

Node* delet(Node *node, int value)
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

// Recursive
void invert(Node *node)
{
    if(node == NULL)
        return;
    
    else 
    {
        Node *temp;

        invert(node -> left);
        invert(node -> right);

        temp = node -> left;
        node -> left = node -> right;
        node -> right = temp;
    }
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

    invert(root);
    printTree(root);
    printf("\n");

    deleteTree(root);
    return 0;
}


