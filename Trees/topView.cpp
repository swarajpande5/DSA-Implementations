// Top View of a Binary Tree : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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

Node *deleteTree(Node *node)
{
    if(node == NULL)
        return NULL;
    
    deleteTree(node -> left);
    deleteTree(node -> right);

    free(node);
    return NULL;
}

vector<int> topView(Node *root)
{
    vector<int> ans;

    if(root == NULL)
        return ans;
    
    Node *temp = NULL;
    
    // Queue for level order traversal 
    queue<pair<Node *, int>> q;

    // Map to store nodes at a particular horizontal distance 
    map<int, int> mp;

    q.push({root, 0});

    while(!q.empty())
    {
        temp = q.front().first;
        int d = q.front().second;
        q.pop();

        // Storing the data in a map if the distance does not already exist
        if(mp.find(d) == mp.end())
            mp[d] = temp -> info;
        
        // If child exist, then pushing it into the queue with the apt horizontal distance
        if(temp -> left)
            q.push({temp -> left, d - 1});
        if(temp -> right)
            q.push({temp -> right, d + 1});
    }

    // Traversing the map and storing the nodes in the answer vector
    for(auto it = mp.begin(); it != mp.end(); it++)
        ans.push_back(it -> second);
    
    return ans;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    vector<int> ans = topView(root);
    for(int x: ans)
        cout << x << " ";
    cout << "\n";

    deleteTree(root);

    return 0;
}