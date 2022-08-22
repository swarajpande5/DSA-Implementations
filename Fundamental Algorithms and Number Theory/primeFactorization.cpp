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

