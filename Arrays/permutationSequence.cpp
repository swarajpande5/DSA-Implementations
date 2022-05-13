// Permutation sequence: https://leetcode.com/problems/permutation-sequence/
// https://leetcode.com/problems/permutation-sequence/discuss/696910/C%2B%2B-or-100-time-space-efficient-or-Iterative-Solution-or-Detailed-Explanation-with-Example

class Solution 
{
public:
    
    vector<int> factorial;
    void populateFactorial(int n)
    {
        factorial = vector<int>(n);
        
        factorial[0] = 1;
        
        if(n == 1)
            return;
        
        factorial[1] = 1;
        for(int i = 2; i < n; i++)
            factorial[i] = i * factorial[i - 1];
    }
    
    string getPermutation(int n, int k) 
    {
        populateFactorial(n);
        
        vector<int> nums(n);
        
        for(int i = 0; i < n; i++)
            nums[i] = i + 1;
        
        n = n - 1;
        k = k - 1;
        
        string ans = "";
        
        while(n >= 0)
        {
            int nt = k / factorial[n];
            int kt = k % factorial[n];
            
            ans += (nums[nt] + '0');
            
            nums.erase(nums.begin() + nt);
            n--;
            k = kt;
        }
        
        return ans;
    }
};