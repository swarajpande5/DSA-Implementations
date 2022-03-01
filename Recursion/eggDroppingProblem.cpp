// Egg dropping problem (recursive): https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
#include <bits/stdc++.h>
using namespace std;

int solve(int eggs, int floors)
{
    if(eggs == 1)
        return floors;
    if(floors == 0 || floors == 1)
        return floors;
    
    int mn = INT_MAX;

    for(int k = 1; k <= floors; k++)
    {
        int temp = 1 + max(solve(eggs - 1, k - 1), solve(eggs, floors - k));
        mn = min(mn, temp);
    }

    return mn;
}

int main() 
{
    int eggs, floors;
    cin >> eggs >> floors;

    cout << solve(eggs, floors) << endl;

    return 0;
}