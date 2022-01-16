// Combinations: https://leetcode.com/problems/combinations/

class Solution
{
public:
    vector<vector<int>> ans;

    void backtrack(int index, int k, vector<int> &current, int n)
    {
        // Base case
        if (current.size() == k)
        {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < n + 1; i++)
        {
            current.push_back(i);            // Considering the current element
            backtrack(i + 1, k, current, n); // Generating combinations
            current.pop_back();              // Proceeding to next element
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> current;
        backtrack(1, k, current, n);
        return ans;
    }
};