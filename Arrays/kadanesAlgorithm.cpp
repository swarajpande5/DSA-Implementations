// Kadane's Algorithm for finding Maximum Subarray Sum (Contiguous)
#include <bits/stdc++.h>
using namespace std;

int kadanes(vector<int> arr)
{
    int currSum = 0, maxSum = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i];

        if(currSum < 0)
            currSum = 0;
        
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    
    cout << kadanes(arr) << "\n";

    return 0;
}