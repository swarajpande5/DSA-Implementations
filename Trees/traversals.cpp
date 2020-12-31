// Different Traversals on a Binary Tree
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

// In Order Traversal
void inOrder(Node *node)
{
    if(node == NULL)
        return;
    
    inOrder(node -> left);
    printf("%d ", node -> info);
    inOrder(node -> right);
}

// Pre Order Traversal (Depth-first Search, DFS)
void preOrder(Node *node)
{
    if(node == NULL)
        return;
    
    printf("%d ", node -> info);
    preOrder(node -> left);
    preOrder(node -> right);
}

// Post Order Traversal
void postOrder(Node *node)
{
    if(node == NULL)
        return;
    
    postOrder(node -> left);
    postOrder(node -> right);
    printf("%d ", node -> info);
}

// Level Order Traversal (Breadth-first Search, BFS)
void levelOrder(Node *node)
{
    if(node == NULL)
        return;
    
    queue<Node *> q;
    q.push(node);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        printf("%d ", curr -> info);

        if(curr -> left)
            q.push(curr -> left);
        
        if(curr -> right)
            q.push(curr -> right);
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

    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Preorder Traversal (DFS): ");
    preOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    printf("Level-order Traversal (BFS): ");
    levelOrder(root);
    printf("\n");

    deleteTree(root);
    return 0;
}