// Extended Euclidean Algorithm: https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;

        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    int x, y, a, b;
    cin >> a >> b;
    cout << gcdExtended(a, b, &x, &y) << "\n";
    cout << x << " " << y << "\n";

    return 0;
}
