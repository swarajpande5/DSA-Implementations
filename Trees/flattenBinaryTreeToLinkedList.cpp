// Flatten binary tree to linked list: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Morris Traversal
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        TreeNode *curr = root; 
        
        while(curr)
        {
            if(curr -> left)
            {
                TreeNode *runner = curr -> left; 
                
                while(runner -> right)
                    runner = runner -> right;
                
                runner -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            
            curr = curr -> right;
        }
    }
};


// Recursive Solution
class RecursiveSolution 
{
public:
    
    TreeNode *prev = NULL;
    
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
            return;
        
        flatten(root -> right);
        flatten(root -> left); 
        
        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
};