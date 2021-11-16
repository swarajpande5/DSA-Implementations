// Bucket Sort (for floating point numbers)
#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float> &arr)
{
    int n = arr.size();

    vector<float> b[n];     // Creating n empty buckets

    // Putting array elements in different buckets
    for(int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i];
        b[bucketIndex].push_back(arr[i]);
    }

    // Sorting individual buckets
    for(int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    
    // Concatenating all the buckets into a single array
    int index = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main()
{
    int n;
    cin >> n;
    vector<float> arr(n);
    for(float &x: arr)
        cin >> x;
    
    bucketSort(arr);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}