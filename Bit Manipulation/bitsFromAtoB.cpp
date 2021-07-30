// Program to calculate the number of bits that will change from a to b 
#include <bits/stdc++.h>
using namespace std;

int bitChanges(int a, int b)
{
    int n = a ^ b; 

    int setbits = 0;
    while(n > 0)
    {
        n = n & (n - 1);
        setbits++;
    }

    return setbits;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bitChanges(a, b) << endl;

    return 0;
}
