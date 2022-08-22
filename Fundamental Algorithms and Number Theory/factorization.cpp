// Find all factors of a number n.

/*
    Key points:
        -   Factors occur in pairs 
            n = p * q
            Without loss of generality if p < q implies p <= sqrt(n)
        -   Check for every p from 1 to sqrt(n), q = n / p;
        -   O(sqrt(n))
*/

vector<long long> findFactors(long long n)
{
    vector<long long> factors; 

    for(long long d = 1; d * d <= n; d++)
    {
        if(n % d == 0)
        {
            factors.push_back(d);
            if(n / d != d)                      // d should be different from n / d
                factors.push_back(n / d);
        }
    }

    return factors;
}