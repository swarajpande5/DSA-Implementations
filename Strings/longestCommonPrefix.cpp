// Longest common prefix using sorting : https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> arr)
{
    if(arr.size() == 0)
        return "";
    
    if(arr.size() == 1)
        return arr[0];
    
    sort(arr.begin(), arr.end());

    int minLength = min(arr[0].size(), arr[arr.size() - 1].size());
    string first = arr[0], last = arr[arr.size() - 1];
    int i = 0;

    while(i < minLength && first[i] == last[i])
        i++;
    
    string pre = first.substr(0, i);
    return pre;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);

    for(string &x: arr)
        cin >> x;
    
    cout << longestCommonPrefix(arr) << "\n";

    return 0;
}