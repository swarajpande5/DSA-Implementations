// Range frequency queries: https://leetcode.com/problems/range-frequency-queries/

// Segment Tree Solution (TLE)
class RangeFreqQuerySegmentTree 
{
public:
    // Each node in segment tree keeps a hashmap of count of array items for the given range
    vector<unordered_map<int, int>> segment;

    // Length of segment tree vector
    int n;

    // Create a vector to make the elements global
    vector<int> nums;

    RangeFreqQuery(vector<int>& arr) 
    {
        n = arr.size();
        segment.resize(4 * n);
        nums = arr;
        buildTree(0, 0, n - 1);
    }
    
    void buildTree(int index, int left, int right)
    {
        if(left == right)
        {
            segment[index][nums[left]]++;
            return;
        }

        int mid = left + (right - left) / 2;

        // Recursive calls for left and right subtree
        buildTree(2 * index + 1, left, mid);
        buildTree(2 * index + 2, mid + 1, right);

        // Left node 
        for (auto &p: segment[2 * index + 1])
            segment[index][p.first] += segment[2 * index + 1][p.first];

        // Right node
        for(auto &p: segment[2 * index + 2])
            segment[index][p.first] += segment[2 * index + 2][p.first];
    }

    int queryUtil(int index, int left, int right, int l, int r, int value)
    {
        // Complete overlap
        if(l <= left && right <= r)
            return segment[index][value];

        // No overlap 
        if(r < left || right < l)
            return 0;
        
        // Partial overlap 
        int mid = (left + right) / 2;
        int ll = queryUtil(2 * index + 1, left, mid, l, r, value);
        int rr = queryUtil(2 * index + 2, mid + 1, right, l, r, value);

        return ll + rr;
    }

    int query(int left, int right, int value) 
    {
        return queryUtil(0, 0, n - 1, left, right, value);
    }
};


// Vector of Indices + Binary search solution
/*
    Logic:
    We just need to maintain a vector of indices for each element in the order they occur.
    Then querying for frequency between a range [left, right] is simply finding highest index and lowest index
    of that element within the given range and returning number of elements between them in the vector of indices.

    The highest and lowest index can be found using binary search (upper_bound and lower_bound) in O(logN) time.
*/
class RangeFreqQuery 
{
public:

    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int> &arr)
    {
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);
    }

    int query(int left, int right, int value)
    {
        return upper_bound(mp[value].begin(), mp[value].end(), right) - lower_bound(mp[value].begin(), mp[value].end(), left);
    }
};


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
