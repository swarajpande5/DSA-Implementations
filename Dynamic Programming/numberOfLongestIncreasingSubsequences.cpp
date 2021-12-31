// Number of Longest Increasing Subsequences : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n, 1);      // Storing LIS's length upto current element
    vector<int> freq(n, 1);     // Storing count of LIS upto current element

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (lis[i] < lis[j] + 1)
                {
                    lis[i] = lis[j] + 1;
                    freq[i] = freq[j];
                }
                else if (lis[i] == lis[j] + 1)
                    freq[i] += freq[j];
            }
        }
    }

    int mx = *max_element(lis.begin(), lis.end());
    int count = 0;
    for (int i = 0; i < n; i++)
        if (lis[i] == mx)
            count += freq[i];

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findNumberOfLIS(arr) << "\n";

    return 0;
}