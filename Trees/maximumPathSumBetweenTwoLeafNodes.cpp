// Maximum path sum between two leaf nodes: https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

class Solution
{
public:
    Node *rootRef;

    int findSum(Node *node, int &maxi)
    {
        if (!node)
            return 0;

        int leftSum = findSum(node->left, maxi);
        int rightSum = findSum(node->right, maxi);

        if ((node->left && node->right) || node == rootRef)
        {
            maxi = max(maxi, leftSum + rightSum + node->data);
            return node->data + max(leftSum, rightSum);
        }

        return (node->left) ? leftSum + node->data : rightSum + node->data;
    }

    int maxPathSum(Node *root)
    {
        rootRef = root;

        int res = INT_MIN;
        int val = findSum(root, res);

        if (res == INT_MIN)
            return val;

        return res;
    }
};