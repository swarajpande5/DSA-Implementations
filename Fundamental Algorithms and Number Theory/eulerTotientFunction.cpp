// Euler's Totient Function: https://cp-algorithms.com/algebra/phi-function.html

/*
    Euler's totient function, also known as phi-function, counts the number of integers between 1 and n inclusive,
    which are coprime to n. Two numbers are coprime, if their greatest common divisor equals 1 (1 is considered to be
    coprime to any number).

    Properties: 
    The following properties of Euler totient function are sufficient to calculate it for any number 
    
    (1) If p is a prime number, then gcd(p, q) = 1 for all 1 <= q < p. Therefore we have, 
        phi(p) = p - 1 
    
    (2) If p is a prime number and k >= 1, then there are exactly (p^k)/p numbers between 1 and p^k that are divisble by p.
        Which gives us, 
        phi(p^k) = (p^k) - (p^(k - 1))
    
    (3) Euler Totient function is multiplicative (https://en.wikipedia.org/wiki/Multiplicative_function)
        phi(ab) = phi(a)*phi(b)

*/

typedef long long ll;

ll phi(ll n)
{
    ll res = n; 

    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i; 
            
            res -= res / i;
        }
    }

    if(n > 1)
        res -= res / n; 

    return res;
}

