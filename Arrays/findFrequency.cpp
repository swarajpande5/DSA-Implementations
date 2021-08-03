// Find the frequency of each element in a sorted array containing duplicates
#include <bits/stdc++.h>
using namespace std;

void findFrequency(vector<int> arr, unordered_map<int, int> &freq)
{
    int low = 0, high = arr.size() - 1, mid;

    while(low <= high)
    {
        if(arr[low] == arr[high])
        {
            freq[arr[low]] += high - low + 1;

            low = high + 1;
            high = arr.size() - 1;
        }

        else 
            high = (low + high) / 2;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    
    unordered_map<int, int> freq;
    findFrequency(arr, freq);

    for(auto it: freq)
    {
        cout << it.first << " : " << it.second << "\n";
    }

    return 0;
}
