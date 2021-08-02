// Peak Finding : https://leetcode.com/problems/find-peak-element/
#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if( (mid == 0 || nums[mid - 1] <= nums[mid]) &&
            (mid == nums.size() - 1 || nums[mid + 1] <= nums[mid]))
            return mid;
        
        else if(mid > 0 && nums[mid - 1] > nums[mid])
            high = mid - 1;
        
        else 
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int &x: nums)
        cin >> x;
    
    cout << findPeak(nums) << "\n";

    return 0;
}