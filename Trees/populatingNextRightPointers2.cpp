// Populating next right pointers in each node 2: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
//                                                https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/962414/C%2B%2B-Recursion-and-Iteration-with-comments-and-figure-illustration
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// DFS based solution
class DFSSolution 
{
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return NULL;
        
        Node *p = root -> next;
        while(p)
        {
            if(p -> left)
            {    
                p = p -> left;
                break;
            }
            
            if(p -> right)
            {
                p = p -> right;
                break;
            }
            
            p = p -> next;
        }
        
        if(root -> right)
            root -> right -> next = p;
        
        if(root -> left)
            root -> left -> next = root -> right ? root -> right : p;
        
        connect(root -> right);
        connect(root -> left);
        
        return root;
    }
};

// BFS based solution
class BFSSolution
{
public:
    Node* connect(Node* root)
    {
        if(!root)
            return NULL;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            for(int i= 0, n = q.size(); i < n; i++)
            {
                auto curr = q.front();
                q.pop();
                
                if(i < n - 1)
                    curr -> next = q.front();
                
                if(curr -> left)
                    q.push(curr -> left);
                
                if(curr -> right)
                    q.push(curr -> right);
            }
        }
        
        return root;
    }
};

// Iterative solution (Space efficient)
class Solution
{
public:
    Node* connect(Node* root)
    {
        Node* dummy = new Node(0);
        Node *curr = dummy;
        Node *head = root;
        
        while(root)
        {
            for(auto i: {root -> left, root -> right})
            {
                if(i)
                {
                    curr -> next = i;
                    curr = curr -> next;
                }
            }
            
            root = root -> next;
            if(!root)
            {
                curr = dummy;
                root = dummy -> next;
                dummy -> next = NULL;
            }
        }
        
        return head;
    }
};