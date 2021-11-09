// Rod Cutting (Unbounded Knapsack variation) : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
#include <bits/stdc++.h>
using namespace std;

int cutRod(int length[], int price[], int n, int L)
{
    int t[n + 1][L + 1];        // DP matrix
    
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < L + 1; j++)
        {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            
            else if(length[i - 1] <= j)
            {
                int val1 = price[i - 1] + t[i][j - length[i - 1]];
                int val2 = t[i - 1][j];

                t[i][j] = max(val1, val2);
            }
            
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][L];
}

int main()
{
    int n;
    cin >> n;
    int length[n], price[n];
    for(int i = 0; i < n; i++)
        cin >> length[i];
    for(int i = 0; i < n; i++)
        cin >> price[i];
    int L; 
    cin >> L;

    cout << cutRod(length, price, n, L) << "\n";

    return 0;
}