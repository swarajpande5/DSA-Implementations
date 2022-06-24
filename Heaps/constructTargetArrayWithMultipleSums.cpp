// Construct target array with multiple sums: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/1199207/Reverse-Simulation-using-Max-Heap-or-Easy-Solution-w-Explanation

class Solution 
{
public:
    
    long max(long a, long b)
    {
        if(a > b)
            return a;
        return b;
    }
    
    bool isPossible(vector<int>& target) 
    {
        if(target.size() == 1)
            return target[0] == 1;
        
        priority_queue<int> maxHeap(target.begin(), target.end());
        
        long long sum = accumulate(target.begin(), target.end(), 0l);
        
        // Repeat while all elements are not equal to 1
        while(maxHeap.top() != 1)
        {
            long largest = maxHeap.top();
            maxHeap.pop();
            int secondLargest = maxHeap.top();
            
            long remainingSum = sum - largest;
            
            // n = number of subtractions to do, such that 
            // the largest becomes just smaller than the secondLargest
            int n = max(1l, (long)(largest - secondLargest) / remainingSum);
            
            // Subtracting from largest n times, 
            // till it gets lower than secondLargest
            largest -= (remainingSum * n);
            
            maxHeap.push(largest);
            sum = remainingSum + largest;
            
            // If an element gets below 1, we can't achieve the original array
            if(largest < 1)
                return false;
        }
        
        return true;
    }
};