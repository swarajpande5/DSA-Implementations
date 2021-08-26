// Reverse Pairs: https://leetcode.com/problems/reverse-pairs/
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int l, int m, int r)
{
    int i, j, k;
    int invcount = 0;
    j = m + 1;
    for(i = l; i <= m; i++)
    {
        while(j <= r && arr[i] > (long long) 2 * arr[j])
            j++;
        invcount += (j- (m + 1));
    }
    
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];

        else
            arr[k++] = R[j++];
    }
    while (i < n1 || j < n2)
    {
        if (i < n1)
            arr[k++] = L[i++];

        else
            arr[k++] = R[j++];
    }

    return invcount;
}

int mergeSort(vector<int>& arr, int l, int r)
{
    if(l >= r)   return 0;

    int m = l + (r - l) / 2;
    
    int invcount = mergeSort(arr, l, m);
    invcount += mergeSort(arr, m + 1, r);
    invcount += merge(arr, l, m, r);
    
    return invcount;
}

int reversePairs(vector<int>& nums) 
{
    return mergeSort(nums, 0, nums.size()-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    
    cout << reversePairs(arr) << "\n";

    return 0;
}