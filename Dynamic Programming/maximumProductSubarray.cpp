// Maximum Product Subarray : https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
#include <bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(int arr[], int n)
{
    int currMaxProd = arr[0];
    int currMinProd = arr[0];
    int maxProd = arr[0];

    for(int i = 1; i < n; i++)
    {
        int temp = max({arr[i], arr[i] * currMaxProd, arr[i] * currMinProd});
        
        currMinProd = min({arr[i], arr[i] * currMaxProd, arr[i] * currMinProd});
        currMaxProd = temp;

        maxProd = max(maxProd, currMaxProd);
    }

    return currMaxProd;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxSubarrayProduct(arr, n) << "\n";

    return 0;
}