// Count of smaller numbers after self: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

using namespace __gnu_pbds;

// STL solution
class STLSolution 
{
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        pbds s;
        vector<int> ans;
        
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i == nums.size() - 1)
                ans.push_back(0);
            else 
                ans.push_back(s.order_of_key({nums[i], i}));
            
            s.insert({nums[i], i});
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Merge sort solution
class Solution
{
public:
    void merge(vector<int> &count, vector<pair<int, int>> &v, int low, int mid, int high)
    {
        vector<pair<int, int>> temp(high - low + 1);

        int i = low;
        int j = mid + 1;
        int k = 0;

        while(i <= mid && j <= high)
        {
            if(v[i].first <= v[j].first)
            {
                temp[k] = v[j];
                k++;
                j++;
            }
            else 
            {
                // All elements to right will be smaller because here we're sorting in descending order
                count[v[i].second] += high - j + 1;
                temp[k] = temp[i];
                k++;
                i++;
            }
        }

        while(i <= mid)
        {
            temp[k] = v[i];
            k++;
            i++;
        }

        while(j <= high)
        {
            temp[k] = v[j];
            k++;
            j++;
        }

        // Changing the original array
        for(int i = low; i <= high; i++)
            v[i] = temp[i - low];
    }

    void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int low, int high)
    {
        // Classic merge sort
        if(low < mid)
        {
            int mid = low + (high - low) / 2;
            mergeSort(count, v, low, mid);
            mergeSort(count, v, mid + 1, high);
            merge(count, low, mid, high);
        }
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> v(n);

        for(int i = 0; i < n; i++)
        {
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }

        vector<int> count(n, 0);
        mergeSort(count, v, 0, n - 1);
        return count;
    }
};