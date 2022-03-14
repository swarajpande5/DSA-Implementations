// Binary tree maximum path sum: https://leetcode.com/problems/binary-tree-maximum-path-sum/
//                               https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/1288024/C%2B%2B-Easy-to-understand-Full-explanation-article-with-code   

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
    
    // This function returns the Branch sum.
    // If the node is NULL, then it won't have a branch, so branch sum will be zero
    int maxSum(TreeNode *root, int &ans)
    {
        if(root == NULL)
            return 0;
        
        int leftBranchSum = root -> val + maxSum(root -> left, ans);
        int rightBranchSum = root -> val + maxSum(root -> right, ans);
        
        ans = max({
                    ans,                                            // We may have found the maximum already
                    root -> val,                                    // Maybe the current node is the maximum sum possible
                    leftBranchSum,                                  // Maybe the answer is the root -> val + left branch value
                    rightBranchSum,                                 // Maybe the answer is the root -> val + right branch value
                    leftBranchSum + rightBranchSum - root -> val    // Maybe the answer contain both left branch value and right branch value.
                                                                    // Since we adding the branches twice, root of those branches is subtracted.
        });
        
        // Returning the maximum branch sum
        return max({leftBranchSum, rightBranchSum, root -> val});
    }
    
    
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        maxSum(root, ans);
        return ans;
    }
};