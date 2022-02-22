// Subtree of another tree: https://leetcode.com/problems/subtree-of-another-tree/

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
class Solution 
{
public:
    
    bool isSametree(TreeNode *s, TreeNode *t)
    {
        if(!s || !t)
            return s == NULL && t == NULL;
        
        else if(s -> val == t -> val)
            return isSametree(s -> left, t -> left) && isSametree(s -> right, t -> right);
        else 
            return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root)
            return false;
        
        else if(isSametree(root, subRoot))
            return true;
        
        else 
            return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};