// Maximum product after k increments: https://leetcode.com/problems/maximum-product-after-k-increments/

class Solution 
{
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<>> minHeap(nums.begin(), nums.end());
        
        while(k--)
        {
            int top = minHeap.top();
            minHeap.pop();
            minHeap.push(++top);
        }
        
        long long ans = 1;
        int mod = 1e9 + 7;
        while(!minHeap.empty())
        {
            ans = (ans * minHeap.top()) % mod;
            minHeap.pop();
        }
        
        return ans;
    }
};