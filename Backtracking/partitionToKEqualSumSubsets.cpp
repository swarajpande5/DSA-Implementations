// Partition to k equal sum subsets: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// Recursive backtracking solution: TLE 
class TLESolution 
{
public:
    
    bool isAllZero(vector<int> &subsetsSum)
    {
        for(int i = 0; i < subsetsSum.size(); i++)
            if(subsetsSum[i] != 0)
                return false; 
        
        return true;
    }

    bool solve(int index, vector<int> &nums, int &k, vector<int> &subsetSums)
    {
        if(index == nums.size())
            return isAllZero(subsetSums);
        
        for(int i = 0; i < k; i++)
        {
            // If the current number exceeds the allowable subset sum, 
            // we simply continue and do not make any further calls 
            if(subsetSums[i] < nums[index]) 
                continue;

            subsetSums[i] -= nums[index]; 
            if(solve(index + 1, nums, k, subsetSums))   // Recursive call
                return true; 
            subsetSums[i] += nums[index];               // Backtracking step
        }

        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0); 

        if(sum % k != 0)
            return false; 
        
        int eachSubsetSum = sum / k; 
        vector<int> subsetSums(k, eachSubsetSum); 

        // Sorting will help us eliminate the larger numbers immediately when check happens in the recursive function
        sort(nums.begin(), nums.end(), greater<int>()); 

        return solve(0, nums, k, subsetSums);
    }
};

// Optimized backtracking solution
class Solution 
{
public:
    
    bool solve(int index, vector<int> &nums, int currSum, int &eachSubsetSum, int k, vector<bool> &visited)
    {
        if(k == 1)
            return true; 

        // This line is important to avoid TLE
        if(index >= nums.size())
            return false; 

        if(currSum == eachSubsetSum)
            return solve(0, nums, 0, eachSubsetSum, k - 1, visited); 
        
        for(int i = index; i < nums.size(); i++)
        {
            if(visited[i] || currSum + nums[i] > eachSubsetSum)
                continue; 
            
            visited[i] = true; 
            if(solve(i + 1, nums, currSum + nums[i], eachSubsetSum, k, visited))    // Recursive call, IMPORTANT: index = i + 1
                return true; 
            visited[i] = false;                                                     // Backtracking step
        }

        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0); 

        if(sum % k != 0)
            return false; 
        
        int eachSubsetSum = sum / k; 
        vector<bool> visited(nums.size(), false);

        // Sorting will help us eliminate the larger numbers immediately when check happens in the recursive function
        sort(nums.begin(), nums.end(), greater<int>()); 

        return solve(0, nums, 0, eachSubsetSum, k, visited);
    }
};