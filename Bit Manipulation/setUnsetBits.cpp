// Setting/Unsettting i-th bit of a number 
// Note: The bit indexing is from right to left starting from 0.
#include <bits/stdc++.h>
using namespace std;

int setBit(int n, int i)
{
    int mask = 1 << i;
    int ans = n | mask;

    return ans;
}

int unsetBit(int n, int i)
{
    int mask = ~(1 << i);
    int ans = n & mask;

    return ans;
}

int main()
{
    int n, i;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter i: ";
    cin >> i;

    cout << setBit(n, i) << endl;
    cout << unsetBit(n, i) << endl;

    return 0;
}