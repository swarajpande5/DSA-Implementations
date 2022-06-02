// kth smallest element in a sorted matrix: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class HeapSolution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        priority_queue<int> pq;
        int n = matrix.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution 
{
public:
    
    // To count how many numbers are less than or equal to mid (from bottom-left or top-right)
    int solve(vector<vector<int>> &matrix, int mid)
    {
        int n = matrix.size();
        int count = 0;
        
        int i = n - 1;
        int j = 0;
        
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] > mid)
                i--;
            else 
            {
                count += (i + 1);
                j++;
            }
        }
        
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size(); 
        int i = matrix[0][0];
        int j = matrix[n - 1][n - 1];
        
        while(i < j)
        {
            int mid = i + (j - i) / 2;
            
            int pos = solve(matrix, mid);
            if(pos < k)
                i = mid + 1;
            else 
                j = mid;
        }
        
        return i;
    }
};