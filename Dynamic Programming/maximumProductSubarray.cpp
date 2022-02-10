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

    return maxProd;
}

/*
    ALTER:
    https://leetcode.com/problems/maximum-product-subarray/discuss/183483/JavaC++Python-it-can-be-more-simple/330117
    If there's no zero in the array, then the subarray with maximum product must start with the first element or 
    end with the last element. And therefore, the maximum product must be some prefix product or suffix product.
    So in the following approach, we compute the prefix product and suffix product, and simply return the maximum 
    of A and B.
    What if there are zeroes in the array? We can split the array into several smaller ones. That's to say, when the
    prefix product is zero, we start over and compute prefix product from the current element instead. And this is 
    exactly what A[i] *= A[i - 1] or 1 does.
*/

int maxProduct(int arr[], int n)
{
    int l = 0;
    int r = 0;
    int res = 0;

    for(int i = 0; i < n; i++)
    {
        l = (l ? l : 1) * arr[i];
        r = (r ? r : 1) * arr[n - 1 - i];
        res = max({res, l, r});
    }

    return res;
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