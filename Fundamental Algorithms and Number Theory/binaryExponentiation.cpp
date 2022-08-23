// Binary exponentiation 
long long binpow(long long a, long long b)
{
    long long res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = res * a;
        
        a = a * a;
        b >>= 1;
    }

    return res;
}

// Binary modular exponentiation
long long binpowmod(long long a, long long b, long long m)
{
    a %= m;

    long long res = 1;

    while(b > 0)
    {
        if(b & 1)
            res = res * a % m;
        
        a = a * a % m;
        b >>= 1;
    }

    return res;
}