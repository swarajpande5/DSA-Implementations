// Program to convert decimal number to binary 
#include <bits/stdc++.h>
using namespace std;

int decimalToBinary(int n)
{
    int ans = 0, p = 1;

    while(n > 0)
    {
        int lsb = n & 1;
        ans += p * lsb;

        p = p * 10;
        n = n >> 1;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << decimalToBinary(n) << endl;
    return 0;
}