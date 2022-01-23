// Palindrome Partitioning (Top Down DP): https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1/
#include <bits/stdc++.h>
using namespace std;

const int D = 1001;
static int t[D][D];

bool isPalindrome(string s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])
            return false;
        
        i++;
        j--;
    }

    return true;
}

int solve(string s, int i, int j)
{
    if(i >= j || isPalindrome(s, i, j))
    {
        t[i][j] = 0;
        return 0;
    }

    if(t[i][j] != -1)
        return t[i][j];
    
    int ans = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
        ans = min(ans, temp);
    }

    return t[i][j] = ans;
}

int solveEff(string s, int i, int j)
{
    if(i >= j || isPalindrome(s, i, j))
    {
        t[i][j] = 0;
        return 0;
    }

    if(t[i][j] != -1)
        return t[i][j];
    
    int ans = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int left, right;
        if(t[i][k] == -1)
            left = solveEff(s, i, k);
        else 
            left = t[i][k];
        
        if(t[k + 1][j] == -1)
            right = solveEff(s, k + 1, j);
        else 
            right = t[k + 1][j];
        
        int temp = 1 + left + right;
        ans = min(ans, temp);
    }

    return t[i][j] = ans;
}

int main()
{
    string s;
    cin >> s;

    memset(t, -1, sizeof(t));

    // cout << solve(s, 0, s.length() - 1) << "\n";
    cout << solveEff(s, 0, s.length() - 1) << "\n";

    return 0;
}