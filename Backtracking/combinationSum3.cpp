// Combination sum 3: https://leetcode.com/problems/combination-sum-iii/

/*
    Intuition: 
    The key idea to this question is backtracking, that is,
    generating all possible combinations and storing the ones that fulfills the conditonns.
    
    We choose a number for 1, 2, 3, ..., kth position in ascending order,
    and for each position, we only iterate through [current_number, 9].
*/

class Solution 
{
public:
    
    vector<vector<int>> ans;
    
    void solve(int k, int n, vector<int> &curr, int currnum)
    {
        if(n < 0 || curr.size() > k)
            return;
        
        if(n == 0 && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i = currnum; i <= 9; i++)
        {
            curr.push_back(i);
            solve(k, n - i, curr, i + 1);       // Recursive call
            curr.pop_back();                    // Backtracking 
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> curr;
        solve(k, n, curr, 1);
        return ans;
    }
};