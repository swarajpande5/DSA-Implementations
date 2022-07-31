// Range sum query mutable: https://leetcode.com/problems/range-sum-query-mutable/
// https://cp-algorithms.com/data_structures/segment_tree.html
// Video: https://youtu.be/2bSS8rtFym4 (Tech Dose)

class NumArray 
{
public:
    
    // Segment Tree to be stored in a vector.
    vector<int> segment;
    
    // Length of the segment tree vector.
    int n;
    
    
    void buildTree(vector<int> &nums, int pos, int left, int right)
    {
        if(left == right)
        {
            segment[pos] = nums[left];
            return;
        }
        
        int mid = (left + right) / 2;
        buildTree(nums, 2 * pos + 1, left, mid);
        buildTree(nums, 2 * pos + 2, mid + 1, right);
        
        segment[pos] = segment[2 * pos + 1] + segment[2 * pos + 2];
    }
    
    
    void updateUtil(int pos, int left, int right, int index, int val)
    {
        // No overlap
        if(index < left || index > right)
            return;
        
        // Total overlap
        if(left == right)
        {
            if(left == index)
                segment[pos] = val;
            
            return;
        }
        
        // Partial overlap
        int mid = (left + right) / 2;
        updateUtil(2 * pos + 1, left, mid, index, val);         // Left child
        updateUtil(2 * pos + 2, mid + 1, right, index, val);    // Right child
        
        segment[pos] = segment[2 * pos + 1] + segment[2 * pos + 2];
    }
    
    int rangeUtil(int qlow, int qhigh, int low, int high, int pos)
    {
        // Total overlap
        if(qlow <= low && qhigh >= high)
            return segment[pos];
        
        // No overlap
        if(qlow > high || qhigh < low)
            return 0;
        
        int mid = low + (high - low) / 2;
        return rangeUtil(qlow, qhigh, low, mid, 2 * pos + 1) + rangeUtil(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    }
    
    NumArray(vector<int>& nums) 
    {
        if(nums.size() > 0)
        {
            n = nums.size();
            
            // Maximum size of a segment tree for an array of size n is 4n.
            segment.resize(4 * n, 0);
            
            // Build the segment tree
            buildTree(nums, 0, 0, n - 1);
        }
    }
    
    void update(int index, int val) 
    {
        if(n == 0)
            return;
        
        updateUtil(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) 
    {
        if(n == 0)
            return 0;
        
        return rangeUtil(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */