// Minimum number of coins for coin change : https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
#include <bits/stdc++.h>
using namespace std;

int makeChange(vector<int> coins, int money)
{
    int res = 0;
    
    while(money > 0)
    {
        int idx = upper_bound(coins.begin(), coins.end(), money) - coins.begin() - 1;
        money -= coins[idx];
        res++;
    }

    return res;
}

int main()
{
    int money;
    cin >> money;

    int n;
    cin >> n;

    vector<int> coins(n);
    for(auto &x: coins)
        cin >> x;

    cout << makeChange(coins, money) << "\n";

    return 0;
}