// Program to convert Binary Search Tree to Max Heap
#include <bits/stdc++.h>
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

void inOrder(Node *node, vector<int> &arr)
{
    if(node == NULL)
        return;
    
    inOrder(node -> left, arr);
    arr.push_back(node -> info);
    inOrder(node -> right, arr);
}

void convertBSTHeap(Node *node, vector<int> arr, int *i)
{
    if(node == NULL)
        return;
    
    convertBSTHeap(node -> left, arr, i);
    convertBSTHeap(node -> right, arr, i);

    *i = *i + 1;
    node -> info = arr[*i];
}

void convertMaxHeap(Node *node)
{
    vector<int> arr;
    int i = -1;
    inOrder(node, arr);
    convertBSTHeap(node, arr, &i);
}

int main()
{
    Node *root = NULL;
    vector<int> arr;

    root = create(root, 4);
    root = create(root, 2);
    root = create(root, 6);
    root = create(root, 1);
    root = create(root, 3);
    root = create(root, 5);
    root = create(root, 7);

    inOrder(root, arr);
    for(int ele: arr)
        printf("%d ", ele);
    printf("\n");

    convertMaxHeap(root);
    arr.clear();

    inOrder(root, arr);
    for(int ele: arr)
        printf("%d ", ele);
    printf("\n");

    deleteTree(root);
    return 0;
}