// Print sum of cousins of a given node in a binary tree 
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int info;
    struct Node *left, *right;
}Node;

Node *newNode(int value)
{
    Node *in = new Node();
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

    delete node;
    return NULL;
}

int findCousinSum(Node *root, int key)
{
    if(root == NULL)
        return -1 ;
    
    // Root node has no cousins hence returning -1 
    if(root -> info == key)
        return - 1;
    
    int currSum = 0;    // To store sum of cousins 
    int size;           // To store size of current level 

    bool found = false; // Flag for target node is found or not.

    queue<Node *> q;    // For performing level order traversal
    q.push(root);

    while(!q.empty())
    {
        // If target node present in current level, then return sum of cousins 
        if(found == true)
            return currSum;
        
        size = q.size();
        currSum = 0;
        
        while(size)
        {
            root = q.front();
            q.pop();

            // Checking if either of current node's children is target node or not
            if ((root -> left && root -> left -> info == key) || 
                (root -> right && root -> right -> info == key)) 
                found = true;
            
            // If target node is not child of current node, the its children can be cousin of target.
            // Hence, adding their value to sum.
            else 
            {
                if(root -> left)
                {
                    currSum += root -> left -> info;
                    q.push(root -> left);
                }
                if(root -> right)
                {
                    currSum += root -> right -> info;
                    q.push(root -> right);
                }
            }

            size--;
        }
    }

    return -1;
}

int main()
{
    Node *root = NULL;

    root = create(root, 1);
    root = create(root, 2);
    root = create(root, 3);
    root = create(root, 4);
    root = create(root, 5);
    root = create(root, 6);
    root = create(root, 7);
    root = create(root, 8);
    root = create(root, 9);
    root = create(root, 10);

    /*

                1
              /   \
             2     3
            /  \  /  \
           4   5  6   7
          / \  |
         8   9 10
    */

    
    int key = 6;
    cout << findCousinSum(root, key) << "\n";

    deleteTree(root);
    return 0;
}