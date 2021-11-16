// Radix Sort (LSD)
#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int exp)
{
    int output[n];      // output array
    int count[10] = {0};

    // Storing count of occurences in count[]
    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    // Changing count[i] such that count[i] now contains actual 
    // position of this digit in output[]
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Building the output array 
    for(int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copying the output array to arr[]
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int mx = *max_element(arr, arr + n);

    // Performing counting sort for every digit
    for(int exp = 1; mx / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    radixSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}