// Euclidean Algorithm for GCD: https://cp-algorithms.com/algebra/euclid-algorithm.html
#include <bits/stdc++.h>
using namespace std;

int gcdRecursive(int a, int b)
{
    if(b == 0)
        return a;
    else 
        return gcdRecursive(b, a % b);
}

int gcdNonRecursive(int a, int b)
{
    while(b)
    {
        a = a % b;
        swap(a, b);
    }

    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcdRecursive(a, b) << "\n";
    cout << gcdNonRecursive(a, b) << "\n";
    
    return 0;
}