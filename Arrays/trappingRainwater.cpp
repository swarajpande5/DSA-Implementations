// Trapping Rainwater : https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;

int findwater(vector<int> arr)
{
    int n = arr.size();
    vector<int> left(n), right(n); 
    int water = 0;

    // Computing the highest bar on left and right side of every bar
    left[0] = arr[0];
    for(int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
    
    right[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
    
    // Calculating the accumulated water on i-th bar
    for(int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
    
    return water;
}

int findwaterEfficient(vector<int> arr)
{
    int water = 0;
    int leftmax = 0, rightmax = 0;
    int l = 0;
    int r = arr.size() - 1;

    while(l <= r)
    {
        if(arr[l] < arr[r])
        {
            if(arr[l] > leftmax)
                leftmax = arr[l];
            else 
                water += leftmax - arr[l];
            
            l++;
        }
        else 
        {
            if(arr[r] > rightmax)
                rightmax = arr[r];
            else 
                water += rightmax - arr[r];
            
            r--;
        }
    }

    return water;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    
    cout << findwater(arr) << endl;
    cout << findwaterEfficient(arr) << endl;

    return 0;
}