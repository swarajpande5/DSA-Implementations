// Kth Smallest element in an array :   https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Kth Largest element in an array :    https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int> arr, int k)
{
    // max heap using priority queue
    priority_queue<int, vector<int>> pq(arr.begin(), arr.begin() + k);              // pushing first k elements

    // for remaining elements 
    for(int i = k; i < arr.size(); i++)
    {
        if(arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int findKthLargest(vector<int> arr, int k)
{
    // min heap using priority queue
    priority_queue<int, vector<int>, greater<>> pq(arr.begin(), arr.begin() + k);   // pushing first k elements

    // for remaining elements 
    for(int i = k; i < arr.size(); i++)
    {
        if(arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

// Improved solution using Quickselect (Quick sort)
int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) 
    {
        int pos = partition(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) 
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) 
    {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        vec[i] = arr[i];
    }
    
    int k;
    cin >> k;

    cout << findKthSmallest(vec, k) << endl;
    cout << findKthLargest(vec, k) << endl;
    cout << kthSmallest(arr, 0, n - 1, k) << endl;

    return 0;
}