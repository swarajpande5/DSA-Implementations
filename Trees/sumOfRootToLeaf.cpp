// Sum of root to leaf binary numbers: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    
    int total(TreeNode *node, int current)
    {
        // If node is null then we simply return zero
        if(!node)
            return 0;
        
        // Otherwise we calculate the sum of binary number into decimal
        current = current * 2 + node -> val;

        // Checking if current node we are processing is leaf, in that case we simply return the sum
        if(!node -> left && !node -> right)
                return current;
        
        // Otherwise we call both left and right subtree and add them
        return total(node -> left, current) + total(node -> right, current);
    }
    
    int sumRootToLeaf(TreeNode* root) 
    {
        return total(root, 0);
    }
};