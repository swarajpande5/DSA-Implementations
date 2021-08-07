// Modular Exponentiation 
// Computing (base^exp)%mod
#include <bits/stdc++.h>
using namespace std;

int modExp(long long base, unsigned long long exp, long long mod)
{
    int ans = 1;
    
    base = base % mod;

    if(base == 0)
        return 0;

    while(exp > 0)
    {
        int lsb = exp & 1;
        if(lsb)
            ans = (ans * base) % mod;
        
        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return ans;
}

int main()
{
    long long base, exp, mod;
    cin >> base >> exp >> mod;
    cout << modExp(base, exp, mod) << "\n";

    return 0;
}