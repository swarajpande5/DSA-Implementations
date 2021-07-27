// Count set bits of a number
#include <bits/stdc++.h>
using namespace std;

int countBits(int n)
{
    int ans = 0;
    
    while(n > 0)
    {
        ans += n & 1;
        n = n >> 1;
    }

    return ans;
}

int countBitsFast(int n)
{
    int ans = 0;

    while(n > 0)
    {
        n = n & (n - 1);
        ans++;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << countBits(n) << endl;
    cout << countBitsFast(n) << endl;

    // STL method for the same
    cout << __builtin_popcount(n) << endl;

    return 0;
}
