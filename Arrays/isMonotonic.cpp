// Monotonic Array : https://leetcode.com/problems/monotonic-array/
#include <bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int> arr)
{
    bool isNonDecreasing = true;
    bool isNonIncreasing = true;

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < arr[i-1])
            isNonDecreasing = false;
        if(arr[i] > arr[i-1])
            isNonIncreasing = false;
    }

    return isNonDecreasing || isNonIncreasing; 
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    
    isMonotonic(arr)? cout << "Monotonic\n" : cout << "Not Monotonic\n";

    return 0;
}