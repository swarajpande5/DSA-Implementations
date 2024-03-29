// Maximum sum BST in binary tree: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/discuss/1126183/C%2B%2B-Recursion-or-Easy-to-understand
// https://www.youtube.com/watch?v=Zz7R9I9j2kI

/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Variable to store the overall maximum sum BST value
int ans;
    
class Properties
{
public:
    bool isBST;     // If current tree is BST or not
    int leftMax;    // Maximum value to the left of the current tree
    int rightMin;   // Minimum value to the right of the current tree
    int sum;        // Sum of all nodes including the current node
    
    Properties()
    {
        isBST = true;
        leftMax = INT_MIN;
        rightMin = INT_MAX;
        sum = 0;
    }
};

class Solution 
{
public:

    Properties calculateSum(TreeNode* root)
    {
        if(root == NULL)
            return Properties();
        
        Properties curr;
        Properties currLeft = calculateSum(root -> left);       // Recursive call for left sub-tree
        Properties currRight = calculateSum(root -> right);     // Recursive call for right sub-tree
        
        // If sub-tree including the current node is BST,
        // then we calculate 'leftMax', 'rightMin' and 'maxSum' for the current node.
        if( currLeft.isBST && 
            currRight.isBST && 
            root -> val > currLeft.leftMax &&
            root -> val < currRight.rightMin )
        {
            curr.isBST = true;
            curr.leftMax = max({ root -> val, currLeft.leftMax, currRight.leftMax });
            curr.rightMin = min({ root -> val, currLeft.rightMin, currRight.rightMin });
            curr.sum = root -> val + currLeft.sum + currRight.sum;
        }
        
        // else if the sub-tree including the  current node is not a BST,
        // then we simply update the 'sum' to the max sum of either left or right sub-tree.
        else 
        {
            curr.isBST = false;
            curr.sum = max(currLeft.sum, currRight.sum);
        }
        
        // Updating the overall maximum sum BST value
        ans = max(ans, curr.sum);
        
        // Finally returning the current property node
        return curr;
    }
    
    int maxSumBST(TreeNode* root) 
    {
        ans = INT_MIN;
        calculateSum(root);
        return ans > 0 ? ans : 0;
    }
};