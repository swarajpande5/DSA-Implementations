// Fast Exponentiation (or Binary Exponentiation) : https://cp-algorithms.com/algebra/binary-exp.html
// Computing base^exp
#include <bits/stdc++.h>
using namespace std;

int fastExp(int base, int exp)
{
    int ans = 1;
    
    while(exp > 0)
    {
        int lsb = exp & 1;
        if(lsb)
            ans = ans * base;
        
        base = base * base;
        exp = exp >> 1;
    }
    return ans;
}

int main()
{
    int base, exp;
    cin >> base >> exp;
    cout << fastExp(base, exp) << "\n";

    return 0;
}
