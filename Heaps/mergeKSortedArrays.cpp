// Merge K sorted arrays: https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Merge K sorted arrays of any size: https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-2-different-sized-arrays/

// Comparator to create max heap based on the first element of the array
struct comp
{
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res; 

    // Priority queue will contain element as a vector of size 3.
    // Where, vec[0] = value, vec[1] = index of array, vec[2] = index of element inside that array

    priority_queue<vector<int>, vector<vector<int>>, comp> pq; 

    for(int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], i, 0});
    }

    while(!pq.empty())
    {
        auto temp = pq.top(); 
        pq.pop();

        int value = temp[0];
        int i = temp[1]; 
        int j = temp[2];

        res.push_back(value); 

        if(j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], i, j + 1}); 
    }

    return res;
    }
};