// Prime factorization: Represent n as p1^k1 * p2^k2 * p3^k3 ... pm^km 

/*
    Key points: 
        -   Only one of the prime factors of n can be greater than sqrt(n)
        -   Iterate from 2 to sqrt(n), check if current number divides n. If yes, 
            keep dividing n by that number as many times as possible.
        
        -   Invariant: Any new number that will divide N now will be a prime number.
        -   O(sqrt(n))
*/

vector<long long> primeFactorization(long long n)
{
    vector<long long> factorization; 

    for(long long d = 2; d * d <= n; d++)
    {
        while(n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }

    if(n > 1)       // Checking for the only prime factor that is greater than sqrt(n)
        factorization.push_back(n);

    return factorization;
}


// Prime Factorization using Sieve O(log n) for multiple queries 

/*

    Key Idea:   Our idea is to store the Smallest Prime Factor (SPF) for every number. 
                Then to calcualate the prime factorization of the given number by dividing
                the number recursively with its smallest prime factor till it becomes 1. 

*/

#define MAX 1000001

int spf[MAX];

void sieve(int n)
{
    // Initially marking spf for every number to be itself.
    for(int i = 1; i <= n; i++)
        spf[i] = i;

    for(int p = 2; p * p <= n; p++)
    {
        // Checking if p is a prime
        if(spf[p] == p)
        {
            // Marking spf for all numbers divisble by p (if not previously marked)
            for(int i = p * p; i <= n; i += p)
                if(spf[i] == i)
                    spf[i] = p;
        }
    }
}

// A O(log n) function returning prime factorization by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;

    while(x != 1)
    {
        res.push_back(spf[x]);
        x = x / spf[x];
    }

    return ret;
}

// A more general way of writing above function vector of pairs, where v[i] = {prime, power}

vector<pair<int, int>> getFactorization(int x)
{
    vector<pair<int, int>> ret; 

    while(x != 1)
    {
        int prime = spf[x]; 
        int power = 1; 

        while(x % prime == 0)
        {
            power++;
            x /= prime;
        }

        ret.push_back({prime, power});
    }

    return ret;
}