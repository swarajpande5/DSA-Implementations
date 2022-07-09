// https://www.geeksforgeeks.org/bitwise-and-or-of-a-range/
#include <bits/stdc++.h>

int andRange(int a, int b)
{
    // This variable counts till which bit, every value will convert to zero
    int shifts = 0; 

    // Iterate through every bit of a and b simultaneously 
    // If a == b, then we know that beyond that the 'and' value remains constant.
    while(a != b && a > 0)
    {
        shifts++; 
        a = a >> 1; 
        b = b >> 1; 
    }

    return int64_t(a << shifts);
}