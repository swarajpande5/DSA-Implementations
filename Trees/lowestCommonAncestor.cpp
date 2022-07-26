// Lowest common ancestor (LCA of binary tree): https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive solution 
class RecursiveSolution
{
public: 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // Base case
        if(root == NULL || root == p || root == q)
            return root; 

        TreeNode *left = lowestCommonAncestor(root -> left, p, q);
        TreeNode *right = lowestCommonAncestor(root -> right, p, q); 

        if(left == NULL)
            return right; 
        else if(right == NULL)
            return left; 
        else                    
        {
            // If both left and right are not null, we have found our result
            return root;
        }
    }
};