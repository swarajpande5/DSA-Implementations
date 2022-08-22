/*  Sieve of Eratosthenes:
    https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
    https://cp-algorithms.com/algebra/prime-sieve-linear.html
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i] && (long long)i * i <= n)
        {
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    
    vector<int> primes;
    for(int i = 1; i <= n; i++)
    {
        if(isPrime[i])
            primes.push_back(i);
    }

    return primes;
}

vector<int> sieveOptimized(int n)
{
    vector<int> primes;
    vector<int> minFactorPrime(n + 1);

    for(int i = 2; i <= n; i++)
    {
        if(minFactorPrime[i] == 0)
        {
            minFactorPrime[i] = i;
            primes.push_back(i);
        }

        for(int j = 0; j < primes.size() && primes[j] <= minFactorPrime[i] && i*primes[j] <= n; j++)
            minFactorPrime[i * primes[j]] = primes[j];
    }

    return primes;
}

int main()
{
    int n;
    cin >> n;
    vector<int> primes = sieve(n);

    for(auto x: primes)
        cout << x << " ";
    cout << "\n";

    primes = sieveOptimized(n);

    for(auto x: primes)
        cout << x << " ";
    cout << "\n";

    return 0;
}
