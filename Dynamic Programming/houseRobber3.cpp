// House Robber 3: https://leetcode.com/problems/house-robber-iii/
// https://leetcode.com/problems/house-robber-iii/discuss/1612349/C%2B%2BPython-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Optimized-DP

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

// Recursive Solution (T.C. = O(2 ^ n))
class RecursiveSolution
{
public:
    int robUtil(TreeNode *root, bool canRob)
    {
        if(!root)
            return 0;
        
        int dontRob = robUtil(root -> left, true) + robUtil(root -> right, true);
        int robRoot = canRob ? root -> val + robUtil(root -> left, false) + robUtil(root -> right, false) : -1; 

        return max(dontRob, robRoot);
    }

    int rob(TreeNode *root)
    {
        return robUtil(root, true);
    }
};

// Top Down (Memoization) Solution (T.C. = O(n) and S.C. = O(n))
class TopDownSolution
{
public:
    unordered_map<TreeNode *, vector<int>> dp; 

    int robUtil(TreeNode *root, bool canRob)
    {
        if(!root)
            return 0; 

        if(dp.count(root) && dp[root][canRob] != -1)
            return dp[root][canRob]; 
        
        dp[root] = {-1, -1}; 

        int dontRob = robUtil(root -> left, true) + robUtil(root -> right, true);
        int robRoot = canRob ? root -> val + robUtil(root -> left, false) + robUtil(root -> right, false) : -1; 

        return dp[root][canRob] = max(dontRob, robRoot);
    }

    int rob(TreeNode *root)
    {
        return robUtil(root, true);
    }
};


// Space Optimized DP (T.C. = O(n) and S.C. = O(h) = recursive stack)
class Solution
{
public:
    pair<int, int> dfs(TreeNode *root)
    {
        if(!root)
            return {0, 0}; 

        auto [leftDontRob, leftRob] = dfs(root -> left); 
        auto [rightDontRob, rightRob] = dfs(root -> right);

        return {
            max(leftDontRob, leftRob) + max(rightDontRob, rightRob), 
            root -> val + leftDontRob + rightDontRob
        };
    }

    int rob(TreeNode *root)
    {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};