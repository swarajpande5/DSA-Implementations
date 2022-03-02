// Egg dropping problem (memoization)

#include <bits/stdc++.h>
using namespace std;

const int D = 101;
int t[D][D];

int solve(int eggs, int floors)
{
    if(t[eggs][floors] != -1)
        return t[eggs][floors];
    
    if(eggs == 1 || floors == 0 || floors == 1)
    {
        t[eggs][floors] = floors;
        return floors;
    }

    int mn = INT_MAX;
    for(int k = 1; k <= floors; k++)
    {
        int temp = 1 + max(solve(eggs - 1, k - 1), solve(eggs, floors - k));
        mn = min(mn, temp);
    }

    return t[eggs][floors] = mn;
}

int main()
{
    int eggs, floors;
    cin >> eggs >> floors;

    memset(t, -1, sizeof(t));

    cout << solve(eggs, floors) << endl;

    return 0;
}