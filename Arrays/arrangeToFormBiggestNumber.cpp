// Largest number formed from an array : https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
#include <bits/stdc++.h>
using namespace std;

int cmp(string x, string y)
{
    string xy = x.append(y);
    string yx = y.append(x);

    return xy.compare(yx) > 0 ? 1 : 0;
}

string printLargest(vector<string> &arr)
{
    sort(arr.begin(), arr.end(), cmp);

    string ans;
    for(auto x : arr)
        ans += x;
    
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for(auto &x: arr)
        cin >> x;
    
    cout << printLargest(arr) << "\n";

    return 0;
}