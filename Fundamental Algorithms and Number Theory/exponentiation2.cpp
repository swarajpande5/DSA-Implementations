/*  Given 4 integers a, b, c and m, where m is a prime number.
    Calculate (a ^ (b ^ c)) % m.

    Constraints: 
    0 <= a, b, c <= 10 ^ 9
*/

/*

    Approach: 
    
    Euler Totient Function (-w- Fermat's Little Theorem): https://cp-algorithms.com/algebra/phi-function.html
    Following approach: https://www.geeksforgeeks.org/find-power-power-mod-prime/

    According to the Fermat's little theorem,
    a ^ (m - 1) is congruent to 1 mod m, if m is a prime.

    So if we rewrite b ^ c as x * (m - 1) + y, then the task of computing 
    a ^ (b ^ c) becomes a ^ (x * (m - 1) + y) which can be rewritten as
    a ^ (x * (m - 1)) * a ^ (y). 

    From Fermat's little theorem, we know a ^ (x * m - 1) = 1.
    So task of computing a ^ (b ^ c) reduces to computing a ^ y.

    What is the value of y ? 
    from (b ^ c) = x * (m - 1) + y 
    y can be written as (b ^ c) % (m - 1).

    Hence, 
    y   = (b ^ c) % (m - 1)
    ans = (a ^ y) % m

*/

typedef long long ll 

// Modular binary exponentiation: (x ^ y) % m
ll binpowmod(ll x, ll y, ll m)
{
	ll res = 1;

	x = x % m;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % m;

		y >>= 1;
		x = (x * x) % m;
	}

	return res;
}

ll calculate(ll a, ll b, ll c, ll m)
{
	ll y, ans;

	// Calculate (b ^ c) % (m - 1)
	y = binpowmod(b, c, m - 1);

	// Calculate (a ^ y) % m
	ans = binpowmod(a, y, m);

	return ans;
}