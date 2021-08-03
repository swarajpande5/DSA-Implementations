// Equilibrium Point of an Array : https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
#include <bits/stdc++.h>
using namespace std;

int equilibrium(vector<int> arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int leftsum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        sum -= arr[i];

        if(leftsum == sum)
            return i;
        
        leftsum += arr[i];
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    
    cout << equilibrium(arr) << "\n";

    return 0;
}