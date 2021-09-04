// Count the number of subarrays having a given XOR : https://www.interviewbit.com/problems/subarray-with-given-xor/
#include <bits/stdc++.h>
using namespace std;

// Naive solution
int subarrayXORNaive(vector<int> arr, int m)
{
    int ans = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int xorSum = 0;
        for(int j = i; j < arr.size(); j++)
        {
            xorSum = xorSum ^ arr[j];
            
            if(xorSum == m)
                ans++;
        }
    }
    return ans;
}

// Efficient solution
int subarrayXOR(vector<int> arr, int m)
{
    map<int, int> freq;
    int count = 0;
    int xorSum = 0;

    for(auto it: arr)
    {
        xorSum = xorSum ^ it;

        if(xorSum == m)
            count++;
        
        if(freq.find(xorSum ^ m) != freq.end())
            count += freq[xorSum ^ m];
        
        freq[xorSum] += 1;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    int m;
    cin >> m;

    cout << subarrayXORNaive(arr, m) << "\n";
    cout << subarrayXOR(arr, m) << "\n";

    return 0;
}
